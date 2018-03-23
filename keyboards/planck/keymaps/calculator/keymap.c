// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
#include "eeconfig.h"
#ifdef BACKLIGHT_ENABLE
  #include "backlight.h"
#endif

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define CALC 0
#define FN 1

#define _______ KC_TRNS

#define MAC_NXT LT(KC_MFFD, KC_MNXT)
#define MAC_PRV LT(KC_MRWD, KC_MPRV)

enum custom_keycodes {
    DbZ = SAFE_RANGE
};

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
[CALC] = { /*Calculator*/
    {KC_LEFT, KC_P0,   KC_P1,   KC_P4,   KC_P7,   KC_NLCK, KC_ESC,  KC_HOME, KC_F9,   KC_F5,   KC_F1,   KC_MPLY},
    {KC_UP,   DbZ,     KC_P2,   KC_P5,   KC_P8,   KC_PSLS, KC_TAB,  KC_PGUP, KC_F10,  KC_F6,   KC_F2,   MAC_PRV},
    {KC_DOWN, KC_PDOT, KC_P3,   KC_P6,   KC_P9,   KC_PAST, KC_PEQL, KC_PGDN, KC_F11,  KC_F7,   KC_F3,   MAC_NXT},
    {KC_RGHT, KC_PENT, KC_PPLS, KC_PMNS, KC_BSPC, MO(1),   MO(1),   KC_END,  KC_F12,  KC_F8,   KC_F4,   KC_MUTE} },

[FN] = { /*Func*/
    {_______, _______, _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, KC_INS,  _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______} }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)  {
    switch(keycode) {
        case DbZ:
            SEND_STRING(SS_TAP(X_KP_0));
            return false;
            break;
    }
    return true;
};
