# Setup Guide

This project uses [PlatformIO](https://platformio.org/) for building and uploading the firmware.

## Requirements

* PlatformIO Core or the PlatformIO extension for VS Code
* An ESP32-S2-Saola-1 or ESP32-S2-Kaluga-1 development board
* Optional: [Doxygen](https://www.doxygen.nl/) to regenerate the API documentation
* Optional: an MQTT broker and Home Assistant instance for discovery testing

## Steps

1. Clone this repository.
2. Copy `src/credentials_template.h` to `src/credentials.h` and edit the file with your Wi-Fi and MQTT credentials.
3. Set an optional `WIFI_HOSTNAME` if you want a stable DHCP/OTA name.
4. Review `platformio.ini` for the correct board environment, display pins, and upload settings.
5. Build the firmware with `platformio run` or using the build button in PlatformIO.
6. Connect your board via USB and upload the firmware with `platformio run -t upload`.
7. If OTA is configured for your environment, you can also use the configured OTA upload target from `platformio.ini`.
8. After flashing, the device will connect to Wi-Fi and publish sensor data via MQTT.
9. If Home Assistant MQTT discovery is enabled on your broker, the outdoor station will also publish entity discovery payloads.

## Documentation

Pre-built API documentation is located in the `doc` directory. Run `doxygen doxygen_config` to regenerate it.

## Notes

- `src/credentials.h` is local machine configuration and should stay untracked.
- Keep environment-specific IP addresses and OTA targets aligned with your own network before flashing.
