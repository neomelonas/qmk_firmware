#include "../../config.h"

/* WS2812B RGB Underglow LED */
#define RGB_DI_PIN F5   // See readme.md for wiring your led's
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 16         // Number of LEDs. Change this to match your use case.
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

#define QMK_ESC_OUTPUT F0 // usually COL
#define QMK_ESC_INPUT D0 // usually ROW
#define QMK_LED B6

