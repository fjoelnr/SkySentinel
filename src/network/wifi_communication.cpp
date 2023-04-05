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
WifiCommunication::WifiCommunication(const char* ssid, const char* password)
    : ssid(ssid), password(password) {}

/**
 * @brief Set up the Wi-Fi module.
 */
void WifiCommunication::setup() {
  WiFi.mode(WIFI_STA);
}

/**
 * @brief Connect to the Wi-Fi network.
 */
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

/**
 * @brief Disconnect from the Wi-Fi network.
 */
void WifiCommunication::disconnect() {
  if (WiFi.status() == WL_CONNECTED) {
    WiFi.disconnect();
    Serial.println("Disconnected from WiFi");
  }
}
