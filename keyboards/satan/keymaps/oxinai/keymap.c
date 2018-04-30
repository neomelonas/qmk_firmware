#include "satan.h"
#include "action_layer.h"

// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1

#define TAPPING_TOGGLE 2

#define _______ KC_TRNS

#define FN_CAPS LT(_FL, KC_CAPSLOCK)
#define FN_MENU LT(_FL, KC_APP)
#define MAC_NXT LT(KC_MFFD, KC_MNXT)
#define MAC_PREV LT(KC_MRWD, KC_MPRV)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
   * |-----------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |Alt |Gui |FN  |Ctrl |
   * `-----------------------------------------------------------'
   */
[_BL] = KEYMAP_ANSI(
  KC_GESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS, \
  FN_CAPS,    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,  \
  KC_LSFT,       KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,         KC_RSFT, \
  KC_LCTL, KC_LGUI, KC_LALT,               KC_SPC,                             KC_RALT,  KC_RGUI, FN_MENU,KC_RCTL),

  /* Keymap _FL: Function Layer
   * ,-----------------------------------------------------------.
   * | ` |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|  Del  |
   * |-----------------------------------------------------------|
   * |     |PUp| Up|PDn|Hom|Ins|   |   |   |   |   |   |   |RESET|
   * |-----------------------------------------------------------|
   * |      |Lft|Dn |Rgt|End|Del|Lft|Dn | Up|Rgt|   |   |        |
   * |-----------------------------------------------------------|
   * |        |Mut|Vo-|Vo+|BLt|BLs|   |   |Ply|Prv|Nxt|          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |Lay0|    |
   * `-----------------------------------------------------------'
   */
[_FL] = KEYMAP_ANSI(
  KC_GRV,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_F12,KC_DEL, \
  _______,KC_PGUP,KC_UP, KC_PGDN,KC_HOME,KC_INS,_______,_______,_______,_______,_______,_______,_______,RESET, \
  _______,KC_LEFT,KC_DOWN,KC_RGHT,KC_END,KC_DEL,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,_______,_______,_______, \
  _______,KC_MUTE,KC_VOLD,KC_VOLU,BL_TOGG,BL_STEP,_______,_______,KC_MPLY,MAC_PREV,MAC_NXT,_______, \
  _______,_______,_______,                _______,                        _______,_______,DF(0),_______),
};

