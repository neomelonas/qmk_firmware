#include QMK_KEYBOARD_H
#include "oxinai.h"

enum TAP_DANCE {
  TD_PLAY = 0,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(KC_MS_BTN5)
};

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(0, 255, 0);
    rgblight_mode(1);
    //rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_MOOD);
}

