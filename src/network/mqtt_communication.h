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
  void subscribeToSensorData();
  void readSensorData(float &temperature, float &humidity, float &pressure);
  void updateSensorData(String topic_str, float value);
  void processCallbacks();

private:
  const char* mqttServer;
  int mqttPort;
  const char* mqttUsername;
  const char* mqttPassword;
  WiFiClient espClient;
  PubSubClient client;  
  float temperature;
  float humidity;
  float pressure;


  void reconnect();
  void publish(const char* topic, float value);
};

extern MqttCommunication* mqttCommPtr;
void mqttCallback(char* topic, byte* payload, unsigned int length);

#endif // MQTT_COMMUNICATION_H
