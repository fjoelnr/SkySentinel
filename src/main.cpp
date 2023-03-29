#include <Arduino.h>
#include "sensors/bme280_sensor.h"
#include "communication/wifi_communication.h"
#include "communication/mqtt_communication.h"
#include "visualization/display_communication.h"
#include "credentials.h"
#include "esp_sleep.h"


BME280_Sensor bmeSensor;
WifiCommunication wifi(WIFI_SSID, WIFI_PASSWORD);
MqttCommunication mqtt(MQTT_SERVER, MQTT_PORT, MQTT_USERNAME, MQTT_PASSWORD);

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

  #if defined(ESP32_KALUGA)
    setupDisplay();
  #endif

  // Initialize BME280 sensor
  if (!bmeSensor.begin()) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  } else {
    Serial.println("Sensor BME280 succesful initialized");
  }

  // Setup Wi-Fi
  Serial.println("Setup Wi-Fi...");
  wifi.setup();

  // Setup MQTT server
  Serial.println("Setup MQTT server...");
  mqtt.setup();
}

void loop() {
  // connect to Wi-Fi
  wifi.connect();

  // connect to MQTT-server
  if (mqtt.connect()) {
    // Read sensor data
    float temperature = bmeSensor.readTemperature();
    float humidity = bmeSensor.readHumidity();
    float pressure = bmeSensor.readPressure();

    #if defined(ESP32_KALUGA)
      displayData(temperature, humidity, pressure);
    #endif

    // Send sensor data to MQTT server
    mqtt.publishTemperature(temperature);
    mqtt.publishHumidity(humidity);
    mqtt.publishPressure(pressure);

    // disconnect from MQTT server
    mqtt.disconnect();
  }

  // disconnect from WiFi
  wifi.disconnect();
  
  // Go to Deep Sleep Mode and wait for the defined time
  goToDeepSleep(sleepTimeInSeconds * 1000000);
}
