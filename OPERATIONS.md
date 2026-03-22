# Operations

## Device Roles

`SkySentinel` currently supports two concrete firmware roles:

- `saola`: outdoor station, reads BME280 values, publishes MQTT telemetry, exposes OTA handling
- `kaluga`: indoor display node, subscribes to the shared MQTT topics and renders the latest values locally

Both roles share the same topic constants and credentials layout, but only the outdoor node publishes sensor values.

## Canonical Build Targets

```bash
platformio run -e saola
platformio run -e kaluga
```

Upload over USB or your configured OTA target:

```bash
platformio run -e saola -t upload
platformio run -e kaluga -t upload
```

## OTA Control

The outdoor node subscribes to:

- `weather/outdoor/ota`

Publishing payload `1` to that topic requests an OTA maintenance window and keeps the device awake for update handling.

## Practical Operator Checks

After flashing or OTA upload, verify:

1. the node joins Wi-Fi with the configured `WIFI_HOSTNAME`
2. MQTT telemetry reaches `weather/outdoor/*`
3. Home Assistant discovery entities appear for the outdoor station
4. the indoor display updates after new outdoor messages arrive

## Local Configuration Rules

- keep `src/credentials.h` local and untracked
- keep environment-specific OTA IPs or hostnames aligned with your own network
- do not hardcode secrets into tracked files
