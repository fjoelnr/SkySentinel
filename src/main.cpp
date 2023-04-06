/**
 * @file main.cpp
 * @author fjoelnr
 * @date 2023-03-22
 * 
 * @brief Main program file for the weather station project.
 * 
 * This file contains the main program loop and setup functions for the
 * weather station project, which integrates BME280 sensor data, display,
 * Wi-Fi, and MQTT communication.
 */

#include <Arduino.h>
#include "sensors/bme280_communication.h"
#include "visualization/display_communication.h"
#include "network/wifi_communication.h"
#include "network/mqtt_communication.h"
#include "data_processing/data_processing.h"
#include "credentials.h"
#include "esp_sleep.h"

// Display pins configuration
#define TFT_CLK 15
#define TFT_MISO 8
#define TFT_MOSI 9
#define TFT_CS 11
#define TFT_DC 13
#define TFT_RST 16
#define TFT_BL 6

// Sensor and communication objects
BME280Communication bme;
DisplayCommunication display(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST);
WifiCommunication wifi(WIFI_SSID, WIFI_PASSWORD);
MqttCommunication mqtt(MQTT_SERVER, MQTT_PORT, MQTT_USERNAME, MQTT_PASSWORD);

// Variables to store sensor data
float temperature, humidity, pressure;

// Time between measurements and data transfers in seconds
const int sleepTimeInSeconds = 60;

/**
 * @brief Puts the ESP32 into deep sleep mode for a specified time.
 * @param sleepTimeInMicroseconds Time to sleep in microseconds.
 */
void goToDeepSleep(uint64_t sleepTimeInMicroseconds) {
  esp_sleep_enable_timer_wakeup(sleepTimeInMicroseconds);
  esp_deep_sleep_start();
}

/**
 * @brief Initializes the system.
 */
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
    mqtt.connect(); // Subscriptions are now set up in the connect() method
  #endif
}

/**
 * @brief Main program loop.
 */
void loop() {
  
  #ifdef ESP32_SAOLA
    if (mqtt.connect()) {
      bme.readSensorData(temperature, humidity, pressure);
      processSensorData(millis(), temperature, humidity, pressure);
      mqtt.publishSensorData(temperature, humidity, pressure);

      Serial.print("MQTT publish: BME280 Temperature: ");
      Serial.println(temperature);
      Serial.print("MQTT publish: BME280 Humidity: ");
      Serial.println(humidity);
      Serial.print("MQTT publish: BME280 Pressure: ");
      Serial.println(pressure);
    
      // disconnect from MQTT server
      mqtt.disconnect();
    }

    // Go to Deep Sleep Mode and wait for the defined time
    goToDeepSleep(sleepTimeInSeconds * 1000000);

  #endif

  #ifdef ESP32_KALUGA
    if (mqtt.connect()) { // Ensure connected to MQTT server
      mqtt.processCallbacks(); // Call MQTT client to trigger callback and update sensor values

       // Get sensor values from mqtt_communication class
      mqtt.readSensorData(temperature, humidity, pressure);

      Serial.print("MQTT subscribe: BME280 Temperature: ");
      Serial.println(temperature);
      Serial.print("MQTT subscribe: BME280 Humidity: ");
      Serial.println(humidity);
      Serial.print("MQTT subscribe: BME280 Pressure: ");
      Serial.println(pressure);

      display.showWeatherData(temperature, humidity, pressure);
    }

    delay(sleepTimeInSeconds *100);

  #endif
}