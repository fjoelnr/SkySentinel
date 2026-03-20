/**
 * @file wifi_communication.cpp
 * @author fjoelnr
 * @date 2023-04-04
 * @brief This file contains the implementation of the WifiCommunication class for managing Wi-Fi connectivity.
 */

#include "wifi_communication.h"

/**
 * @brief Construct a new WifiCommunication object.
 * @param ssid The Wi-Fi SSID.
 * @param password The Wi-Fi password.
 */
WifiCommunication::WifiCommunication(const char* ssid, const char* password, const char* hostname)
    : ssid(ssid), password(password), hostname(hostname) {}

/**
 * @brief Set up the Wi-Fi module.
 */
void WifiCommunication::setup() {
  WiFi.mode(WIFI_STA);
  WiFi.setAutoReconnect(true);
  WiFi.persistent(false);
  if (hostname && hostname[0] != '\0') {
    WiFi.setHostname(hostname);
  }
}

/**
 * @brief Connect to the Wi-Fi network.
 */
bool WifiCommunication::connect(uint32_t timeoutMs) {
  if (WiFi.status() == WL_CONNECTED) {
    return true;
  }

  Serial.print("Connecting to " + String(ssid) + " ");
  // Ensure fresh DHCP request and hostname before connecting
  WiFi.disconnect(true, true);
  delay(100);
  if (hostname && hostname[0] != '\0') {
    WiFi.setHostname(hostname);
  }
  WiFi.begin(ssid, password);
  unsigned long startAttemptTime = millis();

  while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < timeoutMs) {
    delay(500);
    Serial.print(".");
  }

  if (WiFi.status() != WL_CONNECTED) {
    Serial.printf("Connection Failed! status=%d. Will retry later.\n", WiFi.status());
    return false;
  }

  Serial.println();
  Serial.println("WiFi connected with IP address: " + WiFi.localIP().toString());
  return true;
}

/**
 * @brief Disconnect from the Wi-Fi network.
 */
void WifiCommunication::disconnect() {
  if (WiFi.status() == WL_CONNECTED) {
    WiFi.disconnect();
    Serial.println("Disconnected from WiFi");
  }
}

bool WifiCommunication::isConnected() const {
  return WiFi.status() == WL_CONNECTED;
}
