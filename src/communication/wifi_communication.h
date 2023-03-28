#ifndef WIFI_COMMUNICATION_H
#define WIFI_COMMUNICATION_H

#include <WiFi.h>

class WifiCommunication {
public:
  WifiCommunication(const char* ssid, const char* password);

  void setup();
  void connect();
  void disconnect();

private:
  const char* ssid;
  const char* password;
};

#endif // WIFI_COMMUNICATION_H
