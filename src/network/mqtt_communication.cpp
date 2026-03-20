#include "mqtt_communication.h"
#include "weather_topics.h"
#include <ArduinoJson.h>

MqttCommunication::MqttCommunication(const char* mqttServer, int mqttPort, const char* mqttUsername, const char* mqttPassword)
    : mqttServer(mqttServer), mqttPort(mqttPort), mqttUsername(mqttUsername), mqttPassword(mqttPassword), client(espClient), otaUpdateRequested(false) {}

void MqttCommunication::setup() {
  client.setServer(mqttServer, mqttPort);
  client.setKeepAlive(60);
  client.setBufferSize(1024);
}

bool MqttCommunication::connect() {
  if (!client.connected()) {
    reconnect();
    if (client.connected()) {
      subscribeToSensorData();
      subscribeToOTAControl();
      mqttCommPtr = this;
      client.setCallback(mqttCallback);
      if (!discoveryPublished) {
        publishDiscoveryConfig();
      }
    }
  }
  return client.connected();
}

void MqttCommunication::disconnect() {
  if (client.connected()) {
    client.disconnect();
  }
}

void MqttCommunication::publishSensorData(float temperature, float humidity, float pressure) {
  publishTemperature(temperature);
  publishHumidity(humidity);
  publishPressure(pressure);
}

void MqttCommunication::publishTemperature(float temperature) {
  publish(WEATHER_OUTDOOR_TEMPERATURE_TOPIC, temperature);
}

void MqttCommunication::publishHumidity(float humidity) {
  publish(WEATHER_OUTDOOR_HUMIDITY_TOPIC, humidity);
}

void MqttCommunication::publishPressure(float pressure) {
  publish(WEATHER_OUTDOOR_PRESSURE_TOPIC, pressure);
}

void MqttCommunication::reconnect() {
  if (client.connected()) {
    return;
  }

  unsigned long now = millis();
  // Nur alle 5 Sekunden einen neuen Verbindungsversuch starten
  if (now - lastReconnectAttempt < 5000) {
    return;
  }
  lastReconnectAttempt = now;

  Serial.print("Attempting MQTT connection...");
  if (client.connect("ESP32Client", mqttUsername, mqttPassword)) {
    Serial.println("connected");
  } else {
    Serial.print("failed, rc=");
    Serial.print(client.state());
    Serial.println(" try again in 5 seconds");
  }
}

void MqttCommunication::publish(const char* topic, float value) {
  char payload[10];
  snprintf(payload, sizeof(payload), "%.2f", value);
  client.publish(topic, payload);
}

void MqttCommunication::subscribeToSensorData() {
  if (client.connected()) {
    client.subscribe(WEATHER_OUTDOOR_TEMPERATURE_TOPIC);
    client.subscribe(WEATHER_OUTDOOR_HUMIDITY_TOPIC);
    client.subscribe(WEATHER_OUTDOOR_PRESSURE_TOPIC);
  }
}

void MqttCommunication::subscribeToOTAControl() {
  if (client.connected()) {
    client.subscribe(WEATHER_OUTDOOR_OTA_TOPIC);
    Serial.println("Subscribed to weather/outdoor/ota");
  }
}

void MqttCommunication::readSensorData(float &temperature, float &humidity, float &pressure) {
  if (!client.connected()) {
    reconnect();
  }
  temperature = this->temperature;
  humidity = this->humidity;
  pressure = this->pressure;
}

void MqttCommunication::updateSensorData(String topic_str, float value) {
  if (topic_str == WEATHER_OUTDOOR_TEMPERATURE_TOPIC) {
    temperature = value;
  } else if (topic_str == WEATHER_OUTDOOR_HUMIDITY_TOPIC) {
    humidity = value;
  } else if (topic_str == WEATHER_OUTDOOR_PRESSURE_TOPIC) {
    pressure = value;
  }
}

void MqttCommunication::processCallbacks() {
  client.loop();
}

