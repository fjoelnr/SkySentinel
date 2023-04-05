/**
 * @file credentials_template.h
 * @author fjoelnr
 * @date 2023-04-04
 * @brief This file contains the Wi-Fi and MQTT credentials.
 */

#ifndef CREDENTIALS_H
#define CREDENTIALS_H

// Wi-Fi Credentials
// Replace with your actual Wi-Fi credentials

/**
 * @brief The Wi-Fi SSID to connect to.
 */
#define WIFI_SSID "your_wifi_ssid"

/**
 * @brief The Wi-Fi password for the specified SSID.
 */
#define WIFI_PASSWORD "your_wifi_password"

// MQTT Credentials
// Replace with your actual MQTT credentials

/**
 * @brief The MQTT server address.
 */
#define MQTT_SERVER "your_mqtt_server"

/**
 * @brief The MQTT server port.
 * @note Change if your MQTT server uses a different port.
 */
#define MQTT_PORT 1883

/**
 * @brief The MQTT username for authentication.
 */
#define MQTT_USERNAME "your_mqtt_user"

/**
 * @brief The MQTT password for the specified username.
 */
#define MQTT_PASSWORD "your_mqtt_password"

#endif // CREDENTIALS_H
