#include QMK_KEYBOARD_H
#include "oxinai.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
     KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
     LO_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
     OS_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
     OS_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_HOME,          KC_SPC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                    OS_LGUI, OLOW,        KC_SPC,             KC_ENT,       ORAI,    OS_LALT
  ),

  [_LOWER] = LAYOUT(
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
     _______, KC_PGUP, KC_UP,   KC_PGDN, KC_HOME, KC_INS,                             _______, _______, _______, _______, KC_LBRC, KC_RBRC,
     _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_DEL,                             _______, _______, _______, _______, _______, _______,
     _______, KC_MPLY, KC_MPRV, KC_MNXT, BL_DEC,  BL_TOGG, _______,          _______, BL_INC,  KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,
                                    _______, _______, _______,                   _______,OSL(_ADJUST),_______
  ),

  [_RAISE] = LAYOUT(
     KC_GESC, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, KC_MINS, KC_EQL,
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
                                    _______,OSL(_ADJUST),_______,                 _______, _______, _______
  ),

  [_ADJUST] = LAYOUT(
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, RESET,
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, TG_GAME,                            _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, KC_SEC3,          KC_SEC2, _______, _______, _______, _______, _______, _______,
                                    _______, _______, VRSN,                       _______, _______, _______
  ),

  [_GAMEPAD] = LAYOUT(
     KC_ESC,  KC_F1,   KC_1,    KC_2,    KC_3,    KC_4,                               _______, _______, _______, _______, _______, _______,
     KC_TAB,  KC_K,    KC_Q,    KC_W,    KC_E,    KC_R,                               _______, _______, _______, _______, _______, _______,
     KC_LSFT, KC_G,    KC_A,    KC_S,    KC_D,    KC_F,                               _______, _______, _______, _______, _______, _______,
     KC_LCTL, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    TG_GAME,           _______, _______, _______, _______, _______, _______, _______,
                                    LOWER,   KC_SPC, KC_SPC,                     _______, _______, _______
  )
};
