#ifndef SEND_DOT_H
#define SEND_DOT_H

#include <Arduino.h>
#include <config.h>

#define MAIN_TONE 2500

void send_dot() {
    delay(DOT_DELAY);
    tone(WIRE, MAIN_TONE);
    delay(DOT_DELAY);
    noTone(WIRE);
}

#endif