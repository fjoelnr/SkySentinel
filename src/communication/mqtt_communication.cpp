#include "mqtt_communication.h"

MqttCommunication::MqttCommunication(WifiCommunication& wifiComm)
  : _wifiComm(wifiComm), _client(wifiComm.getClient()) {
  _client.setServer(MQTT_SERVER, MQTT_PORT);
}

bool MqttCommunication::connect() {
  while (!_client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (_client.connect("ESP32Client", MQTT_USERNAME, MQTT_PASSWORD)) {
      Serial.println("connected");
      return true;
    } else {
      Serial.print("failed, rc=");
      Serial.print(_client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
  return false;
}

bool MqttCommunication::isConnected() {
  return _client.connected();
}

bool MqttCommunication::sendData(const String& topic, const String& data) {
  return _client.publish(topic.c_str(), data.c_str());
}
