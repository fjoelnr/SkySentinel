/**
 * @file mqtt_communication.h
 * @author fjoelnr
 * @date 2023-03-21
 * @brief Header file containing the MqttCommunication class definition for managing MQTT connectivity and operations.
 */

#ifndef MQTT_COMMUNICATION_H
#define MQTT_COMMUNICATION_H

#include <WiFi.h>
#include <PubSubClient.h>

/**
 * @class MqttCommunication
 * @brief The MqttCommunication class provides methods for connecting to the MQTT broker, subscribing to topics, and publishing data.
 */
class MqttCommunication {
public:
  /**
   * @brief Construct a new MqttCommunication object.
   * @param mqttServer The MQTT server address.
   * @param mqttPort The MQTT server port.
   * @param mqttUsername The MQTT username for authentication.
   * @param mqttPassword The MQTT password for authentication.
   */
  MqttCommunication(const char* mqttServer, int mqttPort, const char* mqttUsername, const char* mqttPassword);

  /**
   * @brief Set up the MQTT client with server and port information.
   */
  void setup();

  /**
   * @brief Connect to the MQTT broker, if not already connected.
   * @return true if connected, false otherwise.
   */
  bool connect();

  /**
   * @brief Disconnect from the MQTT broker, if connected.
   */
  void disconnect();

  /**
   * @brief Publish sensor data for temperature, humidity, and pressure.
   * @param temperature The temperature value to publish.
   * @param humidity The humidity value to publish.
   * @param pressure The pressure value to publish.
   */
  void publishSensorData(float temperature, float humidity, float pressure);

  /**
   * @brief Publish temperature data.
   * @param temperature The temperature value to publish.
   */
  void publishTemperature(float temperature);

  /**
   * @brief Publish humidity data.
   * @param humidity The humidity value to publish.
   */
  void publishHumidity(float humidity);

  /**
   * @brief Publish pressure data.
   * @param pressure The pressure value to publish.
   */
  void publishPressure(float pressure);

  /**
   * @brief Subscribe to sensor data topics.
   */
  void subscribeToSensorData();

  /**
   * @brief Read the current sensor data for temperature, humidity, and pressure.
   * @param temperature Reference to a float to store the temperature value.
   * @param humidity Reference to a float to store the humidity value.
   * @param pressure Reference to a float to store the pressure value.
   */
  void readSensorData(float &temperature, float &humidity, float &pressure);

  /**
   * @brief Update the sensor data based on the received MQTT message.
   * @param topic_str The MQTT topic string.
   * @param value The value received from the MQTT message.
   */
  void updateSensorData(String topic_str, float value);

  /**
   * @brief Process MQTT callbacks.
   */
  void processCallbacks();

private:
  const char* mqttServer;
  int mqttPort;
  const char* mqttUsername;
  const char* mqttPassword;
  WiFiClient espClient;
  PubSubClient client;  
  float temperature;
  float humidity;
  float pressure;

  /**
   * @brief Reconnect to the MQTT broker if disconnected.
   */
  void reconnect();

  /**
   * @brief Publish a float value to a specific MQTT topic.
   * @param topic The MQTT topic to publish to.
   * @param value The float value to publish.
   */
  void publish(const char* topic, float value);
};

/**
 * @brief Pointer to an instance of MqttCommunication class.
 */
extern MqttCommunication* mqttCommPtr;

/**
 * @brief MQTT callback function for handling incoming messages.
 * @param topic The topic on which the message was received.
 * @param payload The payload of the received message.
 * @param length The length of the received payload.
 */
void mqttCallback(char* topic, byte* payload, unsigned int length);

#endif // MQTT_COMMUNICATION_H
