#include <Wire.h>
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <translator.h>
#include <config.h>

LiquidCrystal_I2C lcd(0x27, LCD_COLUMNS, LCD_ROWS);
void drawLcdLetter(char* letter) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(letter);
}

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(WIRE, OUTPUT);
}

void loop() {
  translator("Hello, world!");
}

