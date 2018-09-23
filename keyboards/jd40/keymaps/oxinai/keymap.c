#include "jd40.h"
#include "action_layer.h"

#define FN_TAB LT(_AL2, KC_TAB)

enum {
    _BL = 0,
    _AL1,
    _AL2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BL] = KEYMAP_OXINAI(
        KC_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_BSPC,
        FN_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  MO(_AL2),  MO(_AL1)
    ),
    [_AL1] = KEYMAP_OXINAI(
        KC_GRV, KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS, RESET, KC_TRNS, KC_TRNS, KC_MINS, KC_EQL, KC_DEL, 
        KC_CAPS, KC_4, KC_5, KC_6, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SCLN, KC_QUOT, KC_PSCR,
        KC_TRNS, KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_SLSH, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_AL2] = KEYMAP_OXINAI(
        KC_GRV, KC_PGUP, KC_UP, KC_PGDN, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_DEL,
        KC_CAPS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPRV, KC_MNXT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

};

const uint16_t PROGMEM fn_actions[] = {
    [0]  = ACTION_LAYER_MOMENTARY(1),  // Momentary Fn overlay
    [1]  = ACTION_LAYER_MOMENTARY(2),  // Momentary Fn overlay
};
