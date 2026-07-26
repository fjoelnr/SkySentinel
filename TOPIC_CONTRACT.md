# Topic Contract

## Shared Base Topics

- `weather/indoor`
- `weather/outdoor`

## Outdoor Telemetry

- `weather/outdoor/temperature`
- `weather/outdoor/humidity`
- `weather/outdoor/pressure`

The outdoor node publishes these values after each successful sensor read and MQTT reconnect.

## Indoor Display Inputs

- `weather/outdoor/temperature`
- `weather/outdoor/humidity`
- `weather/outdoor/pressure`

The indoor display node consumes the same outdoor telemetry and renders the latest values locally.

## OTA Control

- `weather/outdoor/ota`

Payload `1` signals that the outdoor node should stay awake for OTA handling.

## Home Assistant Discovery

The outdoor station publishes retained discovery payloads under:

- `homeassistant/sensor/weather_outdoor_station/temperature/config`
- `homeassistant/sensor/weather_outdoor_station/humidity/config`
- `homeassistant/sensor/weather_outdoor_station/pressure/config`

## Device Identifiers

- `weather_indoor_station`
- `weather_outdoor_station`
