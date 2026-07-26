#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include <Arduino.h>
#include <WebServer.h>

class WebServerWrapper {
 public:
  WebServerWrapper(uint16_t port = 80);
  void setup();
  void handleClient();
  void setSensorDataProvider(float (*temperature)(), float (*humidity)(), float (*pressure)());

 private:
  WebServer server;
  float (*getTemperature)();
  float (*getHumidity)();
  float (*getPressure)();

  void handleRoot();
  void handleApi();
};

#endif  // WEB_SERVER_H
