// Below layout is based upon /u/That-Canadian's planck layout
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

enum custom_keycodes {
  NEATO = SAFE_RANGE,
  COOLIO,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NEATO:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("Neat.");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case COOLIO:
      if (record->event.pressed) {
        SEND_STRING("Heck yea, spacecat.design!");
      }
      break;
  }
  return true;
};



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
    KC_VOLU, KC_MNXT, \
    MO(_FUNC), MO(_FUNC),  \
    KC_VOLD, KC_MPRV \
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
    NEATO,    COOLIO \
)

};

void matrix_init_user(void) {
    
}
