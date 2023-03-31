#include "display_communication.h"

DisplayCommunication::DisplayCommunication(int8_t csPin, int8_t dcPin, int8_t mosiPin, int8_t sclkPin, int8_t rstPin)
    : tft(Adafruit_ST7789(csPin, dcPin, mosiPin, sclkPin, rstPin)) {}

void DisplayCommunication::begin() {
  tft.init(240, 320);
  tft.setRotation(3);
  tft.fillScreen(ST77XX_BLACK);
  delay(500);
  tft.fillScreen(ST77XX_WHITE);
  delay(500);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 10);
  tft.setTextWrap(true);
  tft.print("Weather Station");
}

void DisplayCommunication::showWeatherData(float temperature, float humidity, float pressure) {
  tft.fillScreen(ST77XX_BLACK);
  // tft.setTextSize(2);
  // tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 10);
  tft.setTextWrap(true);
  tft.print("Weather Station");
  drawTemperature(temperature);
  drawHumidity(humidity);
  drawPressure(pressure);
}

void DisplayCommunication::drawTemperature(float temperature) {
  tft.setCursor(10, 50);
  tft.print("Temperature: ");
  tft.print(temperature);
  tft.print(" C");
}

void DisplayCommunication::drawHumidity(float humidity) {
  tft.setCursor(10, 90);
  tft.print("Humidity: ");
  tft.print(humidity);
  tft.print(" %");
}

void DisplayCommunication::drawPressure(float pressure) {
  tft.setCursor(10, 130);
  tft.print("Pressure: ");
  tft.print(pressure / 100.0); // Umrechnung in hPa
  tft.print(" hPa");
}