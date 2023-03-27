#ifndef WIFI_COMMUNICATION_H
#define WIFI_COMMUNICATION_H

#include <Arduino.h>
#include <WiFi.h>
#include "credentials.h"

class WifiCommunication {
public:
  WifiCommunication();
  bool connect();
  bool isConnected();
  WiFiClient& getClient();

private:
  WiFiClient _client;
};

#endif // WIFI_COMMUNICATION_H
