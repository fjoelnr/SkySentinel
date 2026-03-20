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

## What Still Needs Work

- clearer operator-facing setup notes for OTA deployments
- more explicit distinction between indoor and outdoor device roles
- more unit tests around MQTT callback and reconnect behavior
- cleaner separation between generated docs and authored docs

## Current Risk Areas

- OTA and Wi-Fi reconnect paths are operationally sensitive
- board-specific pin definitions remain configuration-heavy
- local network deployment details can drift from checked-in docs
