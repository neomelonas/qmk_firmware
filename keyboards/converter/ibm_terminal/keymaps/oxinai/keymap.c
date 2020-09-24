#include QMK_KEYBOARD_H
#include "oxinai.h"

#define KC_FINS LT(_FUNC, KC_INS)
#define KC_FKHM RCTL(KC_RGUI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* qwerty */
    [_QWERTY] = LAYOUT(
                                   KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,
                                   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,

    LOCKITW, SYS_ESC,     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX, KC_BSPC,     KC_FINS, KC_HOME, KC_PGUP,     KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
    KC_VOLU, KC_MNXT,     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          XXXXXXX,     KC_DEL,  KC_END,  KC_PGDN,     KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
    KC_VOLD, KC_MPRV,     FN_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_BSLS, KC_ENT,               KC_UP,                KC_P4,   KC_P5,   KC_P6,   KC_PCMM,
    KC_MUTE, KC_MPLY,     KC_LSFT, KC_LGUI, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          XXXXXXX, KC_RSFT,     KC_LEFT, KC_FKHM, KC_RGHT,     KC_P1,   KC_P2,   KC_P3,   KC_PENT,
    OSL(_SYSTEM), KC_NO,  KC_LCTL,          KC_LALT,                            KC_SPC,                                               KC_RALT,          CTRLENT,              KC_DOWN,              XXXXXXX, KC_P0,   KC_PDOT, XXXXXXX
    ),

    /* colemak */
    [_COLEMAK] = LAYOUT(
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

    _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  _______, _______,     _______, _______, _______,     _______, _______, _______, _______,
    _______, _______,     _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC,          _______,     _______, _______,  _______,     _______, _______, _______, _______,
    _______, _______,     _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,          _______, _______,              _______,              _______, _______, _______, _______,
    _______, _______,     _______, _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          _______, _______,     _______, _______, _______,     _______, _______, _______, _______,
    _______, _______,     _______,          _______,                            _______,                                              _______,          _______,              _______,              _______, _______, _______, _______
    ),

    /* workman */
    [_WORKMAN] = LAYOUT(
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

    _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  _______, _______,     _______, _______, _______,     _______, _______, _______, _______,
    _______, _______,     _______, KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_LBRC, KC_RBRC,          _______,     _______, _______, _______,     _______, _______, _______, _______,
    _______, _______,     _______, KC_A,    KC_S,    KC_H,    KC_T,    KC_G,    KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_QUOT,          _______, _______,              _______,              _______, _______, _______, _______,
    _______, _______,     _______, _______, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH,          _______, _______,     _______, _______, _______,     _______, _______, _______, _______,
    _______, _______,     _______,          _______,                            _______,                                              _______,          _______,              _______,              _______, _______, _______, _______
    ),

    /* dvorak */
    [_DVORAK] = LAYOUT(
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

    _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______,     _______, _______, _______,     _______, _______, _______, _______,
    _______, _______,     _______, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, KC_EQL,           _______,     _______, _______, _______,     _______, _______, _______, _______,
    _______, _______,     _______, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,          _______, _______,              _______,              _______, _______, _______, _______,
    _______, _______,     _______, _______, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,             _______, _______,     _______, _______, _______,     _______, _______, _______, _______,
    _______, _______,     _______,          _______,                            _______,                                              _______,          _______,              _______,              _______, _______, _______, _______
    ),

    /* system */
    [_SYSTEM] = LAYOUT(
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

    LOCKITW, KC_ESC,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,     _______, _______, _______, _______,
    LOCKITM, _______,     _______, LAY_QWE, OS_WIN,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,     _______, _______, _______,     _______, _______, _______, _______,
    _______, _______,     _______, _______, _______, LAY_DVO, _______, _______, _______, _______, LAY_WOR, OS_LIN,  _______, _______,          _______, _______,              _______,              _______, _______, _______, _______,
    _______, KC_SEC2,     _______, _______, _______, _______, LAY_COL, _______, _______, _______, OS_MAC,  _______, _______, _______,          _______, _______,     _______, _______, _______,     _______, _______, _______, _______,
    _______, KC_SEC1,     _______,          _______,                            _______,                                              _______,          _______,              _______,              _______, _______, _______, _______
    ),

    /* mouse keys */
    [_MOUSE] = LAYOUT(
                                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

    XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_BTN4,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,              KC_MS_U,              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_BTN5,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,     KC_MS_L, _______, KC_MS_R,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_BTN1, KC_BTN3,     KC_BTN2,          XXXXXXX,                            XXXXXXX,                                              XXXXXXX,          XXXXXXX,              KC_MS_D,              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    /* Standard 60% arrow layer, for muscle memory reasons. */
    [_FUNC] = LAYOUT(
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,

    _______, _______,     KC_GRV,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,     _______, _______, _______, _______,
    _______, _______,     _______, KC_PGUP, KC_UP,   KC_PGDN, KC_HOME, KC_INS,  KC_WH_U, _______, _______, _______, _______, _______, _______,          _______,     _______, KC_SPC,  _______,     _______, _______, _______, _______,
    _______, _______,     _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_DEL,  KC_WH_D, _______, _______, _______, _______, _______,          VRSN,    _______,              _______,               _______, _______, _______, _______,
    _______, KC_SEC3,     _______, _______, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______,          _______, _______,     KC_PGUP, _______, KC_PGDN,     _______, _______, _______, _______,
    _______, _______,      _______,          _______,                       _______,                                              _______,          _______,              _______,                  _______, _______, _______, _______
    ),
/*
    [XXX] = LAYOUT(
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

    _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,     _______, _______, _______, _______,
    _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,     _______, _______, _______,     _______, _______, _______, _______,
    _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,              _______,              _______, _______, _______, _______,
    _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,     _______, _______, _______,     _______, _______, _______, _______,
    _______, _______,     _______,          _______,                            _______,                                              _______,          _______,              _______,              _______, _______, _______, _______
    ),
    */
};
