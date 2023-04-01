#ifndef DISPLAY_COMMUNICATION_H
#define DISPLAY_COMMUNICATION_H

#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>


class DisplayCommunication {
public:
  DisplayCommunication(int8_t csPin, int8_t dcPin, int8_t mosiPin, int8_t sclkPin, int8_t rstPin);
  void begin();
  void showWeatherData(float temperature, float humidity, float pressure);

private:
  void updateTemperature(float temperature);
  void updateHumidity(float humidity);
  void updatePressure(float pressure);
  void drawHistoryGraphs();
  Adafruit_ST7789 tft;
  float lastTemperature = 0;
  float lastHumidity = 0;
  float lastPressure = 0;
};

#endif // DISPLAY_COMMUNICATION_H