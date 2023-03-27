#include "wifi_communication.h"

WifiCommunication::WifiCommunication() {
}

bool WifiCommunication::connect() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  unsigned long startTime = millis();
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    if (millis() - startTime > 30000) { // Timeout after 30 seconds
      return false;
    }
  }
  return true;
}

bool WifiCommunication::isConnected() {
  return WiFi.status() == WL_CONNECTED;
}

WiFiClient& WifiCommunication::getClient() {
  return _client;
}
