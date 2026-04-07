#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <Arduino.h>
#include <send_dash.h>
#include <send_dot.h>

const char* MORSE_ALPHABET[] = {
    ".-",       // A
    "-...",     // B
    "-.-.",     // C
    "-..",      // D
    ".",        // E
    "..-.",     // F
    "--.",      // G
    "....",     // H
    "..",       // I
    ".---",     // J
    "-.-",      // K
    ".-..",     // L
    "--",       // M
    "-.",       // N
    "---",      // O
    ".--.",     // P
    "--.-",     // Q
    ".-.",      // R
    "...",      // S
    "-",        // T
    "--.",      // U
    "...-",     // V
    ".--",      // W
    "-..-",     // X
    "-.--",     // Y
    "--..",      // ZZ
};

void processChar(char c) {
    c = toupper(c);

    if (c >= 'A' && c <= 'Z') {
        int index = c - 'A';
        const char* morseCode = MORSE_ALPHABET[index];

        for (int i = 0; morseCode[i] != '\0'; i++) {
            if (morseCode[i] == '.') {
                send_dot();
            } else if (morseCode[i] == '-') {
                send_dash();
            }
            delay(CHAR_SPACE);
        }
    } else if (c == ' ') {
        delay(SPACE_TIME);
    } 
}

void translator(const char* word) {
    for (int i = 0; word[i] != '\0'; i++) {
        processChar(word[i]);
    }
}



#endif