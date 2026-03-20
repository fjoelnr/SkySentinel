/**
 * @file bme280_communication.h
 * @author fjoelnr
 * @date 2023-04-04
 * @brief This file contains the BME280Communication class for interacting with the BME280 sensor.
 */

#ifndef BME280_COMMUNICATION_H
#define BME280_COMMUNICATION_H

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

/**
 * @brief BME280Communication class for reading data from the BME280 sensor.
 */
class BME280Communication {
public:
  /**
   * @brief Construct a new BME280Communication object.
   */
  BME280Communication();

  /**
   * @brief Initialize the BME280 sensor.
   * @return true if initialization is successful, false otherwise.
   */
  bool begin();

  /**
   * @brief Read sensor data and update the reference values.
   * @param[out] temperature Reference to a float variable to store the temperature value.
   * @param[out] humidity Reference to a float variable to store the humidity value.
   * @param[out] pressure Reference to a float variable to store the pressure value.
   */
  void readSensorData(float &temperature, float &humidity, float &pressure);

  /**
   * @brief Read the temperature value from the sensor.
   * @return The temperature value in degrees Celsius.
   */
  float readTemperature();

  /**
   * @brief Read the humidity value from the sensor.
   * @return The humidity value in percentage.
   */
  float readHumidity();

  /**
   * @brief Read the pressure value from the sensor.
   * @return The pressure value in hPa.
   */
  float readPressure();

private:
  Adafruit_BME280 bme; ///< BME280 sensor object.
  uint8_t _i2cAddress; ///< I2C address of the BME280 sensor.
  int _sdaPin;         ///< SDA pin for I2C communication.
  int _sclPin;         ///< SCL pin for I2C communication.
};

#endif // BME280_COMMUNICATION_H
