#ifndef MQTT_COMMUNICATION_H
#define MQTT_COMMUNICATION_H

#include <WiFi.h>
#include <PubSubClient.h>

class MqttCommunication {
public:
  MqttCommunication(const char* mqttServer, int mqttPort, const char* mqttUsername, const char* mqttPassword);

  void setup();
  bool connect();
  void disconnect();
  void publishSensorData(float temperature, float humidity, float pressure);
  void publishTemperature(float temperature);
  void publishHumidity(float humidity);
  void publishPressure(float pressure);
  void readSensorData(float &temperature, float &humidity, float &pressure);

private:
  const char* mqttServer;
  int mqttPort;
  const char* mqttUsername;
  const char* mqttPassword;
  WiFiClient espClient;
  PubSubClient client;

  void reconnect();
  void publish(const char* topic, float value);
};

#endif // MQTT_COMMUNICATION_H
