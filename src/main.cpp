#include <Arduino.h>
#include "sensors/bme280_sensor.h"

BME280_Sensor bmeSensor;

void setup() {
  Serial.begin(115200);
  if (!bmeSensor.begin()) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}

void loop() {
  Serial.print("Temperature = ");
  Serial.print(bmeSensor.readTemperature());
  Serial.println(" *C");

  Serial.print("Humidity = ");
  Serial.print(bmeSensor.readHumidity());
  Serial.println(" %");

  Serial.print("Pressure = ");
  Serial.print(bmeSensor.readPressure());
  Serial.println(" hPa");

  delay(2000);
}
