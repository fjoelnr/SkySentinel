#ifndef DATA_PROCESSING_H
#define DATA_PROCESSING_H

#include "ring_buffer.h"

/**
 * @brief Processes sensor data and adds it to the ring buffer.
 *
 * @param timestamp The timestamp of the recorded data.
 * @param temperature The temperature in degrees Celsius.
 * @param humidity The humidity in percentage.
 * @param pressure The pressure in hPa.
 */
void processSensorData(uint32_t timestamp, float temperature, float humidity, float pressure);

#endif // DATA_PROCESSING_H
