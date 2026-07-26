#ifndef SOIL_MOISTURE_SENSOR_H
#define SOIL_MOISTURE_SENSOR_H

class SoilMoistureSensor {
 public:
  void begin() {}
  float readMoisture() { return 0.0f; }
};

#endif  // SOIL_MOISTURE_SENSOR_H
