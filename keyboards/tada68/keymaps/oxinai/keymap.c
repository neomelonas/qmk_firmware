#include QMK_KEYBOARD_H
#include "oxinai.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,---------------------------------------------------------------.
   * |Esc| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp  |Hom|
   * |---------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |PgU|
   * |---------------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgD|
   * |---------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|End|
   * |---------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |Alt| FN|Ctrl|<- |Dow|-> |
   * `---------------------------------------------------------------'
   */
[_QWERTY] = LAYOUT_ansi(
  KC_GESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC,KC_GRV, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS,KC_DEL, \
  FN_CTRL, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,KC_PGUP,  \
  KC_LSFT,      KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   KC_RSFT, KC_UP, KC_PGDN, \
  KC_LCTL, KC_LGUI,KC_LALT,                KC_SPC,                        KC_RALT, KC_FUNC,  KC_RCTRL, KC_LEFT,KC_DOWN,KC_RGHT),

  /* Keymap _FL: Function Layer
   * ,---------------------------------------------------------------.
   * |   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Ins|
   * |---------------------------------------------------------------|
   * |     |PgU|Up |PgD|Hom|Ins|   |   |   |   |   |   |   |Reset|Del|
   * |---------------------------------------------------------------|
   * |      |<- |Dn | ->|End|Del|   |   |   |   |   |   |        |LMc|
   * |---------------------------------------------------------------|
   * |        |MPl|MPr|MNx|Bl-|BLT|BL+|Mut|VU-|VU+|   |   McL|MsU|McR|
   * |---------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |MsL|MsD|MsR|
   * `---------------------------------------------------------------'
   */
[_FUNC] = LAYOUT_ansi(
  KC_GRV, KC_F1 ,KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, MACRS,  \
  _______,KC_PGUP,KC_UP,  KC_PGDN, KC_HOME, KC_INS,_______,_______,_______,_______,_______,_______,_______,RESET,KC_INS, \
  _______,KC_LEFT,KC_DOWN,KC_RIGHT, KC_END, KC_DEL,_______,_______,_______,_______,_______,_______,        _______, KC_HOME, \
  _______,KC_MPLY,KC_MPRV,KC_MNXT,BL_DEC, BL_TOGG,BL_INC,KC_MUTE,KC_VOLD,KC_VOLU,_______,KC_BTN1, KC_MS_U, KC_END, \
  _______,_______,_______,                 _______,               _______,_______,KC_BTN2,KC_MS_L,KC_MS_D, KC_MS_R),

  /* Keymap _MACROS: Macro Layer
   * ,---------------------------------------------------------------.
   * |   |   |   |   |   |   |   |   |   |   |   |   |   |       |   |
   * |---------------------------------------------------------------|
   * |     |LoM|   |   |   |   |   |   |Se1|Se2|   |   |   |     |   |
   * |---------------------------------------------------------------|
   * |      |   |   |   |   |   |   |   |   |LoW|   |   |        |   |
   * |---------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |      |   |   |
   * |---------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |   |   |   |
   * `---------------------------------------------------------------'
   */
[_MACROS] = LAYOUT_ansi(
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
  _______,LOCKITM, KC_WPM,_______,_______,_______,_______,_______,KC_SEC1,KC_SEC2,_______,_______,_______,_______,_______, \
  KC_CAPS, _______,_______,_______,_______,_______,_______,_______,_______,LOCKITW,_______,_______,   _______,    _______, \
    _______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______, _______, _______,_______, \
  _______,_______,_______,                      _______,                  _______,_______,_______,_______,_______,_______),
};
