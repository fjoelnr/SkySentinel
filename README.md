# SkySentinel

Modular ESP32-S2 weather station firmware for indoor or outdoor telemetry, MQTT transport, optional Home Assistant auto-discovery, and OTA-friendly operation.

[English](#english) | [Deutsch](#deutsch)

## English

SkySentinel is a builder-oriented firmware project for ESP32 weather stations. It currently targets the ESP32-S2 Saola and Kaluga boards and combines BME280 sensor readings, Wi-Fi connectivity, MQTT publishing, display support, and recent OTA integration work.

### What It Does

- reads temperature, humidity, and pressure from a BME280
- publishes weather data via MQTT
- supports an indoor display node and an outdoor sensor node
- can publish Home Assistant discovery payloads for MQTT entities
- keeps the firmware small enough to iterate on quickly in PlatformIO

### Current Focus

The current codebase is focused on:

- ESP32-S2 outdoor station telemetry
- MQTT topic cleanup and shared topic constants
- OTA-triggered maintenance flows
- display updates for the indoor station
- incremental hardening with PlatformIO tests and GitHub Actions

Planned improvements remain tracked in [ROADMAP.md](ROADMAP.md).

### Quick Start

1. Clone the repository.
2. Copy `src/credentials_template.h` to `src/credentials.h`.
3. Fill in Wi-Fi, MQTT, and optional hostname values.
4. Build the firmware with `platformio run`.
5. Upload it with USB or your configured OTA target.

See [SETUP.md](SETUP.md) for the practical setup flow.

### Repository Layout

```text
src/sensors/         sensor adapters such as BME280
src/network/         Wi-Fi and MQTT communication layers
src/visualization/   display communication
src/data_processing/ ring buffer and processing helpers
test/                PlatformIO unit tests
doc/                 generated Doxygen output
```

### Documentation

- [SETUP.md](SETUP.md)
- [STATUS.md](STATUS.md)
- [OPERATIONS.md](OPERATIONS.md)
- [TOPIC_CONTRACT.md](TOPIC_CONTRACT.md)
- [ROADMAP.md](ROADMAP.md)
- generated API docs in [doc](doc/)

### Contributing

Before changing code, read:

- [CONTRIBUTING.md](CONTRIBUTING.md)
- [SECURITY.md](SECURITY.md)
- [AGENTS.md](AGENTS.md)

### License

MIT, see [LICENSE](LICENSE).

---

## Deutsch

SkySentinel ist ein firmware-orientiertes ESP32-Wetterstationsprojekt fuer Indoor- und Outdoor-Szenarien. Der aktuelle Schwerpunkt liegt auf ESP32-S2-Boards, MQTT-gestuetzter Telemetrie, optionaler Home-Assistant-Auto-Discovery und einem OTA-faehigen Betriebsmodell.

### Was das Projekt aktuell kann

- Temperatur, Luftfeuchtigkeit und Druck per BME280 erfassen
- Wetterdaten per MQTT veroeffentlichen
- Indoor-Display- und Outdoor-Sensorknoten abbilden
- Home-Assistant-Discovery-Konfiguration per MQTT senden
- schnelle Firmware-Iteration mit PlatformIO ermoeglichen

### Aktueller Schwerpunkt

- Outdoor-Telemetrie fuer ESP32-S2
- gemeinsame MQTT-Topics und konsistente Topic-Namen
- OTA-gestuetzte Wartung
- Anzeige-Updates fuer die Indoor-Station
- schrittweise Robustheit und Testabdeckung

### Schnellstart

1. Repository klonen.
2. `src/credentials_template.h` nach `src/credentials.h` kopieren.
3. WLAN-, MQTT- und optionalen Hostnamen eintragen.
4. Firmware mit `platformio run` bauen.
5. Per USB oder konfiguriertem OTA-Ziel hochladen.

Details stehen in [SETUP.md](SETUP.md).

### Struktur

```text
src/sensors/         Sensoranbindungen wie BME280
src/network/         Wi-Fi- und MQTT-Kommunikation
src/visualization/   Display-Ansteuerung
src/data_processing/ Ringpuffer und Datenverarbeitung
test/                PlatformIO-Unit-Tests
doc/                 generierte Doxygen-Dokumentation
```

### Weitere Doku

- [SETUP.md](SETUP.md)
- [STATUS.md](STATUS.md)
- [OPERATIONS.md](OPERATIONS.md)
- [TOPIC_CONTRACT.md](TOPIC_CONTRACT.md)
- [ROADMAP.md](ROADMAP.md)
- generierte API-Doku unter [doc](doc/)

