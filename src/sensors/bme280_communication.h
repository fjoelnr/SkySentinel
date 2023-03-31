#ifndef BME280_COMMUNICATION_H
#define BME280_COMMUNICATION_H

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

class BME280Communication {
public:
  BME280Communication(uint8_t i2cAddress);
  bool begin(TwoWire &wire = Wire);
  void readSensorData(float &temperature, float &humidity, float &pressure);
  float readTemperature();
  float readHumidity();
  float readPressure();

private:
  Adafruit_BME280 bme;
  uint8_t _i2cAddress;
};

#endif // BME280_COMMUNICATION_H