void MqttCommunication::publishDiscoveryConfig() {
  if (!client.connected()) {
    Serial.println("MQTT not connected, cannot publish discovery config.");
    return;
  }

  const char* device_id = WEATHER_OUTDOOR_DEVICE_ID;
  const char* manufacturer = "Valur";
  const char* model = "ESP32-S2";
  const char* device_name = "SkySentinel Outdoor Station";

  StaticJsonDocument<256> deviceDoc;
  JsonArray identifiers = deviceDoc.createNestedArray("identifiers");
  identifiers.add(device_id);
  deviceDoc["name"] = device_name;
  deviceDoc["model"] = model;
  deviceDoc["manufacturer"] = manufacturer;

  StaticJsonDocument<512> doc;

  // Temperatur
  doc.clear();
  doc["name"] = "Outdoor Temperature";
  doc["unique_id"] = String(device_id) + "_temperature";
  doc["state_topic"] = WEATHER_OUTDOOR_TEMPERATURE_TOPIC;
  doc["unit_of_measurement"] = "°C";
  doc["device_class"] = "temperature";
  doc["state_class"] = "measurement";
  doc["value_template"] = "{{ value | float | round(2) }}";
  doc["device"] = deviceDoc;

  String tempConfigTopic = String("homeassistant/sensor/") + device_id + "/temperature/config";
  String tempConfigPayload;
  serializeJson(doc, tempConfigPayload);
  client.publish(tempConfigTopic.c_str(), tempConfigPayload.c_str(), true);

  // Luftfeuchtigkeit
  doc.clear();
  doc["name"] = "Outdoor Humidity";
  doc["unique_id"] = String(device_id) + "_humidity";
  doc["state_topic"] = WEATHER_OUTDOOR_HUMIDITY_TOPIC;
  doc["unit_of_measurement"] = "%";
  doc["device_class"] = "humidity";
  doc["state_class"] = "measurement";
  doc["value_template"] = "{{ value | float | round(2) }}";
  doc["device"] = deviceDoc;

  String humConfigTopic = String("homeassistant/sensor/") + device_id + "/humidity/config";
  String humConfigPayload;
  serializeJson(doc, humConfigPayload);
  client.publish(humConfigTopic.c_str(), humConfigPayload.c_str(), true);

  // Luftdruck
  doc.clear();
  doc["name"] = "Outdoor Pressure";
  doc["unique_id"] = String(device_id) + "_pressure";
  doc["state_topic"] = WEATHER_OUTDOOR_PRESSURE_TOPIC;
  doc["unit_of_measurement"] = "hPa";
  doc["device_class"] = "pressure";
  doc["state_class"] = "measurement";
  doc["value_template"] = "{{ value | float | round(2) }}";
  doc["device"] = deviceDoc;

  String presConfigTopic = String("homeassistant/sensor/") + device_id + "/pressure/config";
  String presConfigPayload;
  serializeJson(doc, presConfigPayload);
  client.publish(presConfigTopic.c_str(), presConfigPayload.c_str(), true);

  discoveryPublished = true;
  Serial.println("Home Assistant discovery config for SkySentinel published.");
}

void MqttCommunication::setOtaUpdateRequested(bool requested) {
  otaUpdateRequested = requested;
}

bool MqttCommunication::isOtaUpdateRequested() const {
  return otaUpdateRequested;
}

MqttCommunication* mqttCommPtr;

void mqttCallback(char* topic, byte* payload, unsigned int length) {
  payload[length] = '\0';
  String topic_str = String(topic);
  float value = atof((char*)payload);

  Serial.print("Callback received for topic: ");
  Serial.println(topic_str);
  Serial.print("Payload: ");
  Serial.println(value);

  mqttCommPtr->updateSensorData(topic_str, value);
  if (topic_str == WEATHER_OUTDOOR_OTA_TOPIC) {
    Serial.println("OTA topic received");
    if (value == 1) {
      // Temporarily disable deep sleep for OTA update
      Serial.println("OTA Update requested");
      mqttCommPtr->setOtaUpdateRequested(true);
    }
  }
}
