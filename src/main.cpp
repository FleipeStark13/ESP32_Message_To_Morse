#include <Wire.h>
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

const int lcdColumns = 16;
const int lcdRows = 2;

LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

const int SPEED = 1;

#define dash  500 / SPEED
#define dot   150 / SPEED
#define wire  18
#define spaceTime 1000

void drawLcdLetter(char* letter) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(letter);
}

void space() {
  delay(spaceTime);
}

void send_dot(int times) {
  for (int i = 0; i < times; i++) {
    delay(dot);
    tone(wire, 2500);
    delay(dot);
    noTone(wire);
  }
}

void send_dash(int times) {
  for (int i = 0; i < times; i++) {
    delay(dash);
    tone(wire, 1200);
    delay(dash);
    noTone(wire);
  }
}

void morseLetter(char letter) {
  switch (letter) {
    case 'a':
      send_dot(1);
      send_dash(1);
      //drawLcdLetter(letter);
      break;
    
    case 'b':
      send_dash(1);
      send_dot(3);
      //drawLcdLetter(letter);
      break;

    case 'c':
      send_dash(1);
      send_dot(1);
      send_dash(1);
      send_dot(1);
      //drawLcdLetter(letter);
      break;
    case 'd':
      send_dash(1);
      send_dot(2);
      //drawLcdLetter(letter);
      break;
    case 'e':
      send_dot(1);
      //drawLcdLetter(letter);
      break;
    case 'f':
      send_dot(2);
      send_dash(1);
      send_dot(1);
      //drawLcdLetter(letter);
      break;
    case 'g':
      send_dash(2);
      send_dot(1);
      //drawLcdLetter(letter);
      break;
    case 'h':
      send_dot(4);
      //drawLcdLetter(letter);
      break;
    case 'i':
      send_dot(2);
      //drawLcdLetter(letter);
      break;
    case 'j':
      send_dot(1);
      send_dash(3);
      //drawLcdLetter(letter);
      break;
    case 'k':
      send_dash(1);
      send_dot(1);
      send_dash(1);
      //drawLcdLetter(letter);
      break;
    case 'l':
      send_dot(1);
      send_dash(1);
      send_dot(2);
      //drawLcdLetter(letter);
      break;
    case 'm':
      send_dash(2);
      //drawLcdLetter(letter);
      break;
    case 'n':
      send_dash(1);
      send_dot(1);
      //drawLcdLetter(letter);
      break;
    case 'o':
      send_dash(3);
      //drawLcdLetter(letter);
      break;
    case 'p':
      send_dot(1);
      send_dash(2);
      send_dot(1);
      //drawLcdLetter(letter);
      break;
    case 'q':
      send_dash(2);
      send_dot(1);
      send_dash(1);
      //drawLcdLetter(letter);
      break;
    case 'r':
      send_dot(1);
      send_dash(1);
      send_dot(1);
      //drawLcdLetter(letter);
      break;
    case 's':
      send_dot(1);
      send_dash(1);
      send_dot(1);
      //drawLcdLetter(letter);
      break;
    case 't':
      send_dash(1);
      //drawLcdLetter(letter);
      break;
    case 'u':
      send_dot(2);
      send_dash(1);
      //drawLcdLetter(letter);
      break;
    case 'v':
      send_dot(3);
      send_dash(1);
      //drawLcdLetter(letter);
      break;
    case 'w':
      send_dot(1);
      send_dash(2);
      //drawLcdLetter(letter);
      break;
    case 'x':
      send_dash(1);
      send_dot(2);
      send_dash(1);
      //drawLcdLetter(letter);
      break;    
    case 'y':
      send_dash(1);
      //drawLcdLetter(letter);
      break;
      send_dot(1);
      send_dash(2);
      //drawLcdLetter(letter);
      break;
    case 'z':
      send_dash(2);
      send_dot(2);  
      //drawLcdLetter(letter);
      break;
  }


}

void callWord(const char* word) {

  for (int i = 0; word[i] != '\0'; i++) {
    morseLetter(toLowerCase(word[i]));
    space();
  }

}


void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(wire, OUTPUT);
}

void loop() {
  //callWord("Hello, world");
  drawLcdLetter("Hello, world!");
}

