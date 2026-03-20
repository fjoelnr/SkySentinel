#include "ring_buffer.h"

/**
 * @brief Weather data buffer for storing historical data.
 */
WeatherData weatherDataBuffer[bufferSize];

/**
 * @brief The index at which the next weather data item should be stored in the buffer.
 */
size_t bufferIndex = 0;

/**
 * @brief Indicates whether the buffer is full.
 */
bool bufferFull = false;

void addWeatherDataToBuffer(const WeatherData& data) {
  weatherDataBuffer[bufferIndex] = data;
  bufferIndex = (bufferIndex + 1) % bufferSize;

  if (!bufferFull && bufferIndex == 0) {
    bufferFull = true;
  }
}

size_t getWeatherDataHistory(WeatherData* outputBuffer, size_t outputBufferSize) {
  size_t count = 0;

  if (bufferFull) {
    for (size_t i = bufferIndex; i < bufferSize && count < outputBufferSize; ++i) {
      outputBuffer[count++] = weatherDataBuffer[i];
    }
  }

  for (size_t i = 0; i < bufferIndex && count < outputBufferSize; ++i) {
    outputBuffer[count++] = weatherDataBuffer[i];
  }

  return count;
}
