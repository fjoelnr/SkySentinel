#include "mqtt_communication.h"

MqttCommunication::MqttCommunication(const char* mqttServer, int mqttPort, const char* mqttUsername, const char* mqttPassword)
    : mqttServer(mqttServer), mqttPort(mqttPort), mqttUsername(mqttUsername), mqttPassword(mqttPassword), client(espClient) {}

void MqttCommunication::setup() {
  client.setServer(mqttServer, mqttPort);
  client.setKeepAlive(60);
}

bool MqttCommunication::connect() {
  if (!client.connected()) {
    reconnect();
    if (client.connected()) {
      // Abonnements einrichten
      subscribeToSensorData();

      // Callback einrichten
      mqttCommPtr = this;
      client.setCallback(mqttCallback);
    }
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
    #ifdef ESP32_SAOLA
      if (client.connect("ESP32Saola", mqttUsername, mqttPassword)) {
    #endif
    #ifdef ESP32_KALUGA
      if (client.connect("ESP32Kaluga", mqttUsername, mqttPassword)) {
    #endif
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

void MqttCommunication::subscribeToSensorData() {
  if (client.connected()) {
    client.subscribe("weather_station/temperature");
    client.subscribe("weather_station/humidity");
    client.subscribe("weather_station/pressure");
  }
}

MqttCommunication* mqttCommPtr;

void mqttCallback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Callback: ");
  Serial.println((char)payload[0]);
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("]: ");
  Serial.println((char *)payload);

  payload[length] = '\0';
  String topic_str = String(topic);
  float value = atof((char*)payload);

  mqttCommPtr->updateSensorData(topic_str, value);
}


void MqttCommunication::readSensorData(float &temperature, float &humidity, float &pressure) {
  if (!client.connected()) {
    reconnect();
  }
  temperature = this->temperature;
  humidity = this->humidity;
  pressure = this->pressure;
}

void MqttCommunication::updateSensorData(String topic_str, float value) {
  if (topic_str == "weather_station/temperature") {
    temperature = value;
  } else if (topic_str == "weather_station/humidity") {
    humidity = value;
  } else if (topic_str == "weather_station/pressure") {
    pressure = value;
  }
}

void MqttCommunication::processCallbacks() {
  client.loop();
}