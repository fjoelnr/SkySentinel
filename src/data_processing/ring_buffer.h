#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <Arduino.h>

/**
 * @brief A structure to hold weather data.
 */
struct WeatherData {
  uint32_t timestamp;  ///< Timestamp of the recorded data
  float temperature;   ///< Temperature in degrees Celsius
  float humidity;      ///< Humidity in percentage
  float pressure;      ///< Pressure in hPa
  // Weitere Sensordaten hier
};

/**
 * @brief The size of the ring buffer.
 */
const size_t bufferSize = 1440; // Speichert 24 Stunden Daten bei einem 1-Minuten-Intervall

extern WeatherData weatherDataBuffer[];
extern size_t bufferIndex;
extern bool bufferFull;

/**
 * @brief Adds a new weather data item to the buffer.
 * 
 * This function adds a new weather data item to the buffer.
 * When the buffer is full, the oldest item is overwritten.
 * 
 * @param data The weather data item to be added.
 */
void addWeatherDataToBuffer(const WeatherData& data);

/**
 * @brief Retrieves historical weather data from the buffer.
 * 
 * This function retrieves the historical weather data stored in the buffer.
 * The data is returned in reverse chronological order (i.e., the most recent data first).
 * 
 * @param outputBuffer An array to store the retrieved data.
 * @param outputBufferSize The size of the outputBuffer array.
 * @return The number of weather data items retrieved.
 */
size_t getWeatherDataHistory(WeatherData* outputBuffer, size_t outputBufferSize);

#endif // RING_BUFFER_H
