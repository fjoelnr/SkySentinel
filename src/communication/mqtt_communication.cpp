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
    if (client.connect("ESP32Client", mqttUsername, mqttPassword)) {
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
