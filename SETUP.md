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
4. Choose the correct board role in `platformio.ini`:
   - `saola` for the outdoor sensor node
   - `kaluga` for the indoor display node
5. Review the board-specific display pins and upload settings in `platformio.ini`.
6. Build the firmware with `platformio run -e saola` or `platformio run -e kaluga`.
7. Connect your board via USB and upload with `platformio run -e <env> -t upload`.
8. If OTA is configured for your environment, you can also use the configured OTA upload target from `platformio.ini`.
9. After flashing, the outdoor node will publish sensor data via MQTT and the indoor node will subscribe to the shared topics.
10. If Home Assistant MQTT discovery is enabled on your broker, the outdoor station will also publish retained discovery payloads.
11. For OTA maintenance, publish `1` to `weather/outdoor/ota` and keep the device reachable on the network.

## Documentation

Pre-built API documentation is located in the `doc` directory. Run `doxygen doxygen_config` to regenerate it.

## Notes

- `src/credentials.h` is local machine configuration and should stay untracked.
- Keep environment-specific IP addresses and OTA targets aligned with your own network before flashing.
- Review [OPERATIONS.md](OPERATIONS.md) and [TOPIC_CONTRACT.md](TOPIC_CONTRACT.md) before changing role behavior or MQTT paths.
