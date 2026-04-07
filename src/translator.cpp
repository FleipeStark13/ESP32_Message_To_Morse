#include "translator.h"
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

void sendDash() {
    tone(WIRE, 1200);
    delay(DASH_DELAY);
    noTone(WIRE);
    delay(CHAR_SPACE);
}

void sendDot() {
    tone(WIRE, 2500);
    delay(DOT_DELAY);
    noTone(WIRE);
    delay(CHAR_SPACE);
}

void processChar(char c) {
    c = toupper(c);

    if (c >= 'A' && c <= 'Z') {
        int index = c - 'A';
        const char* morseCode = MORSE_ALPHABET[index];

        for (int i = 0; morseCode[i] != '\0'; i++) {
            if (morseCode[i] == '.') {
                sendDot();
            } else if (morseCode[i] == '-') {
                sendDash();
            }
            delay(CHAR_SPACE);
        }
    } else if (c == ' ') {
        delay(SPACE_TIME);
    } 
}

void translator(String word) {
    for (int i = 0; word[i] != '\0'; i++) {
        processChar(word[i]);
    }
}


