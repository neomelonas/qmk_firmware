#include QMK_KEYBOARD_H
#include "oxinai.h"

enum TAP_DANCE {
  TD_PLAY = 0,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(TD_PLAY)
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_PLAY] = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MNXT),
};

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(255, 255, 255);
    rgblight_mode(1);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_MOOD);
    //rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_MOOD);
}

