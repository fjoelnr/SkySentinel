#include "mqtt_communication.h"

/**
 * @brief Constructor for the MqttCommunication class.
 * @param mqttServer The MQTT server address.
 * @param mqttPort The MQTT server port.
 * @param mqttUsername The MQTT username.
 * @param mqttPassword The MQTT password.
 */
MqttCommunication::MqttCommunication(const char* mqttServer, int mqttPort, const char* mqttUsername, const char* mqttPassword)
    : mqttServer(mqttServer), mqttPort(mqttPort), mqttUsername(mqttUsername), mqttPassword(mqttPassword), client(espClient) {}

/**
 * @brief Sets up the MQTT client.
 */
void MqttCommunication::setup() {
  client.setServer(mqttServer, mqttPort);
  client.setKeepAlive(60);
}

/**
 * @brief Connects to the MQTT server and sets up subscriptions and callbacks.
 * @return True if the client is connected to the MQTT server, otherwise false.
 */
bool MqttCommunication::connect() {
  if (!client.connected()) {
    reconnect();
    if (client.connected()) {
      // Abonnements einrichten
      subscribeToSensorData();

      // Callback einrichten
      mqttCommPtr = this;
      client.setCallback(mqttCallback);
    }
  }
  return client.connected();
}

/**
 * @brief Disconnects from the MQTT server.
 */
void MqttCommunication::disconnect() {
  if (client.connected()) {
    client.disconnect();
  }
}

/**
 * @brief Publishes sensor data to their respective topics.
 * @param temperature The temperature value to be published.
 * @param humidity The humidity value to be published.
 * @param pressure The pressure value to be published.
 */
void MqttCommunication::publishSensorData(float temperature, float humidity, float pressure) {
  publishTemperature(temperature);
  publishHumidity(humidity);
  publishPressure(pressure);
}

/**
 * @brief Publishes the temperature value to the corresponding topic.
 * @param temperature The temperature value to be published.
 */
void MqttCommunication::publishTemperature(float temperature) {
  publish("weather_station/temperature", temperature);
}

/**
 * @brief Publishes the humidity value to the corresponding topic.
 * @param humidity The humidity value to be published.
 */
void MqttCommunication::publishHumidity(float humidity) {
  publish("weather_station/humidity", humidity);
}

/**
 * @brief Publishes the pressure value to the corresponding topic.
 * @param pressure The pressure value to be published.
 */
void MqttCommunication::publishPressure(float pressure) {
  publish("weather_station/pressure", pressure);
}

/**
 * @brief Reconnects to the MQTT server if the connection is lost.
 */
void MqttCommunication::reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    #ifdef ESP32_SAOLA
      if (client.connect("ESP32Saola", mqttUsername, mqttPassword)) {
    #endif
    #ifdef ESP32_KALUGA
      if (client.connect("ESP32Kaluga", mqttUsername, mqttPassword)) {
    #endif
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

/**
 * @brief Publishes a float value to the specified topic.
 * @param topic The topic on which the value should be published.
 * @param value The float value to be published.
 */
void MqttCommunication::publish(const char* topic, float value) {
  char payload[10];
  snprintf(payload, sizeof(payload), "%.2f", value);
  client.publish(topic, payload);
}

/**
 * @brief Subscribes to sensor data topics.
 */
void MqttCommunication::subscribeToSensorData() {
  if (client.connected()) {
    client.subscribe("weather_station/temperature");
    client.subscribe("weather_station/humidity");
    client.subscribe("weather_station/pressure");
  }
}

MqttCommunication* mqttCommPtr;

/**
 * @brief MQTT callback function for handling incoming messages.
 * @param topic The topic on which the message was received.
 * @param payload The payload of the received message.
 * @param length The length of the received payload.
 */
void mqttCallback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Callback: ");
  Serial.println((char)payload[0]);
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("]: ");
  Serial.println((char *)payload);

  payload[length] = '\0';
  String topic_str = String(topic);
  float value = atof((char*)payload);

  mqttCommPtr->updateSensorData(topic_str, value);
}


/**
 * @brief Reads the latest sensor data.
 * @param temperature Reference to store the latest temperature value.
 * @param humidity Reference to store the latest humidity value.
 * @param pressure Reference to store the latest pressure value.
 */
void MqttCommunication::readSensorData(float &temperature, float &humidity, float &pressure) {
  if (!client.connected()) {
    reconnect();
  }
  temperature = this->temperature;
  humidity = this->humidity;
  pressure = this->pressure;
}

/**
 * @brief Updates the stored sensor data based on the received topic and value.
 * @param topic_str The topic on which the data was received.
 * @param value The new sensor value.
 */
void MqttCommunication::updateSensorData(String topic_str, float value) {
  if (topic_str == "weather_station/temperature") {
    temperature = value;
  } else if (topic_str == "weather_station/humidity") {
    humidity = value;
  } else if (topic_str == "weather_station/pressure") {
    pressure = value;
  }
}

/**

    @brief Processes MQTT callbacks by calling the PubSubClient loop function.
    */
    void MqttCommunication::processCallbacks() {
  client.loop();
}