#ifndef LIGHTNING_SENSOR_H
#define LIGHTNING_SENSOR_H

class LightningSensor {
 public:
  void begin() {}
  bool detected() { return false; }
};

#endif  // LIGHTNING_SENSOR_H
