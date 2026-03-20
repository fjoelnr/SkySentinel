#include <Arduino.h>
#include <ArduinoOTA.h>
#include "sensors/bme280_communication.h"
#include "visualization/display_communication.h"
#include "network/wifi_communication.h"
#include "network/mqtt_communication.h"
#include "data_processing/data_processing.h"
#include "credentials.h"
#include "esp_sleep.h"

// Display pins configuration are now in platformio.ini

// Sensor and communication objects
BME280Communication bme;
DisplayCommunication display(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST);
WifiCommunication wifi(WIFI_SSID, WIFI_PASSWORD, WIFI_HOSTNAME);
MqttCommunication mqtt(MQTT_SERVER, MQTT_PORT, MQTT_USERNAME, MQTT_PASSWORD);

// Variables to store sensor data
float temperature, humidity, pressure;

// Time between measurements and data transfers in seconds
// Time between measurements and data transfers in seconds
const int sleepTimeInSeconds = 60;
unsigned long lastMeasurementTime = 0;

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
    if (!bme.begin()) {
      Serial.println("BME280 initialization failed. Rebooting...");
      delay(5000);
      ESP.restart();
    }
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

  // OTA Setup
  ArduinoOTA.setHostname(WIFI_HOSTNAME);
  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH) {
      type = "sketch";
    } else { // U_SPIFFS
      type = "filesystem";
    }
    Serial.println("Start updating " + type);
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) {
      Serial.println("Auth Failed");
    } else if (error == OTA_BEGIN_ERROR) {
      Serial.println("Begin Failed");
    } else if (error == OTA_CONNECT_ERROR) {
      Serial.println("Connect Failed");
    } else if (error == OTA_RECEIVE_ERROR) {
      Serial.println("Receive Failed");
    } else if (error == OTA_END_ERROR) {
      Serial.println("End Failed");
    }
  });
  ArduinoOTA.begin();

  #ifdef ESP32_KALUGA
    display.begin();
    mqtt.connect(); // Subscriptions are now set up in the connect() method
  #endif
}

/**
 * @brief Main program loop.
 */
void loop() {
  // Keep Wi-Fi alive; reconnect if dropped
  if (!wifi.connect()) {
    delay(500);
    return;
  }

  ArduinoOTA.handle();
  mqtt.processCallbacks();

  unsigned long currentMillis = millis();

  #ifdef ESP32_SAOLA
    if (currentMillis - lastMeasurementTime >= sleepTimeInSeconds * 1000) {
      lastMeasurementTime = currentMillis;
      
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
    }
    
    if (mqtt.isOtaUpdateRequested()) {
       // If OTA update is requested, we don't sleep (which we aren't doing here anyway in this non-blocking loop)
       // But we might want to prevent other heavy tasks? For now, just logging.
       static unsigned long lastOtaLog = 0;
       if (currentMillis - lastOtaLog > 5000) {
         Serial.println("OTA Update in progress, staying awake.");
         lastOtaLog = currentMillis;
       }
    }
  #endif

  #ifdef ESP32_KALUGA
    if (mqtt.connect()) { // Ensure connected to MQTT server
      // Get sensor values from mqtt_communication class
      mqtt.readSensorData(temperature, humidity, pressure);

      // Update display only periodically to avoid flickering or excessive processing
      if (currentMillis - lastMeasurementTime >= sleepTimeInSeconds * 1000) {
         lastMeasurementTime = currentMillis;
         
         Serial.print("MQTT subscribe: BME280 Temperature: ");
         Serial.println(temperature);
         Serial.print("MQTT subscribe: BME280 Humidity: ");
         Serial.println(humidity);
         Serial.print("MQTT subscribe: BME280 Pressure: ");
         Serial.println(pressure);

         display.showWeatherData(temperature, humidity, pressure);
      }
    }
  #endif
}
