# Roadmap

## English

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

3. **Kaluga board integration:**
   - Support for reading and processing sensor data on the Kaluga board
   - Display weather data on the included Kaluga display

4. **OTA (Over-the-Air) functionality:**
   - Select an OTA library compatible with the project
   - Implement OTA functionality in the firmware
   - Consider security aspects (encrypted connections, authentication)
   - Integrate OTA functionality into the web application
   - Test and debug OTA functionality

## Deutsch

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

3. **Integration des Kaluga-Boards:**
   - Unterstützung für das Lesen und Verarbeiten von Sensordaten auf dem Kaluga-Board
   - Anzeige der Wetterdaten auf dem im Lieferumfang enthaltenen Kaluga-Display

4. **OTA (Over-the-Air)-Funktionalität:**
   - Auswahl einer mit dem Projekt kompatiblen OTA-Bibliothek
   - Implementierung der OTA-Funktionalität in der Firmware
   - Berücksichtigung von Sicherheitsaspekten (verschlüsselte Verbindungen, Authentifizierung)
   - Integration der OTA-Funktionalität in die Webanwendung
   - Testen und Debuggen der OTA-Funktionalität


| Status       | Priority | Task                                              | Description (English)                                             | Beschreibung (Deutsch)                                          | Complexity |
|--------------|----------|---------------------------------------------------|-------------------------------------------------------------------|----------------------------------------------------------------|------------|
| [x]          | 1        | BME280 Sensor Communication                      | Integration of BME280 sensor communication (completed)            | Integration der BME280-Sensor-Kommunikation (abgeschlossen)   | Medium     |
| [x]          | 2        | LyraP-LCD32 Display Integration                  | Integration of the display on the LyraP-LCD32 (completed)         | Integration der Anzeige auf dem LyraP-LCD32 (abgeschlossen)    | Medium     |
| [x]          | 3        | MQTT Communication                                | Implementation of MQTT communication (completed)                   | Implementierung von MQTT-Kommunikation (abgeschlossen)         | Medium     |
| [x]          | 4        | Deep Sleep and Wake-Up                            | Implementation of Deep Sleep and Wake-Up for energy efficiency (partially completed) | Implementierung von Deep Sleep und Wake-Up für Energieeffizienz (teilweise abgeschlossen) | Medium     |
| [x]          | 5        | Display Optimization                              | Optimization of the display (partially completed)                          | Optimierung der Anzeige (teilweise abgeschlossen)                       | Medium     |
| [x]          | 6        | Firmware Merge for ESP32-Saola-1 and ESP32-Kaluga-1 | Merging the firmware for ESP32-Saola-1 and ESP32-Kaluga-1 (completed) | Zusammenführung der Firmware für ESP32-Saola-1 und ESP32-Kaluga-1 (abgeschlossen) | High       |
| [ ]          | 7        | OTA Updates                                       | Over-the-Air (OTA) updates (not started)                           | Over-the-Air (OTA) Updates (nicht begonnen)                    | Medium     |
| [ ]          | 8        | Additional Sensors Integration                   | Integration of additional sensors (not started)                    | Integration zusätzlicher Sensoren (nicht begonnen)             | High       |
| [ ]          | 9        | Web App Development                               | Development of a web app for visualization and control (not started) | Entwicklung einer Web-App zur Visualisierung und Steuerung (nicht begonnen) | High       |
