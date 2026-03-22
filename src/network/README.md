# Network

This directory contains the Wi-Fi and MQTT communication layers for `SkySentinel`.

- `wifi_communication.*`: Wi-Fi setup, connection handling, and hostname usage
- `mqtt_communication.*`: MQTT reconnect logic, telemetry publishing, subscriptions, and Home Assistant discovery

The current firmware uses MQTT as the canonical transport between the outdoor node and the indoor display node.
