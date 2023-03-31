#include "wifi_communication.h"

WifiCommunication::WifiCommunication(const char* ssid, const char* password)
    : ssid(ssid), password(password) {}

void WifiCommunication::setup() {
  WiFi.mode(WIFI_STA);
}

void WifiCommunication::connect() {
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
    Serial.println("");
    Serial.println("Connected to WiFi");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }
}

void WifiCommunication::disconnect() {
  if (WiFi.status() == WL_CONNECTED) {
    WiFi.disconnect();
    Serial.println("Disconnected from WiFi");
  }
}
