// Below layout is based upon /u/That-Canadian's planck layout
#include QMK_KEYBOARD_H
#include "oxinai.h"

#include "launchpad.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _FUNC 15

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))
#define LOCKITM LCTL(LGUI(KC_Q))
#define LOCKITW LGUI(KC_L)
#define CTLTAB LCTL(KC_TAB)
#define COMTAB LGUI(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-------------.
 * | MUTE | PLAY |
 * |------+------|
 * | VOL+ | NEXT |
 * |------+------|
 * |    _FUNC    |
 * |------+------|
 * | VOL- | PREV |
 * `-------------'
 */
[_QWERTY] = LAYOUT( \
    KC_MUTE, KC_MPLY, \
    KC_VOLD, KC_VOLU, \
    MO(_FUNC), MO(_FUNC),  \
    KC_MPRV, KC_MNXT \
),

/* Function
 * ,-------------.
 * |MACLCK|WINLCK|
 * |------+------|
 * |CMDTAB|ALTTAB|
 * |------+------|
 * |             |
 * |------+------|
 *|spacecat.design|
 * `-------------'
 */
[_FUNC] = LAYOUT( \
    LOCKITM,  LOCKITW, \
    COMTAB,   CTLTAB, \
    _______,  _______, \
    KC_SECRET_2, KC_SECRET_1 \
)

};
const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {100, 50, 10}; // Set the last one to 10ms for some speedy swirls
uint8_t prev = _QWERTY;
uint32_t desired = 7;

void matrix_init_user(void) {
    rgblight_mode(desired);
}

uint32_t layer_state_set_user(uint32_t state) {
    uint8_t layer = biton32(state);
    if (prev!=_FUNC) {
        switch (layer) {
            case _QWERTY:
                rgblight_mode(desired);
                break;
            case _FUNC:
                rgblight_mode(1);
                rgblight_setrgb(0,128,128);
                break;
        }
    } else {
      desired = rgblight_get_mode();
  }
  prev = layer;
  return state;
}
