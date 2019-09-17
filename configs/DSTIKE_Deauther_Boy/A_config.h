#ifndef config_h
#define config_h

// ===== DISPLAY LIBRARY ===== //
#include "SH1106Wire.h"
// =========================== //

// ===================== LED CONFIG ==================== //
#define NEOPIXEL_LED

#define LED_MODE_BRIGHTNESS 10 // brightness of LED modes 

#define LED_NEOPIXEL_NUM 1
#define LED_NEOPIXEL_PIN 15
#define LED_NEOPIXEL_MODE NEO_GRB + NEO_KHZ800

// ===================== DISPLAY CONFIG ==================== //
#define USE_DISPLAY true // default display setting

#define BUTTON_UP 10
#define BUTTON_DOWN 9
#define BUTTON_A 14
#define BUTTON_B 12

#define DEAUTHER_DISPLAY SH1106Wire display = SH1106Wire(0x3c, 5, 4); // for 1.3" OLED
// ========================================================= //

#endif
