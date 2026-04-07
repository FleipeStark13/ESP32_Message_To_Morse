#ifndef CONFIG_H
#define CONFIG_H

// Main lcd settings.
// Width = 16, Height = 2
#define LCD_COLUMNS     16
#define LCD_ROWS        2

#define PLAY_SPEED      1 // The playback speed of each letter. 

// Each symbol had your own speed.
// Then we divide by the main SPEED.
#define DASH_DELAY      (500 / PLAY_SPEED)
#define DOT_DELAY       (150 / PLAY_SPEED)

#define SPACE_TIME      1000 // Space char time to separate each word.
#define CHAR_SPACE      50
#define WIRE            18 // Output Wire of Speaker

#endif