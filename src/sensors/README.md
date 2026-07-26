# Sensors

This directory contains sensor integrations for the firmware.

The current primary implementation is:

- `bme280_communication.*`: temperature, humidity, and pressure reads for the outdoor station

Future sensor work should extend this layer instead of hardcoding reads directly into `main.cpp`.
