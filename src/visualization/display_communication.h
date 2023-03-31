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
  Adafruit_ST7789 tft;
  void drawTemperature(float temperature);
  void drawHumidity(float humidity);
  void drawPressure(float pressure);
};

#endif // DISPLAY_COMMUNICATION_H