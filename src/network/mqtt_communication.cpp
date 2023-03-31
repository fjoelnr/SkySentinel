#include "mqtt_communication.h"

MqttCommunication::MqttCommunication(const char* mqttServer, int mqttPort, const char* mqttUsername, const char* mqttPassword)
    : mqttServer(mqttServer), mqttPort(mqttPort), mqttUsername(mqttUsername), mqttPassword(mqttPassword), client(espClient) {}

void MqttCommunication::setup() {
  client.setServer(mqttServer, mqttPort);
}

bool MqttCommunication::connect() {
  if (!client.connected()) {
    reconnect();
  }
  return client.connected();
}

void MqttCommunication::disconnect() {
  if (client.connected()) {
    client.disconnect();
  }
}

void MqttCommunication::publishSensorData(float temperature, float humidity, float pressure) {
  publishTemperature(temperature);
  publishHumidity(humidity);
  publishPressure(pressure);
}

void MqttCommunication::publishTemperature(float temperature) {
  publish("weather_station/temperature", temperature);
}

void MqttCommunication::publishHumidity(float humidity) {
  publish("weather_station/humidity", humidity);
}

void MqttCommunication::publishPressure(float pressure) {
  publish("weather_station/pressure", pressure);
}

void MqttCommunication::reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP32Kaluga", mqttUsername, mqttPassword)) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void MqttCommunication::publish(const char* topic, float value) {
  char payload[10];
  snprintf(payload, sizeof(payload), "%.2f", value);
  client.publish(topic, payload);
}

void MqttCommunication::readSensorData(float &temperature, float &humidity, float &pressure) {
  if (!client.connected()) {
    // reconnect();
  }
  
  client.subscribe("weather_station/temperature");
  client.subscribe("weather_station/humidity");
  client.subscribe("weather_station/pressure");

  client.setCallback([&](char* topic, byte* payload, unsigned int length) {
    payload[length] = '\0';
    String topic_str = String(topic);
    float value = atof((char*)payload);

    if (topic_str == "weather_station/temperature") {
      temperature = value;
    } else if (topic_str == "weather_station/humidity") {
      humidity = value;
    } else if (topic_str == "weather_station/pressure") {
      pressure = value;
    }
  });

  client.loop();
}
