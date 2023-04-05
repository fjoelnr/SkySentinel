/**
 * @file bme280_communication.cpp
 * @author fjoelnr
 * @date 2023-04-04
 * @brief This file contains the implementation of the BME280Communication class for interacting with the BME280 sensor.
 */

#include "bme280_communication.h"

/**
 * @brief Construct a new BME280Communication object.
 */
BME280Communication::BME280Communication() {
}

/**
 * @brief Initialize the BME280 sensor.
 * @return true if initialization is successful, false otherwise.
 */
bool BME280Communication::begin() {
  return bme.begin();
}

/**
 * @brief Read sensor data and update the reference values.
 * @param[out] temperature Reference to a float variable to store the temperature value.
 * @param[out] humidity Reference to a float variable to store the humidity value.
 * @param[out] pressure Reference to a float variable to store the pressure value.
 */
void BME280Communication::readSensorData(float &temperature, float &humidity, float &pressure) {
  temperature = readTemperature();
  humidity = readHumidity();
  pressure = readPressure();
}

/**
 * @brief Read the temperature value from the sensor.
 * @return The temperature value in degrees Celsius.
 */
float BME280Communication::readTemperature() {
  return bme.readTemperature();
}

/**
 * @brief Read the humidity value from the sensor.
 * @return The humidity value in percentage.
 */
float BME280Communication::readHumidity() {
  return bme.readHumidity();
}

/**
 * @brief Read the pressure value from the sensor.
 * @return The pressure value in hPa.
 */
float BME280Communication::readPressure() {
  return bme.readPressure() / 100.0F;
}

