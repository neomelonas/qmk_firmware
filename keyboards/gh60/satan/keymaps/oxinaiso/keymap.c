#include QMK_KEYBOARD_H
#include "oxinai.h"

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define TAPPING_TOGGLE 2


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _QWERTY: (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|     |
   * |--------------------------------------------------------   |
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '| \ |   |
   * |-----------------------------------------------------------|
   * |Shift|sft|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift    |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |spc |Alt |FN  |Ctrl |
   * `-----------------------------------------------------------'
   */
[_QWERTY] = LAYOUT_60_iso(
  KC_GESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC,
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,
  FN_CTRL,    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,KC_BSLS,    KC_ENT,
  KC_LSFT, KC_NO, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,         KC_RSFT,
  KC_LCTL, KC_LGUI, KC_LALT,               KC_SPC,                             KC_NO,  KC_RALT, OSL(_MACROS), CTRLENT),

/* Keymap _FUNC: Function Layer
   * ,-----------------------------------------------------------.
   * | ~`|F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|  Del  |
   * |-----------------------------------------------------------|
   * |     |PUp| Up|PDn|Hom|Ins|   |   |   |   |   |   |   |     |
   * |-------------------------------------------------------    |
   * |       |Lft|Dn |Rgt|End|Del|   |   |   |   |   |   |   |   |
   * |-----------------------------------------------------------|
   * |    |   |Ply|Prv|Nxt|BLd|BLs|BLi|Mut|Vo-|Vo+|   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |Lay0|    |
   * `-----------------------------------------------------------'
   *
   */
[_FUNC] = LAYOUT_60_iso(
  KC_GRV,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,  KC_F12, KC_DEL,    //14
  _______,  KC_PGUP, KC_UP, KC_PGDN, KC_HOME, KC_INS, _______,  _______,  _______, _______, _______, _______, RESET,               //13
  _______,   KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_DEL, _______, _______, _______, _______, _______, _______, VRSN, _______,  //14
  _______,_______, KC_MPLY, KC_MPRV, KC_MNXT, BL_DEC, BL_STEP, BL_INC, KC_MUTE, KC_VOLD, KC_VOLU, _______,   _______,      //13
  _______, _______, _______,               _______,                             _______,  _______, _______, _______), //8


[_MACROS] = LAYOUT_60_iso(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   //14
  _______, QWERTY, OS_WIN, _______, _______, _______, _______,  _______,  KC_SEC1, KC_SEC2, _______, _______, _______,            //13
  _______,  _______, _______, _______, _______, _______, _______, _______, _______, OS_LIN, _______, _______, _______, _______,   //14
  _______,_______, _______, _______, _______, VRSN, BL_BRTG,  _______, OS_MAC, _______, _______, _______,   _______,              //13
  _______, _______, _______,               _______,                             _______,  _______, OSL(_FUNC), _______),             //8
};

