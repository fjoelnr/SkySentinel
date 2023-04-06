## Roadmap

### English

This roadmap outlines the planned features and improvements for the Modular Weather Station project.

1. **Integrate additional sensors:**
   - Anemometer (Wind speed sensor)
   - Wind vane (Wind direction sensor)
   - Rain gauge (Precipitation sensor)
   - UV sensor
   - Soil moisture sensor
   - Lightning sensor

2. **Web application development:**
   - User interface for displaying real-time weather data
   - Historical data visualization and analysis
   - Configuration and management of weather station settings

3. **Web application on the ESP32:**
   - Minimalist web application with live data and configuration options hosted on the ESP32

4. **API development:**
   - Develop an API to expose weather data and allow configuration updates

5. **Server-based web application (example for Raspberry Pi):**
   - General server-based web application, exemplarily set up for Raspberry Pi
   a. Set up the server environment (consider using Docker for all components, including InfluxDB, Grafana, etc.)
   b. Create a web frontend for displaying data and managing the weather station
   c. Integrate InfluxDB for storing and managing weather data
   d. Integrate Grafana for data visualization and analysis
   e. Implement an alerting function for specific weather conditions

6. **OTA (Over-the-Air) functionality:**
   - Implement OTA updates for the weather station firmware

7. **Integration with home automation systems:**
   a. Integrate with ioBroker
   b. Integrate with Home Assistant

### Deutsch

Diese Roadmap skizziert die geplanten Funktionen und Verbesserungen für das modulare Wetterstationsprojekt.

1. **Integration zusätzlicher Sensoren:**
   - Anemometer (Windgeschwindigkeitssensor)
   - Windfahne (Windrichtungssensor)
   - Regenmesser (Niederschlagssensor)
   - UV-Sensor
   - Bodenfeuchtigkeitssensor
   - Blitzsensor

2. **Entwicklung einer Webanwendung:**
   - Benutzeroberfläche zur Anzeige von Echtzeit-Wetterdaten
   - Visualisierung und Analyse von historischen Daten
   - Konfiguration und Verwaltung der Wetterstationseinstellungen

3. **Webanwendung auf dem ESP32:**
   - Minimalistische Webanwendung mit Live-Daten und Konfigurationsoptionen, gehostet auf dem ESP32

4. **API-Entwicklung:**
   - Entwicklung einer API zur Bereitstellung von Wetterdaten und Aktualisierung der Konfiguration

5. **Serverbasierte Webanwendung (Beispiel für Raspberry Pi):**
   - Allgemeine serverbasierte Webanwendung, exemplarisch aufgesetzt für Raspberry Pi
   a. Einrichten der Serverumgebung (Docker für alle Komponenten, einschließlich InfluxDB, Grafana usw. in Betracht ziehen)
   b. Erstellen einer Web-Benutzeroberfläche zur Anzeige von Daten und Verwaltung der Wetterstation
   c. Integration von InfluxDB zur Speicherung und Verwaltung von Wetterdaten
   d. Integration von Grafana zur Datenvisualisierung und Analyse
   e. Implementierung einer Alarmierungsfunktion für bestimmte Wetter

6. **OTA (Over-the-Air)-Funktionalität:**
   - Implementierung von OTA-Updates für die Firmware der Wetterstation

7. **Integration in Hausautomatisierungssysteme:**
   a. Integration in ioBroker
   b. Integration in Home Assistant

### Status

| Status       | Priority | Task                                              | Description (English)                                            | Beschreibung (Deutsch)                                          | Complexity |
|--------------|----------|---------------------------------------------------|------------------------------------------------------------------|----------------------------------------------------------------|------------|
| [x]          | 1        | BME280 Sensor Communication                      | Integration of BME280 sensor communication (completed)           | Integration der BME280-Sensor-Kommunikation (abgeschlossen)   | Medium     |
| [x]          | 2        | LyraP-LCD32 Display Integration                  | Integration of the display on the LyraP-LCD32 (completed)        | Integration der Anzeige auf dem LyraP-LCD32 (abgeschlossen)    | Medium     |
| [x]          | 3        | MQTT Communication                                | Implementation of MQTT communication (completed)                  | Implementierung von MQTT-Kommunikation (abgeschlossen)         | Medium     |
| [x]          | 4        | Deep Sleep and Wake-Up                            | Implementation of Deep Sleep and Wake-Up for energy efficiency (partially completed) | Implementierung von Deep Sleep und Wake-Up für Energieeffizienz (teilweise abgeschlossen) | Medium     |
| [x]          | 5        | Display Optimization                              | Optimization of the display (partially completed)                          | Optimierung der Anzeige (teilweise abgeschlossen)                       | Medium     |
| [x]          | 6        | Firmware Merge for ESP32-Saola-1 and ESP32-Kaluga-1 | Merging the firmware for ESP32-Saola-1 and ESP32-Kaluga-1 (completed) | Zusammenführung der Firmware für ESP32-Saola-1 und ESP32-Kaluga-1 (abgeschlossen) | High       |
| [-]          | 7        | Web App on ESP32                                  | Minimalistic web app on ESP32 for live data and configuration (not started) | Minimalistische Webanwendung auf dem ESP32 für Live-Daten und Konfiguration (nicht begonnen) | Medium     |
| [ ]          | 8        | API Development                                   | Development of an API (not started)                               | Entwicklung einer API (nicht begonnen)                          | Medium     |
| [ ]          | 9        | Server-based Web App (Raspberry Pi example)       | Server-based web app with Docker integration (not started)        | Serverbasierte Webanwendung mit Docker-Integration (nicht begonnen) | High       |
| [ ]          | 10       | OTA Updates                                       | Over-the-Air (OTA) updates (not started)                           | Over-the-Air (OTA) Updates (nicht begonnen)                    | Medium     |
| [ ]          | 11       | Additional Sensors Integration                   | Integration of additional sensors (not started)                    | Integration zusätzlicher Sensoren (nicht begonnen)             | High       |
| [ ]          | 12       | Integration into Home Automation Systems          | Integration into ioBroker and Home Assistant (not started)        | Integration in ioBroker und Home Assistant (nicht begonnen)    | Medium     |
