#include "data_processing.h"

/**
 * @brief Processes sensor data and adds it to the ring buffer.
 *
 * @param timestamp The timestamp of the recorded data.
 * @param temperature The temperature in degrees Celsius.
 * @param humidity The humidity in percentage.
 * @param pressure The pressure in hPa.
 */
void processSensorData(uint32_t timestamp, float temperature, float humidity, float pressure) {
  WeatherData newData = {timestamp, temperature, humidity, pressure};
  addWeatherDataToBuffer(newData);
}
