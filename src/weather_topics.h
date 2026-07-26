#ifndef WEATHER_TOPICS_H
#define WEATHER_TOPICS_H

// Gemeinsame Topic-Konstanten für Indoor- und Outdoor-Stationen

// Basis-Pfade
static constexpr const char* WEATHER_INDOOR_BASE  = "weather/indoor";
static constexpr const char* WEATHER_OUTDOOR_BASE = "weather/outdoor";

// Indoor-Topics
static constexpr const char* WEATHER_INDOOR_TEMPERATURE_TOPIC = "weather/indoor/temperature";
static constexpr const char* WEATHER_INDOOR_HUMIDITY_TOPIC    = "weather/indoor/humidity";
static constexpr const char* WEATHER_INDOOR_PRESSURE_TOPIC    = "weather/indoor/pressure";
static constexpr const char* WEATHER_INDOOR_ALTITUDE_TOPIC    = "weather/indoor/altitude";

// Outdoor-Topics
static constexpr const char* WEATHER_OUTDOOR_TEMPERATURE_TOPIC = "weather/outdoor/temperature";
static constexpr const char* WEATHER_OUTDOOR_HUMIDITY_TOPIC    = "weather/outdoor/humidity";
static constexpr const char* WEATHER_OUTDOOR_PRESSURE_TOPIC    = "weather/outdoor/pressure";

// OTA-Topics
static constexpr const char* WEATHER_OUTDOOR_OTA_TOPIC = "weather/outdoor/ota";

// Device-IDs für Home Assistant
static constexpr const char* WEATHER_INDOOR_DEVICE_ID  = "weather_indoor_station";
static constexpr const char* WEATHER_OUTDOOR_DEVICE_ID = "weather_outdoor_station";

#endif // WEATHER_TOPICS_H

