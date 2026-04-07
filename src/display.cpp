#include "display.h"

const char*  STARTUP_TEXT = "Morse Sys - FLP";

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

void centerAndDisplayText(const char* word) {
    int word_length = strlen(word);
    int center_cursor = (LCD_COLUMNS - word_length) / 2;
    lcd.setCursor(center_cursor, 0);
    lcd.print(word);
}

void setupDisplay() {
    lcd.init();
    lcd.backlight();
    lcd.clear();
    centerAndDisplayText(STARTUP_TEXT);
    delay(1500);
}

void displayText(const char*  word) {
    centerAndDisplayText(word);
}
