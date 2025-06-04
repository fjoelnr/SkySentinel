#include "web_server.h"

WebServerWrapper::WebServerWrapper(uint16_t port)
    : server(port), getTemperature(nullptr), getHumidity(nullptr), getPressure(nullptr) {}

void WebServerWrapper::setSensorDataProvider(float (*temperature)(), float (*humidity)(), float (*pressure)()) {
  getTemperature = temperature;
  getHumidity = humidity;
  getPressure = pressure;
}

void WebServerWrapper::setup() {
  server.on("/", [this]() { handleRoot(); });
  server.on("/api/sensor", [this]() { handleApi(); });
  server.begin();
}

void WebServerWrapper::handleClient() { server.handleClient(); }

void WebServerWrapper::handleRoot() {
  String html = "<html><body><h1>Weather Station</h1>";
  if (getTemperature && getHumidity && getPressure) {
    html += "<p>Temperature: " + String(getTemperature()) + "</p>";
    html += "<p>Humidity: " + String(getHumidity()) + "</p>";
    html += "<p>Pressure: " + String(getPressure()) + "</p>";
  } else {
    html += "<p>Sensor data unavailable</p>";
  }
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void WebServerWrapper::handleApi() {
  if (getTemperature && getHumidity && getPressure) {
    String json = "{";
    json += "\"temperature\":" + String(getTemperature()) + ",";
    json += "\"humidity\":" + String(getHumidity()) + ",";
    json += "\"pressure\":" + String(getPressure());
    json += "}";
    server.send(200, "application/json", json);
  } else {
    server.send(503, "application/json", "{\"error\":\"sensor data unavailable\"}");
  }
}
