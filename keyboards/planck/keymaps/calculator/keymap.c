// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.
#include QMK_KEYBOARD_H
#include "oxinai.h"
#ifdef BACKLIGHT_ENABLE
  #include "backlight.h"
#endif

extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* MIT Layout (QWERTY layer)
 *
 * ,-----------------------------------------------------------------------.
 * |esc`~|  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  | bspc|
 * |-----------------------------------------------------------------------|
 * | tab |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |
 * |-----------------------------------------------------------------------|
 * |shift|  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |enter|
 * |-----------------------------------------------------------------------|
 * | ctl | sup | alt | Mgm |lower|    spc    |raise| left| down|  up |right|
 * `-----------------------------------------------------------------------'
 */
[_CALC] = { /*Calculator*/
    {KC_P0,   KC_P1,   KC_P4,   KC_P7,   KC_LEFT, KC_NLCK, KC_ESC,  KC_HOME, KC_F9,   KC_F5,   KC_F1,   KC_MPLY},
    {DbZ,     KC_P2,   KC_P5,   KC_P8,   KC_UP,   KC_PSLS, KC_TAB,  KC_PGUP, KC_F10,  KC_F6,   KC_F2,   KC_MPRV},
    {KC_PDOT, KC_P3,   KC_P6,   KC_P9,   KC_DOWN, KC_PAST, KC_PEQL, KC_PGDN, KC_F11,  KC_F7,   KC_F3,   KC_MNXT},
    {KC_PENT, KC_PPLS, KC_PMNS, KC_BSPC, KC_RGHT, MO(_FUNC),MO(_FUNC),KC_END,  KC_F12,  KC_F8,   KC_F4,   KC_MUTE} },

[_FUNC] = { /*Func*/
    {_______, _______, _______, _______, _______, BL_TOGG, RESET,   _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, BL_DEC,  KC_INS,  _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, BL_INC,  KC_DEL,  _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______} }
};

