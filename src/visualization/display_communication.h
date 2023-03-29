#pragma once

#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

void setupDisplay();
void displayData(float temperature, float humidity, float pressure);
