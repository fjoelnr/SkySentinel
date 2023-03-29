#include "display_communication.h"

#define TFT_CS 11
#define TFT_DC 13
#define TFT_RST 16
#define TFT_MOSI 9
#define TFT_CLK 15
#define TFT_MISO 8
#define TFT_LED 6


Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST, TFT_CLK, TFT_MOSI, TFT_MISO);

void setupDisplay() {
    tft.begin();
    tft.setRotation(3); // Setzen Sie die Display-Rotation, falls erforderlich
    tft.fillScreen(ILI9341_BLACK); // Füllen Sie den Bildschirm mit einer Farbe
    tft.setTextColor(ILI9341_WHITE); // Setzen Sie die Textfarbe
    tft.setTextSize(2); // Setzen Sie die Textgröße
    tft.setCursor(0, 0); // Setzen Sie den Cursor auf die gewünschte Position
    tft.println("Wetterstation Kaluga"); // Zeigen Sie den gewünschten Text an
}

void displayData(float temperature, float humidity, float pressure) {
  tft.setCursor(0, 0);
  tft.print("Temperature: ");
  tft.print(temperature);
  tft.println(" C");

  tft.print("Humidity: ");
  tft.print(humidity);
  tft.println(" %");

  tft.print("Pressure: ");
  tft.print(pressure);
  tft.println(" hPa");
}
