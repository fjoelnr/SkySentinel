# Setup Guide

This project uses [PlatformIO](https://platformio.org/) for building and uploading the firmware.

## Requirements

* PlatformIO Core or the PlatformIO extension for VS Code
* An ESP32-S2-Saola-1 or ESP32-S2-Kaluga-1 development board
* Optional: [Doxygen](https://www.doxygen.nl/) to regenerate the API documentation

## Steps

1. Clone this repository.
2. Copy `src/credentials_template.h` to `src/credentials.h` and edit the file with your Wi-Fi and MQTT credentials.
3. Build the firmware with `platformio run` or using the build button in PlatformIO.
4. Connect your board via USB and upload the firmware with `platformio run -t upload`.
5. After flashing, the device will start publishing sensor data via MQTT.

## Documentation

Pre-built API documentation is located in the `doc` directory. Run `doxygen doxygen_config` to regenerate it.
