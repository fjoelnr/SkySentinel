#include <Arduino.h>
#include "sensors/bme280_sensor.h"
#include "communication/wifi_communication.h"
#include "communication/mqtt_communication.h"

BME280_Sensor bmeSensor;
WifiCommunication wifiComm;
MqttCommunication mqttComm(wifiComm);

void setup() {
  Serial.begin(115200);

  // Initialize BME280 sensor
  if (!bmeSensor.begin()) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }

  // Connect to Wi-Fi
  Serial.println("Connecting to Wi-Fi...");
  if (wifiComm.connect()) {
    Serial.println("Connected to Wi-Fi!");
  } else {
    Serial.println("Failed to connect to Wi-Fi.");
    while (1);
  }

  // Connect to MQTT server
  Serial.println("Connecting to MQTT server...");
  if (mqttComm.connect()) {
    Serial.println("Connected to MQTT server!");
  } else {
    Serial.println("Failed to connect to MQTT server.");
    while (1);
  }
}

void loop() {
  // Read sensor data
  float temperature = bmeSensor.readTemperature();
  float humidity = bmeSensor.readHumidity();
  float pressure = bmeSensor.readPressure();


  // Send sensor data to MQTT server
  String temperatureTopic = "sensors/bme280/temperature";
  String humidityTopic = "sensors/bme280/humidity";
  String pressureTopic = "sensors/bme280/pressure";

  mqttComm.sendData(temperatureTopic, String(temperature));
  mqttComm.sendData(humidityTopic, String(humidity));
  mqttComm.sendData(pressureTopic, String(pressure));

  // Wait for 1 minute before sending data again
  delay(60000);
}
