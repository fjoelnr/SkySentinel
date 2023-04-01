#include "bme280_communication.h"

BME280Communication::BME280Communication() {
}

bool BME280Communication::begin() {
  return bme.begin();
}

void BME280Communication::readSensorData(float &temperature, float &humidity, float &pressure) {
  temperature = readTemperature();
  humidity = readHumidity();
  pressure = readPressure();
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
