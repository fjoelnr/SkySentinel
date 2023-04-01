#ifndef BME280_COMMUNICATION_H
#define BME280_COMMUNICATION_H

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

class BME280Communication {
public:
  BME280Communication();
  bool begin();
  void readSensorData(float &temperature, float &humidity, float &pressure);
  float readTemperature();
  float readHumidity();
  float readPressure();

private:
  Adafruit_BME280 bme;
  uint8_t _i2cAddress;
  int _sdaPin;
  int _sclPin;
};

#endif // BME280_COMMUNICATION_H
