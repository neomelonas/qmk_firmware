#include QMK_KEYBOARD_H
#include "oxinai.h"

// Curly braces have their own keys. These are defined to make them not mess up
// the grid in layer 2.
#define L_CURBR LSFT(KC_LBRC)
#define R_CURBR LSFT(KC_RBRC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( /* Qwerty */
    KC_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    FN_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MO(_MODS),
    KC_LCTL, KC_LGUI, KC_LALT,                   KC_ENT,  KC_SPC,                    KC_RALT, KC_RSFT, MO_GAME
  ),
  [_FUNC] = LAYOUT( /* LAYER 1 */
    KC_GRV,  KC_PGUP, KC_UP,   KC_PGDN, KC_HOME, KC_INS,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    _______, KC_BSLS, KC_QUOT, KC_MINS, KC_END,  KC_DEL,  KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_RBRC, _______,
    _______, KC_MPLY,  KC_MPRV, KC_MNXT, _______, _______, _______, KC_MUTE,KC_VOLD, KC_VOLU, _______, _______,
    _______, _______, _______,                _______, _______,                   _______, _______,    _______
  ),
  [_MODS] = LAYOUT( /* LAYER 2 */
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    KC_ESC,  KC_BSLS, KC_QUOT, KC_MINS, KC_EQL,  KC_LBRC, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_RBRC, KC_ENT,
    _______, _______, _______, KC_PSCR, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_VOLD, _______,
    _______, _______, _______,                   _______, _______,                   _______, _______, _______
  ),
  [_GAMEPAD] = LAYOUT( /* LAYER 3 */
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_1,    KC_2,    KC_3,    KC_4,   KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_F9,   KC_F10,  KC_F11,  KC_F12, _______,
    _______, KC_LGUI, KC_LALT,                   KC_SPC,  KC_C,                      _______, KC_M,   MO_GAME
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

uint32_t layer_state_set_keymap(uint32_t state) {
    switch (biton32(state)) {
        case _FUNC:
            rgblight_setrgb (0x19, 0xE5, 0x44);
            break;
        case _MODS:
            rgblight_setrgb (0xD5, 0x4D, 0x29);
            break;
        case _GAMEPAD:
            rgblight_setrgb (0xFF, 0xFF, 0xFF);
            break;
        default:
            rgblight_setrgb (0x7A,  0x00, 0xFF);
            break;
    }
    return state;
};
