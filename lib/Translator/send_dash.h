#ifndef SEND_DASH_H
#define SEND_DASH_H

#include <Arduino.h>
#include <config.h>

#define MAIN_TONE 1200

void send_dash() {
        delay(DASH_DELAY);
        tone(WIRE, MAIN_TONE);
        delay(DASH_DELAY);
        noTone(WIRE);
}

#endif