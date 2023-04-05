/**
 * @file wifi_communication.h
 * @author fjoelnr
 * @date 2023-04-04
 * @brief This file contains the definition of the WifiCommunication class for managing Wi-Fi connectivity.
 */

#ifndef WIFI_COMMUNICATION_H
#define WIFI_COMMUNICATION_H

#include <WiFi.h>

class WifiCommunication {
public:
  /**
   * @brief Construct a new WifiCommunication object.
   * @param ssid The Wi-Fi SSID.
   * @param password The Wi-Fi password.
   */
  WifiCommunication(const char* ssid, const char* password);

  /**
   * @brief Set up the Wi-Fi module.
   */
  void setup();

  /**
   * @brief Connect to the Wi-Fi network.
   */
  void connect();

  /**
   * @brief Disconnect from the Wi-Fi network.
   */
  void disconnect();

private:
  const char* ssid;
  const char* password;
};

#endif // WIFI_COMMUNICATION_H
