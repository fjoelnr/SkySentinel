#include "display_communication.h"

// Custom color definitions
#define CUSTOM_BLUE 0xFFE0
#define CUSTOM_GREEN 0xF81F
#define CUSTOM_RED 0x07FF

DisplayCommunication::DisplayCommunication(int8_t csPin, int8_t dcPin, int8_t mosiPin, int8_t sclkPin, int8_t rstPin)
    : tft(Adafruit_ST7789(csPin, dcPin, mosiPin, sclkPin, rstPin)) {}

void DisplayCommunication::begin() {
  tft.init(240, 320);
  tft.setRotation(3);
  tft.fillScreen(ST77XX_BLACK);
  delay(100);

  // Weather Station title
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(60, 10);
  tft.setTextWrap(true);
  tft.print("Weather Station");

  // Draw rectangles around each value
  tft.fillRect(5, 40, 230, 40, CUSTOM_BLUE);
  tft.fillRect(5, 90, 230, 40, CUSTOM_GREEN);
  tft.fillRect(5, 140, 230, 40, CUSTOM_RED);

  // Labels for Temperature, Humidity, and Pressure
  tft.setTextSize(1);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 55);
  tft.print("Temperature: ");
  tft.setCursor(10, 105);
  tft.print("Humidity: ");
  tft.setCursor(10, 155);
  tft.print("Pressure: ");

  // Units for each value with symbols
  tft.setCursor(200, 55);
  tft.print((char)248);
  tft.print("C");
  tft.setCursor(200, 105);
  tft.print("%");
  tft.setCursor(200, 155);
  tft.print("hPa");

  delay(100);
}

void DisplayCommunication::showWeatherData(float temperature, float humidity, float pressure) {
  updateTemperature(temperature);
  updateHumidity(humidity);
  updatePressure(pressure);
}

void DisplayCommunication::updateTemperature(float temperature) {
  tft.setTextSize(1);
  tft.setTextColor(CUSTOM_BLUE);
  tft.setCursor(110, 55);
  tft.print(lastTemperature, 1);
  tft.setCursor(110, 55);
  tft.setTextColor(ST77XX_WHITE);
  tft.print(temperature, 1);
  lastTemperature = temperature;
}

void DisplayCommunication::updateHumidity(float humidity) {
  tft.setTextSize(1);
  tft.setCursor(110, 105);
  tft.setTextColor(CUSTOM_GREEN);
  tft.print(lastHumidity, 1);
  tft.setCursor(110, 105);
  tft.setTextColor(ST77XX_WHITE);
  tft.print(humidity, 1);
  lastHumidity = humidity;
}

void DisplayCommunication::updatePressure(float pressure) {
  tft.setTextSize(1);
  tft.setCursor(110, 155);
  tft.setTextColor(CUSTOM_RED);
  tft.print(lastPressure, 1);
  tft.setCursor(110, 155);
  tft.setTextColor(ST77XX_WHITE);
  tft.print(pressure, 1);
  lastPressure = pressure;
}
