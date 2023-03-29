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


| Status | Priority | Task                                              | Description (English)                                             | Beschreibung (Deutsch)                                          | Complexity |
|--------|----------|---------------------------------------------------|-------------------------------------------------------------------|----------------------------------------------------------------|------------|
| [x]    | 1        | Implement base sensors (Temperature, Humidity...) | Implement the basic sensors for the modular weather station.      | Implementierung der grundlegenden Sensoren für die modulare Wetterstation. | Medium     |
| [ ]    | 2        | OTA Updates                                       | Implement wireless updates to simplify software updating.         | Implementierung von drahtlosen Updates zur Vereinfachung der Softwareaktualisierung. | Medium     |
| [ ]    | 3        | Support for Kaluga and Display                    | Adapt the code for the ESP32-S2-Kaluga-1 and implement display functionality. | Anpassung des Codes für den ESP32-S2-Kaluga-1 und Implementierung der Displayfunktionalität. | High       |
| [ ]    | 4        | Implement additional sensors (Wind, Rain...)      | Implement more sensors for comprehensive data collection.         | Implementierung von weiteren Sensoren für eine umfassendere Datenerfassung. | High       |
| [ ]    | 5        | Web App for management and visualization          | Develop a web application for managing and displaying weather data. | Entwicklung einer Webanwendung zur Verwaltung und Anzeige der Wetterdaten. | High       |
| [ ]    | 6        | Energy efficiency and Deep Sleep                  | Optimize energy consumption through the implementation of Deep Sleep and other techniques. | Optimierung des Energieverbrauchs durch Implementierung von Deep Sleep und anderen Techniken. | Medium     |
