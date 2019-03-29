#include QMK_KEYBOARD_H
#include "oxinai.h"
#include "quantum_keycodes.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
//#include "vim.h"

#define VERSION_STRING QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION
#define _______ KC_TRNS
#define X_____X KC_TRNS
#define KC_ATM LGUI(LSFT(KC_P))
#define KC_ATP LGUI(LCTL(KC_P))
#define TO_NORM TO(VIM)
#define FN_BKSP LT(SYMB, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |  Bksp  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  L1  |           | Vim  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |;/MDIA|  LGui  |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  |-/SYMB|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |AltApp| LGui |       |AltEsc| Ctrl |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 |Space | Bksp |------|       |------|  Del   |Enter |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_EQL,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_LEFT,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   TG(SYMB),
        FN_BKSP,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        CTL_T(KC_Z),  KC_X,   KC_C,   KC_V,   KC_B,   ALL_T(KC_NO),
        LT(SYMB,KC_GRV),KC_QUOT,      LALT(KC_LSFT),  KC_LEFT,KC_RGHT,
                                              ALT_T(KC_APP),  KC_LGUI,
                                                              KC_HOME,
                                               KC_SPC,KC_BSPC,KC_END,
        // right hand
             KC_RGHT,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,               KC_BSPC,
             TG(MDIA),       KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_BSLS,
                          KC_H,   KC_J,   KC_K,   KC_L,   LT(MDIA, KC_SCLN),KC_LGUI,
             MEH_T(KC_NO),KC_N,   KC_M,   KC_COMM,KC_DOT, CTL_T(KC_SLSH),   KC_RSFT,
                                  KC_UP,  KC_DOWN,KC_LBRC,KC_RBRC,          LT(SYMB, KC_MINS),
             KC_GESC,KC_LCTL,
             KC_PGUP,
             KC_PGDN,KC_DELT, KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           | RESET|  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 _
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_PGUP,KC_UP,  KC_PGDN,KC_HOME,KC_INS, KC_TRNS,
       KC_TRNS,KC_LEFT,KC_DOWN,KC_RGHT,KC_END, KC_DEL,
       KC_TRNS,KC_MPLY,KC_MPRV,KC_MNXT,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       RESET,   KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |  M4  |  M5  |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_BTN4, KC_BTN5, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
), */
/* Normal mode
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  TAB   |      | WORD |  END |      |      |      |           |      | YANK | UNDO |      | OPEN |  PUT |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |    ⎋   |      |      |  DEL |      |      |------|           |------|  ←   |  ↓   |  ↑   |  →   |      |    ⎋   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | SHIFT  |      |      |      |VISUAL| BACK |      |           |      |      |      |      |      |      | SHIFT  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |SPACE |DELETE|------|       |------|ENTER |BACKSP|
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// VIM Normal Mode
//[VIM] = LAYOUT_ergodox(
//    // Layer 2 Left Hand
//    X_____X,X_____X,X_____X,X_____X,X_____X,X_____X,X_____X,
//    KC_TAB ,X_____X,VIM_W,  VIM_E  ,X_____X,X_____X,X_____X,
//    X_____X,VIM_A  ,VIM_S  ,VIM_D  ,X_____X,X_____X,
//    KC_LSFT,X_____X,VIM_X  ,VIM_C  ,VIM_V  ,VIM_B  ,X_____X,
//    KC_LCTL,KC_LALT,X_____X,X_____X,X_____X,
//
//                                            KC_HOME,KC_END ,
//                                            TO(SYMB),
//                                            GUI_T(KC_SPC),  KC_ESC ,_______,
//
//
//    // Layer 2 Right Hand
//                              X_____X,X_____X,X_____X,X_____X,X_____X,X_____X,X_____X,
//                              X_____X,VIM_Y  ,VIM_U  ,VIM_I  ,VIM_O  ,VIM_P  ,X_____X,
//                                      VIM_H  ,VIM_J  ,VIM_K  ,VIM_L  ,X_____X,X_____X,
//                              X_____X,X_____X,X_____X,X_____X,X_____X,X_____X,KC_LSFT,
//                                              X_____X,X_____X,X_____X,KC_RALT,KC_RCTL,
//
//    KC_PGUP,  KC_PGDN,
//    TO(SYMB),
//    KC_DEL , KC_ENT, GUI_T(KC_BSPC)
//
//),
[MDIA] = LAYOUT_ergodox(
    // Layer 2 Left Hand
    X_____X,X_____X,X_____X,X_____X,X_____X,X_____X,X_____X,
    KC_TAB ,LSFT(LALT(KC_A)),X_____X,LSFT(LALT(KC_D)),X_____X,X_____X,X_____X,
    X_____X, LCTL(KC_LEFT),X_____X,LCTL(KC_RGHT),X_____X,X_____X,
    KC_LSFT,LSFT(LGUI(KC_A)),X_____X,LSFT(LGUI(KC_D)),X_____X,X_____X,X_____X,
    KC_LCTL,KC_LALT,X_____X,X_____X,X_____X,

                                            KC_HOME,KC_END ,
                                            TO(SYMB),
                                            GUI_T(KC_SPC),  KC_ESC ,_______,


    // Layer 2 Right Hand
                              X_____X,X_____X,X_____X,X_____X,X_____X,X_____X,X_____X,
                              X_____X,X_____X,X_____X,X_____X,X_____X,X_____X,X_____X,
                                      X_____X,X_____X,X_____X,X_____X,X_____X,X_____X,
                              X_____X,X_____X,X_____X,X_____X,X_____X,X_____X,KC_LSFT,
                                              X_____X,X_____X,X_____X,KC_RALT,KC_RCTL,

    KC_PGUP,  KC_PGDN,
    TO(SYMB),
    KC_DEL , KC_ENT, GUI_T(KC_BSPC)

),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
      }
      break;
  }
  return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    // TODO: Make this relevant to the ErgoDox EZ.
    case SYMB:
      ergodox_right_led_1_on();
      break;
    case MDIA:
      ergodox_right_led_2_on();
      break;
    case VIM:
      ergodox_right_led_3_on();
      break;
    default:
      // none
      break;
  }

};
