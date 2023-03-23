#ifndef BME280_SENSOR_H
#define BME280_SENSOR_H

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

class BME280_Sensor {
public:
  BME280_Sensor();
  bool begin();
  float readTemperature();
  float readHumidity();
  float readPressure();

private:
  Adafruit_BME280 bme;
};

#endif // BME280_SENSOR_H
