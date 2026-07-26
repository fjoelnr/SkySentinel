#ifndef WIND_SENSOR_H
#define WIND_SENSOR_H

class WindSensor {
 public:
  void begin() {}
  float readSpeed() { return 0.0f; }
  float readDirection() { return 0.0f; }
};

#endif  // WIND_SENSOR_H
