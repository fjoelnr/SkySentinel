#ifndef DISPLAY_COMMUNICATION_H
#define DISPLAY_COMMUNICATION_H

#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

/**
 * @class DisplayCommunication
 * @brief Class to handle display communication for showing weather data.
 */
class DisplayCommunication {
public:
  /**
   * @brief Constructor to create a DisplayCommunication object.
   * @param csPin Chip select pin for the display.
   * @param dcPin Data/command pin for the display.
   * @param mosiPin MOSI pin for the display.
   * @param sclkPin SCLK pin for the display.
   * @param rstPin Reset pin for the display.
   */
  DisplayCommunication(int8_t csPin, int8_t dcPin, int8_t mosiPin, int8_t sclkPin, int8_t rstPin);

  /**
   * @brief Initializes the display.
   */
  void begin();

  /**
   * @brief Displays weather data on the display.
   * @param temperature Current temperature value.
   * @param humidity Current humidity value.
   * @param pressure Current pressure value.
   */
  void showWeatherData(float temperature, float humidity, float pressure);

private:
  /**
   * @brief Updates the temperature value on the display.
   * @param temperature Current temperature value.
   */
  void updateTemperature(float temperature);

  /**
   * @brief Updates the humidity value on the display.
   * @param humidity Current humidity value.
   */
  void updateHumidity(float humidity);

  /**
   * @brief Updates the pressure value on the display.
   * @param pressure Current pressure value.
   */
  void updatePressure(float pressure);

  /**
   * @brief Draws history graphs for the weather data on the display.
   */
  void drawHistoryGraphs();

  Adafruit_ST7789 tft; //!< Instance of the Adafruit ST7789 display driver.
  float lastTemperature; //!< Last temperature value displayed.
  float lastHumidity; //!< Last humidity value displayed.
  float lastPressure; //!< Last pressure value displayed.
};

#endif // DISPLAY_COMMUNICATION_H
