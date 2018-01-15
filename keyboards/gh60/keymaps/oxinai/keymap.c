#include "gh60.h"
#include "action_layer.h"

#define _BL 0
#define _AL 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /*
   *  Base layer, pretty standard ANSI layout.
   * ,-----------------------------------------------------------.
   * |F(12)| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
   * |-----------------------------------------------------------|
   * |Caps/Fn|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space             |Alt |Fn  |Menu|Ctrl|
   * `-----------------------------------------------------------'
   */
	[_BL] = KEYMAP(
        KC_GESC,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINS,KC_EQL,KC_BSPC, \
    	KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_LBRC,KC_RBRC,KC_BSLS, \
        MO(_AL),KC_A,KC_S,KC_D,KC_F,KC_G,KC_H,KC_J,KC_K,KC_L,KC_SCLN,KC_QUOT,KC_NO,KC_ENT,  \
        KC_LSFT,KC_NO,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_N,KC_M,KC_COMM,KC_DOT,KC_SLSH,KC_NO,KC_RSFT, \
        KC_LCTL,KC_LGUI,KC_LALT,        KC_SPC,      KC_NO,KC_RALT,KC_RGUI,MO(_AL),KC_RCTL),

   /*
   * Locking arrow keys to WASD for when you need dedicated arrow keys
   * ,-----------------------------------------------------------.
   * |    |  |   |   |   |   |   |   |   |   |   |   |   |  Del  |
   * |-----------------------------------------------------------|
   * |     |PgU|Up |PgD|Home|Ins|   |   |   |   |   |   |  |RESET|
   * |-----------------------------------------------------------|
   * |       |Left|Down|Rght|End|Del|   |   |   |   |   |   |    |
   * |-----------------------------------------------------------|
   * |        |Mute|-Vol|+Vol|BL\|BLStep|  |  |  |Play |  |      |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
	[_AL] = KEYMAP(
        KC_GRAVE,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_F12,KC_DEL, \
        KC_TRNS,KC_PGUP,KC_UP,KC_PGDN,KC_HOME,KC_INS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, \
        KC_TRNS,KC_LEFT,KC_DOWN,KC_RGHT,KC_END,KC_DEL,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, \
        KC_TRNS,KC_MUTE,KC_VOLD,KC_VOLU,BL_TOGG,BL_STEP,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_MPLY,KC_TRNS,KC_TRNS,   \
        KC_TRNS,KC_TRNS,KC_TRNS,          KC_TRNS,               KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS),


};

const uint16_t PROGMEM fn_actions[] = {
    [0]  = ACTION_LAYER_MOMENTARY(1),  // Momentary Fn overlay
};
