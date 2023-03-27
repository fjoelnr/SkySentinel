#ifndef MQTT_COMMUNICATION_H
#define MQTT_COMMUNICATION_H

#include <Arduino.h>
#include <PubSubClient.h>
#include "wifi_communication.h"
#include "credentials.h"

class MqttCommunication {
public:
  MqttCommunication(WifiCommunication& wifiComm);
  bool connect();
  bool isConnected();
  bool sendData(const String& topic, const String& data);

private:
  WifiCommunication& _wifiComm;
  PubSubClient _client;
};

#endif // MQTT_COMMUNICATION_H
