#include "display_communication.h"

// Custom color definitions
#define CUSTOM_BLUE 0xFFE0
#define CUSTOM_GREEN 0xF81F
#define CUSTOM_RED 0x07FF

#define NUM_DATA_POINTS 30
float temperatureHistory[NUM_DATA_POINTS] = {0};
float humidityHistory[NUM_DATA_POINTS] = {0};
unsigned long lastUpdateTime = 0;
const unsigned long updateInterval = 120000; // 2 Minuten

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
  tft.fillRect(5, 40, 140, 30, CUSTOM_BLUE);
  tft.fillRect(5, 70, 140, 30, CUSTOM_GREEN);
  tft.fillRect(5, 100, 140, 30, CUSTOM_RED);

  // Labels for Temperature, Humidity, and Pressure
  tft.setTextSize(1);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 50);
  tft.print("Temperature: ");
  tft.setCursor(10, 80);
  tft.print("Humidity: ");
  tft.setCursor(10, 110);
  tft.print("Pressure: ");

  // Units for each value with symbols
  tft.setCursor(125, 50);
  tft.print((char)248);
  tft.print("C");
  tft.setCursor(125, 80);
  tft.print("%");
  tft.setCursor(125, 110);
  tft.print("hPa");

  delay(100);
}


void updateHistoryArrays(float temperature, float humidity) {
  for (int i = NUM_DATA_POINTS - 1; i > 0; i--) {
    temperatureHistory[i] = temperatureHistory[i - 1];
    humidityHistory[i] = humidityHistory[i - 1];
  }
  temperatureHistory[0] = temperature;
  humidityHistory[0] = humidity;
}

void DisplayCommunication::showWeatherData(float temperature, float humidity, float pressure) {
  updateTemperature(temperature);
  updateHumidity(humidity);
  updatePressure(pressure);
  
  unsigned long currentTime = millis();
  if (currentTime - lastUpdateTime > updateInterval) {
    updateHistoryArrays(temperature, humidity);
    drawHistoryGraphs();
    lastUpdateTime = currentTime;
  }

}

void DisplayCommunication::updateTemperature(float temperature) {
  tft.setTextSize(1);
  tft.setTextColor(CUSTOM_BLUE);
  tft.setCursor(85, 50);
  tft.print(lastTemperature, 1);
  tft.setCursor(85, 50);
  tft.setTextColor(ST77XX_WHITE);
  tft.print(temperature, 1);
  lastTemperature = temperature;
}

void DisplayCommunication::updateHumidity(float humidity) {
  tft.setTextSize(1);
  tft.setCursor(85, 80);
  tft.setTextColor(CUSTOM_GREEN);
  tft.print(lastHumidity, 1);
  tft.setCursor(85, 80);
  tft.setTextColor(ST77XX_WHITE);
  tft.print(humidity, 1);
  lastHumidity = humidity;
}

void DisplayCommunication::updatePressure(float pressure) {
  tft.setTextSize(1);
  tft.setCursor(85, 110);
  tft.setTextColor(CUSTOM_RED);
  tft.print(lastPressure, 1);
  tft.setCursor(85, 110);
  tft.setTextColor(ST77XX_WHITE);
  tft.print(pressure, 1);
  lastPressure = pressure;
}

void DisplayCommunication::drawHistoryGraphs() {
  int graphWidth = 200;
  int graphHeight = 40;
  int graphX = 20;
  
  // Temperature graph position
  int graphY1 = 130;

  // Clear temperature graph area
  tft.fillRect(graphX, graphY1, graphWidth, graphHeight, ST77XX_BLACK);

  // Zeichnen der Temperaturkurve
  tft.setTextColor(CUSTOM_BLUE);
  for (int i = 0; i < NUM_DATA_POINTS - 1; i++) {
    int x1 = map(i, 0, NUM_DATA_POINTS - 1, graphX, graphX + graphWidth);
    int x2 = map(i + 1, 0, NUM_DATA_POINTS - 1, graphX, graphX + graphWidth);
    int y1 = map(temperatureHistory[i], -20, 50, graphY1 + graphHeight, graphY1);
    int y2 = map(temperatureHistory[i + 1], -20, 50, graphY1 + graphHeight, graphY1);
    tft.drawLine(x1, y1, x2, y2, CUSTOM_BLUE);
  }

  // Humidity graph position
  int graphY2 = 160;

  // Clear humidity graph area
  tft.fillRect(graphX, graphY2, graphWidth, graphHeight, ST77XX_BLACK);

  // Zeichnen der Luftfeuchtigkeitskurve
  tft.setTextColor(CUSTOM_GREEN);
  for (int i = 0; i < NUM_DATA_POINTS - 1; i++) {
    int x1 = map(i, 0, NUM_DATA_POINTS - 1, graphX, graphX + graphWidth);
    int x2 = map(i + 1, 0, NUM_DATA_POINTS - 1, graphX, graphX + graphWidth);
    int y1 = map(humidityHistory[i], 0, 100, graphY2 + graphHeight, graphY2);
    int y2 = map(humidityHistory[i + 1], 0, 100, graphY2 + graphHeight, graphY2);
    tft.drawLine(x1, y1, x2, y2, CUSTOM_GREEN);
  }
}
