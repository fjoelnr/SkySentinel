#include "bme280_communication.h"

BME280Communication::BME280Communication(uint8_t i2cAddress) : _i2cAddress(i2cAddress) {}

bool BME280Communication::begin(TwoWire &wire) {
  return bme.begin(_i2cAddress, &wire);
}

void BME280Communication::readSensorData(float &temperature, float &humidity, float &pressure) {
  temperature = bme.readTemperature();
  humidity = bme.readHumidity();
  pressure = bme.readPressure() / 100.0F;
}

float BME280Communication::readTemperature() {
  return bme.readTemperature();
}

float BME280Communication::readHumidity() {
  return bme.readHumidity();
}

float BME280Communication::readPressure() {
  return bme.readPressure() / 100.0F;
}
