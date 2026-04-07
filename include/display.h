#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "config.h"

void centerAndDisplayText(const char*  word);
void setupDisplay();
void displayText(const char* text);

#endif