#include <Wire.h>
#include <Arduino.h>
#include "config.h"
#include "translator.h"

void setup() {
  pinMode(WIRE, OUTPUT);
}

void loop() {
  translator("Hello, world!");
}

