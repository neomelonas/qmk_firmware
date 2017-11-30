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
#define _QW 0
#define _CM 1
#define _DV 2
#define _LW 3
#define _RS 4
#define _NP 5
#define _GM 6

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
[_QW] = { /* Qwerty */
  {KC_GESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_LCTL, KC_LGUI, KC_LALT, MO(_GM), MO(_LW), KC_SPC,  KC_SPC,  MO(_RS), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},
[_CM] = { /* Colemak */
  {KC_GESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
  {KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_LCTL, KC_LGUI, KC_LALT, MO(_GM), MO(_LW), KC_SPC,  KC_SPC,  MO(_RS), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},
[_DV] = { /* Dvorak */
  {KC_GESC,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC},
  {KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH},
  {KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT },
  {KC_LCTL, KC_LGUI, KC_LALT, MO(_GM), MO(_LW), KC_SPC,  KC_SPC,  MO(_RS), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},
/* MIT Layout (Raised layer)
 *
 * ,-----------------------------------------------------------------------.
 * |     |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  | del |
 * |-----------------------------------------------------------------------|
 * |  `  | F1  | F2  | F3  | F4  | F5  | F6  |  -  |  =  |  [  |  ]  |  \  |
 * |-----------------------------------------------------------------------|
 * |     | F7  | F8  | F9  | F10 | F11 | F12 | _QW | _NP | _NP | RST |     |
 * |-----------------------------------------------------------------------|
 * |     |     |     |     |     |           |     | MNX | VDN | VUP | MPL |
 * `-----------------------------------------------------------------------'
 */
[_RS] = { /* RAISE */
  {KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL},
  {KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  DF(_QW), DF(_NP), DF(_GM), RESET,   KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},
/* MIT Layout (Lowered layer)
 *
 * ,-----------------------------------------------------------------------.
 * |     |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  |     |
 * |-----------------------------------------------------------------------|
 * |  ~  | F1  | F2  | F3  | F4  | F5  | F6  |  _  |  +  |  {  |  }  |  |  |
 * |-----------------------------------------------------------------------|
 * |rshft| F7  | F8  | F9  | F10 | F11 | F12 | _QW | _NP | _NP |     |     |
 * |-----------------------------------------------------------------------|
 * |blstp|     |     |     |     |           |     | MPV | VDN | VUP | MPL |
 * `-----------------------------------------------------------------------'
 */
[_LW] = { /* LOWER */
  {KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC},
  {KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE},
  {KC_RSFT, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  DF(_QW), DF(_NP), DF(_GM), RESET,   KC_TRNS},
  {BL_STEP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_VOLD, KC_VOLU, KC_MPLY}
},
/* MIT Layout (Numpad)
 *
 * ,-----------------------------------------------------------------------.
 * |     |  7  |  8  |  9  |  /  |  *  |     | Num |  7  |  8  |  9  | bspc|
 * |-----------------------------------------------------------------------|
 * | tab |  4  |  5  |  6  |  +  |  *  |     |  _  |  4  |  5  |  6  |  +  |
 * |-----------------------------------------------------------------------|
 * |     |  1  |  2  |  3  |  -  |  *  |     | _QW |  1  |  2  |  3  | Ent |
 * |-----------------------------------------------------------------------|
 * |     |     |     |     |     |           |     |  0  |  0  |  .  | Ent |
 * `-----------------------------------------------------------------------'
 */
[_NP] = { /* NUMPAD */
  {KC_TRNS, KC_P7,   KC_P8,   KC_P9,   KC_PSLS, KC_PAST, KC_TRNS, KC_NLCK, KC_P7,   KC_P8,   KC_P9,   KC_BSPC},
  {KC_TAB,  KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PAST, KC_TRNS, KC_PMNS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS},
  {KC_TRNS, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, KC_PAST, KC_TRNS, DF(_QW), KC_P1,   KC_P2,   KC_P3,   KC_PENT},
  {KC_TRNS, KC_P0,   KC_PDOT, KC_PENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0,   KC_P0,   KC_PDOT, KC_PENT}
},
/* MIT Layout (Games Layer)
 *
 * ,-----------------------------------------------------------------------.
 * |     |  m1 |  m2 |  m3 |  m4 |     |     |     |     |     |     |     |
 * |-----------------------------------------------------------------------|
 * |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----------------------------------------------------------------------|
 * |     |     |     |     |     |     |     | _QW | _NP |     |     |     |
 * |-----------------------------------------------------------------------|
 * |     |     |     |     |     |           |     |     |     |     |     |
 * `-----------------------------------------------------------------------'
 */
[_GM] = { /* GAME STUFF */
  {KC_TRNS, M(1),    M(2),    M(3),    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PMNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DF(_QW), DF(_NP), KC_TRNS, KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
}
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        break;
        case 1: // CS:GO Buy Bind - M4/AK
          return MACRODOWN( TYPE(KC_B), TYPE(KC_4), TYPE(KC_2), END );
        break;
        case 2: // CS:GO Buy Bind - P250
          return MACRODOWN( TYPE(KC_B), TYPE(KC_1), TYPE(KC_3), END );
        break;
        case 3: // CS:GO Buy Bind - AWP
          return MACRODOWN( TYPE(KC_B), TYPE(KC_4), TYPE(KC_5), END );
        break;
        case 4: // CS:GO Buy Bind - Armor/Helm
          return MACRODOWN( TYPE(KC_B), TYPE(KC_5), TYPE(KC_2), END );
        break;

      }
    return MACRO_NONE;
};

