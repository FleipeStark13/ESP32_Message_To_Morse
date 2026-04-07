#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <Arduino.h>
#include "config.h"

void sendDash();
void sendDot();
void processChar(char c);
void translator(const char* word);

#endif