# Status

## Project State

`SkySentinel` is an active firmware project, not an archived hardware experiment.

The current codebase already covers the core weather-station loop:

- sensor reads from the BME280
- Wi-Fi connectivity
- MQTT publishing and subscription flow
- display support for the indoor station
- OTA-related update handling

## What Works

- PlatformIO-based firmware builds
- MQTT telemetry for weather values
- shared topic definitions for weather data
- Home Assistant discovery publishing
- ring-buffer based weather data storage
- OTA handling in the outdoor node runtime
- indoor display rendering from shared MQTT topics

## What Still Needs Work

- more unit tests around MQTT callback and reconnect behavior
- cleaner separation between generated docs and authored docs
- board-role and operations docs must stay aligned with `platformio.ini`

## Current Risk Areas

- OTA and Wi-Fi reconnect paths are operationally sensitive
- board-specific pin definitions remain configuration-heavy
- local network deployment details can drift from checked-in docs
- MQTT payload handling is still simple and should remain tightly scoped
