#include <Arduino.h>
#include "sensors/bme280_communication.h"
#include "visualization/display_communication.h"
#include "network/wifi_communication.h"
#include "network/mqtt_communication.h"
#include "credentials.h"
#include "esp_sleep.h"

#define TFT_CLK 15
#define TFT_MISO 8
#define TFT_MOSI 9
#define TFT_CS 11
#define TFT_DC 13
#define TFT_RST 16
#define TFT_BL 6

BME280Communication bme;
DisplayCommunication display(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST);
WifiCommunication wifi(WIFI_SSID, WIFI_PASSWORD);
MqttCommunication mqtt(MQTT_SERVER, MQTT_PORT, MQTT_USERNAME, MQTT_PASSWORD);

float temperature, humidity, pressure;

// Zeit zwischen den Messungen und Datenübertragungen in Sekunden
const int sleepTimeInSeconds = 60;

void goToDeepSleep(uint64_t sleepTimeInMicroseconds) {
  esp_sleep_enable_timer_wakeup(sleepTimeInMicroseconds);
  esp_deep_sleep_start();
}

void setup() {
  Serial.begin(115200);
  Serial.println("Booting...");
  delay(1000);

  #ifdef ESP32_SAOLA
    bme.begin();
  #endif

  // Setup Wi-Fi
  Serial.print("Setup Wi-Fi...");
  wifi.setup();
  wifi.connect();
  Serial.println(" done! ");
  
  // Setup MQTT server
  Serial.print("Setup MQTT server...");
  mqtt.setup();
  Serial.println(" done! ");

  #ifdef ESP32_KALUGA
    display.begin();
  #endif

}

void loop() {
  
  #ifdef ESP32_SAOLA
    if (mqtt.connect()) {
      bme.readSensorData(temperature, humidity, pressure);

      mqtt.publishSensorData(temperature, humidity, pressure);
    
      // disconnect from MQTT server
      mqtt.disconnect();
    }

    // Go to Deep Sleep Mode and wait for the defined time
    goToDeepSleep(sleepTimeInSeconds * 1000000);

  #endif

  #ifdef ESP32_KALUGA
    mqtt.connect(); // Stelle sicher, dass Du mit dem MQTT-Server verbunden bist
    mqtt.readSensorData(temperature, humidity, pressure);
    display.showWeatherData(temperature, humidity, pressure);

    delay(10000);

  #endif

}