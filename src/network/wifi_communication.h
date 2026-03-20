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
   * @param hostname Optional Wi-Fi hostname (for DHCP).
   */
  WifiCommunication(const char* ssid, const char* password, const char* hostname = nullptr);

  /**
   * @brief Set up the Wi-Fi module.
   */
  void setup();

  /**
   * @brief Connect to the Wi-Fi network.
   */
  bool connect(uint32_t timeoutMs = 10000);

  /**
   * @brief Check if the Wi-Fi is connected.
   */
  bool isConnected() const;

  /**
   * @brief Disconnect from the Wi-Fi network.
   */
  void disconnect();

private:
  const char* ssid;
  const char* password;
  const char* hostname;
};

#endif // WIFI_COMMUNICATION_H
