#include "wifi_communication.h"

WifiCommunication::WifiCommunication(const char* ssid, const char* password)
    : ssid(ssid), password(password) {}

void WifiCommunication::setup() {
  WiFi.mode(WIFI_STA);
}

void WifiCommunication::connect() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.print("Connecting to " + String(ssid) + " ");
    WiFi.begin(ssid, password);
    while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }
    Serial.println("");
    Serial.println("WiFi connected with IP address: " + WiFi.localIP().toString());
  }
}

void WifiCommunication::disconnect() {
  if (WiFi.status() == WL_CONNECTED) {
    WiFi.disconnect();
    Serial.println("Disconnected from WiFi");
  }
}