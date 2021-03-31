#include QMK_KEYBOARD_H
#include "oxinai.h"

#define RGB_STA RGB_M_P //rgb static
#define RGB_BRE RGB_M_B //rgb breathe
#define RGB_RAI RGB_M_R //rgb rainbow
#define RGB_SWI RGB_M_SW //rgb swirl
#define RGB_SNA RGB_M_SN //rgb snake
#define RGB_KNI RGB_M_K //rgb knight
#define RGB_GRA RGB_M_G //rgb gradient

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   /* Keymap: (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
   * |-----------------------------------------------------------|
   * |CAPS/MO|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |Alt |Gui |MO  |Ctrl |
   * `-----------------------------------------------------------'
   */
    [_QWERTY] = LAYOUT_60_tsangan_hhkb(
        KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_GRV, KC_BSPC,
        KC_TAB,     KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,  KC_BSLS,
        KC_FUNC,       KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,      KC_ENT,
        KC_LSFT,         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_FUNC,
        KC_LCTL,   KC_LGUI,  KC_LALT,                   KC_SPC,                 KC_RALT, KC_RGUI, KC_LGUI),

    /* Keymap : Second Layer (WASD and Media)
   * ,-----------------------------------------------------------.
   * |ESC| F1| F2| F3  |   |   |   |   |   |   |   |   |   | DEL |
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
   * |-----------------------------------------------------------|
   * |      |   |   |   |   |   |   |   |   |   |   |   |        |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
    [_FUNC] = LAYOUT_60_tsangan_hhkb(
        KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_LGUI, KC_DEL,
        _______,     KC_PGUP, KC_UP, KC_PGDN, KC_HOME, KC_INS, _______, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG, _______, RESET,
        XXXXXXX,       KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_DEL, _______, _______, _______, _______, _______, VRSN,      _______,
        _______,         KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, KC_UP, _______,
        _______,   _______,  _______,      _______, KC_LEFT, KC_DOWN, KC_RGHT),

   /* Keymap : Third Layer (RGB / Reset)
   * ,-----------------------------------------------------------.
   * | ` |   |   |   |   |   |   |   |   |   |   |   |   |       |
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
   * |-----------------------------------------------------------|
   * |      |   |   |   |   |   |   |       |   |   |   |        |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
    [_RGB] = LAYOUT_60_tsangan_hhkb(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,     RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______,
        KC_CAPS,       RGB_STA, RGB_BRE, RGB_RAI, RGB_SWI, RGB_SNA, RGB_KNI, RGB_GRA, _______, _______, _______, _______,     _______,
        _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______,   _______,  _______,      _______,  _______, _______,   _______),

};
/*
void led_set_user(uint8_t usb_led) {
    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        DDRB |= (1 << 2); PORTB &= ~(1 << 2);
    } else {
        DDRB &= ~(1 << 2); PORTB &= ~(1 << 2);
    }
};
*/
uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
        case _QWERTY:
            rgblight_setrgb(0xff, 0x40, 0x40);
            break;
        case _FUNC:
            rgblight_setrgb(0x39, 0x5f, 0x75);
            break;
        case _RGB:
            rgblight_setrgb(0xf6, 0xea, 0xe8);
            break;
        default:
            rgblight_setrgb(0xff, 0xff, 0xff);
            break;
    }
    return state;
};
