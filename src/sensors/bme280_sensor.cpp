#include "bme280_sensor.h"

BME280_Sensor::BME280_Sensor() {
}

bool BME280_Sensor::begin() {
  if (!bme.begin()) {
    return false;
  }
  return true;
}

float BME280_Sensor::readTemperature() {
  return bme.readTemperature();
}

float BME280_Sensor::readHumidity() {
  return bme.readHumidity();
}

float BME280_Sensor::readPressure() {
  return bme.readPressure() / 100.0F;
}
