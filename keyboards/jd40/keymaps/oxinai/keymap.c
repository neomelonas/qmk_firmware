#include "jd40.h"
#include "action_layer.h"

#define FN_TAB LT(_AL2, KC_TAB)

enum layers {
    _BL = 0,
    _AL1,
    _AL2,
};
enum keycodes {
    TD_Q,
    TD_W,
    TD_E,
    TD_R,
    TD_T,
    TD_Y,
    TD_U,
    TD_I,
    TD_O,
    TD_P,
    TD_L,
    TD_ENT,

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BL] = KEYMAP_OXINAI(
        KC_GESC, TD(TD_Q),TD(TD_W),TD(TD_E),TD(TD_R),TD(TD_T),TD(TD_Y),TD(TD_U),TD(TD_I),TD(TD_O),TD(TD_P),KC_BSPC,
        FN_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    TD(TD_L),    TD(TD_ENT),
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  TG(_AL2),  TG(_AL1)
    ),
    [_AL1] = KEYMAP_OXINAI(
        KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, F6, KC_F7, KC_F8, KC_F9, KC_EQL, KC_DEL,
        KC_CAPS, KC_4, KC_5, KC_6, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SCLN, KC_QUOT, KC_PSCR,
        KC_TRNS, KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_SLSH, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_AL2] = KEYMAP_OXINAI(
        KC_GRV, KC_PGUP, KC_UP, KC_PGDN, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_DEL,
        KC_CAPS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR,
        KC_TRNS, KC_MPLY, KC_MPRV, KC_MNXT, BL_TOGG, BL_DEC, BL_INC, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS, RESET
    ),

};


qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_Q] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_1),
    [TD_W] = ACTION_TAP_DANCE_DOUBLE(KC_W, KC_2),
    [TD_E] = ACTION_TAP_DANCE_DOUBLE(KC_E, KC_3),
    [TD_R] = ACTION_TAP_DANCE_DOUBLE(KC_R, KC_4),
    [TD_T] = ACTION_TAP_DANCE_DOUBLE(KC_T, KC_5),
    [TD_Y] = ACTION_TAP_DANCE_DOUBLE(KC_Y, KC_6),
    [TD_U] = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_7),
    [TD_I] = ACTION_TAP_DANCE_DOUBLE(KC_I, KC_8),
    [TD_O] = ACTION_TAP_DANCE_DOUBLE(KC_O, KC_9),
    [TD_P] = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_0),
    [TD_L] = ACTION_TAP_DANCE_DOUBLE(KC_L, KC_QUOT),
    [TD_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_ENT),

};

const uint16_t PROGMEM fn_actions[] = {
    [0]  = ACTION_LAYER_MOMENTARY(1),  // Momentary Fn overlay
    [1]  = ACTION_LAYER_MOMENTARY(2),  // Momentary Fn overlay
};
