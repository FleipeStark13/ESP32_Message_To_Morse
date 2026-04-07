#include <Wire.h>
#include <Arduino.h>
#include "config.h"
#include "translator.h"
#include "display.h"

const char* display_text = "Hello, world!";

void setup() {
  setupDisplay();
  pinMode(WIRE, OUTPUT);
}

void loop() {
  translator(display_text);
}

