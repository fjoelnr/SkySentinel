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

8. **Enhanced data visualization:**
   - Implement more sophisticated graphics or animations for displaying weather data

9. **Data analysis and forecasting:**
   - Integrate machine learning or statistical models for recognizing patterns in weather data and predicting future weather conditions

10. **Alerts and notifications:**
   - Develop a notification system to inform users of extreme weather conditions or rapid changes in weather

11. **Energy efficiency:**
   - Optimize energy consumption of the weather station, e.g. by using solar panels or implementing energy-saving modes

12. **Remote access:**
   - Develop a web or smartphone app to allow users to access weather data from anywhere

13. **Expanded connectivity:**
   - Integrate other communication protocols or cloud platforms to improve interoperability and data transmission options

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
   e. Implementierung einer Alarmierungsfunktion für bestimmte Wetterbedingungen

6. **OTA (Over-the-Air)-Funktionalität:**
   - Implementierung von OTA-Updates für die Firmware der Wetterstation

7. **Integration in Hausautomatisierungssysteme:**
   a. Integration in ioBroker
   b. Integration in Home Assistant

8. **Erweiterte Datenvisualisierung:**
   - Implementierung von anspruchsvolleren Grafiken oder Animationen zur Anzeige von Wetterdaten

9. **Datenanalyse und Vorhersage:**
   - Integration von maschinellem Lernen oder statistischen Modellen zur Erkennung von Mustern in Wetterdaten und Vorhersage zukünftiger Wetterbedingungen

10. **Alarme und Benachrichtigungen:**
   - Entwicklung eines Benachrichtigungssystems, um Benutzer über extreme Wetterbedingungen oder schnelle Wetteränderungen zu informieren

11. **Energieeffizienz:**
   - Optimierung des Energieverbrauchs der Wetterstation, z. B. durch den Einsatz von Solarzellen oder die Implementierung von Energiesparmodi

12. **Fernzugriff:**
   - Entwicklung einer Web- oder Smartphone-App, die es Benutzern ermöglicht, von überall auf Wetterdaten zuzugreifen

13. **Erweiterte Konnektivität:**
   - Integration anderer Kommunikationsprotokolle oder Cloud-Plattformen zur Verbesserung der Interoperabilität und Datenübertragungsoptionen

### Status

| Status       | Priority | Task                                              | Description (English)                                            | Beschreibung (Deutsch)                                          | Complexity |
|--------------|----------|---------------------------------------------------|------------------------------------------------------------------|----------------------------------------------------------------|------------|
| [x]          | 1        | BME280 Sensor Communication                      | Integration of BME280 sensor communication (completed)           | Integration der BME280-Sensor-Kommunikation (abgeschlossen)   | Medium     |
| [x]          | 2        | LyraP-LCD32 Display Integration                  | Integration of the display on the LyraP-LCD32 (completed)        | Integration der Anzeige auf dem LyraP-LCD32 (abgeschlossen)    | Medium     |
| [x]          | 3        | MQTT Communication                                | Implementation of MQTT communication (completed)                  | Implementierung von MQTT-Kommunikation (abgeschlossen)         | Medium     |
| [x]          | 4        | Deep Sleep and Wake-Up                            | Implementation of Deep Sleep and Wake-Up for energy efficiency (partially completed) | Implementierung von Deep Sleep und Wake-Up für Energieeffizienz (teilweise abgeschlossen) | Medium     |
| [x]          | 5        | Display Optimization                              | Optimization of the display (partially completed)                          | Optimierung der Anzeige (teilweise abgeschlossen)                       | Medium     |
| [x]          | 6        | Firmware Merge for ESP32-Saola-1 and ESP32-Kaluga-1 | Merging the firmware for ESP32-Saola-1 and ESP32-Kaluga-1 (completed) | Zusammenführung der Firmware für ESP32-Saola-1 und ESP32-Kaluga-1 (abgeschlossen) | High       |
| [ ]          | 7        | Web App on ESP32                                  | Minimalistic web app on ESP32 for live data and configuration (not started) | Minimalistische Webanwendung auf dem ESP32 für Live-Daten und Konfiguration (nicht begonnen) | Medium     |
| [ ]          | 8        | API Development                                   | Development of an API (not started)                               | Entwicklung einer API (nicht begonnen)                          | Medium     |
| [ ]          | 9        | Server-based Web App (Raspberry Pi example)       | Server-based web app with Docker integration (not started)        | Serverbasierte Webanwendung mit Docker-Integration (nicht begonnen) | High       |
| [ ]          | 10       | OTA Updates                                       | Over-the-Air (OTA) updates (not started)                           | Over-the-Air (OTA) Updates (nicht begonnen)                    | Medium     |
| [ ]          | 11       | Additional Sensors Integration                   | Integration of additional sensors (not started)                    | Integration zusätzlicher Sensoren (nicht begonnen)             | High       |
| [ ]          | 12       | Integration into Home Automation Systems          | Integration into ioBroker and Home Assistant (not started)        | Integration in ioBroker und Home Assistant (nicht begonnen)    | Medium     |
| [ ]          | 13       | Enhanced Data Visualization                       | Implement more sophisticated graphics or animations for displaying weather data (not started) | Implementierung anspruchsvollerer Grafiken oder Animationen zur Anzeige von Wetterdaten (nicht begonnen) | Medium     |
| [ ]          | 14       | Data Analysis and Forecasting                     | Integrate machine learning or statistical models for recognizing patterns in weather data and predicting future weather conditions (not started) | Integration von maschinellem Lernen oder statistischen Modellen zur Erkennung von Mustern in Wetterdaten und Vorhersage zukünftiger Wetterbedingungen (nicht begonnen) | High       |
| [ ]          | 15       | Alerts and Notifications                          | Develop a notification system to inform users of extreme weather conditions or rapid changes in weather (not started) | Entwicklung eines Benachrichtigungssystems, um Benutzer über extreme Wetterbedingungen oder schnelle Wetteränderungen zu informieren (nicht begonnen) | Medium     |
| [ ]          | 16       | Energy Efficiency                                 | Optimize energy consumption of the weather station, e.g. by using solar panels or implementing energy-saving modes (not started) | Optimierung des Energieverbrauchs der Wetterstation, z. B. durch den Einsatz von Solarzellen oder die Implementierung von Energiesparmodi (nicht begonnen) | High       |
| [ ]          | 17       | Remote Access                                     | Develop a web or smartphone app to allow users to access weather data from anywhere (not started) | Entwicklung einer Web- oder Smartphone-App, die es Benutzern ermöglicht, von überall auf Wetterdaten zuzugreifen (nicht begonnen) | Medium     |
| [ ]          | 18       | Enhanced Connectivity                             | Integrate other communication protocols or cloud platforms to improve interoperability and data transmission options (not started) | Integration anderer Kommunikationsprotokolle oder Cloud-Plattformen zur Verbesserung der Interoperabilität und Datenübertragungsoptionen (nicht begonnen) | High       |



