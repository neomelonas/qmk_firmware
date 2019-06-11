/* Copyright 2018 MechMerlin
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "oxinai.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_all(\
      KC_ESC,   KC_F2,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS, KC_DEL, KC_HOME,  KC_PGUP, KC_PGDN, KC_END,        //19
      KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,     KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_BSPC,KC_BSPC,  KC_NLCK,  KC_PGDN, KC_PSLS, KC_PAST,    //19
      KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS,             //18
      FN_CTRL,     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN, KC_QUOT,  KC_NO, KC_ENT,  KC_P4,   KC_P5,   KC_P6,   KC_PPLS,             //18
      KC_LSFT,  KC_NO,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT,  KC_UP,   KC_P1,   KC_P2,   KC_P3, KC_NO,                //18
      KC_LCTL,  KC_LGUI, KC_LALT,                  KC_SPC,                            KC_RALT,    OS_RGB,  KC_RCTL,       KC_LEFT, KC_DOWN, KC_RIGHT, KC_P0,   KC_PDOT,  KC_PENT),      //13
/*
[1] = LAYOUT_96_ansi(\
      RESET,   EEP_RST,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, \
      BL_TOGG, BL_STEP,  BL_ON,   BL_OFF,  BL_INC,  BL_DEC,  BL_BRTG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           \
      RGB_TOG, RGB_MOD,  RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           \
      KC_TRNS, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    \
      KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                             \
      KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),                                                                \
*/
[_FUNC] = LAYOUT_all(
      _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,    _______,   _______,  _______,  _______,  _______, _______, _______,  _______, EEP_RST, RESET,
      _______,   _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,     _______,    _______,    _______, _______,   _______,_______,  _______,  _______, _______, _______,
      _______,     KC_PGUP,    KC_UP,    KC_PGDN,    KC_HOME,    KC_INS,     _______,    _______,    _______,     _______,    _______,    _______, _______, _______, _______,   _______,   _______,   _______,
      _______,      KC_LEFT,    KC_DOWN,  KC_RIGHT,    KC_END,    KC_DEL,     _______,    _______,    _______,     _______,    _______, _______,  _______, _______,  _______,   _______,   _______,   _______,
      _______,     _______,  KC_MPLY,     KC_MPRV,  KC_MNXT,     BL_DEC,    BL_TOGG,    BL_INC,    KC_MUTE,     KC_VOLD,  KC_VOLU,  _______, _______,KC_PGUP,_______, _______,   _______,   _______,
      _______,  _______, _______,                  _______,                            _______,   MO(_RGB),  _______,       _______, KC_PGDN, _______, _______,   _______,          _______),

[_RGB] = LAYOUT_all(
      _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,    _______,   _______,  _______,  _______,  _______, _______, _______,  _______, _______, _______,
      _______,   RGB_TOG, RGB_MOD,  RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,           _______,    _______,     _______,    _______,    _______, _______,   _______,_______,  _______,  _______, _______, _______,
      _______,     _______, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,   _______,    _______,     _______,    _______,    _______, _______, _______, _______,   _______,   _______,   _______,
      _______,      _______,    _______,  _______,    _______,    _______,     _______,    _______,    _______,     _______,    _______, _______,  _______, _______,  _______,   _______,   _______,   _______,
      _______,       _______,     _______,    _______,    _______,     _______,    _______,     _______,  _______,  _______, _______,_______,_______, _______,   KC_SEC1,   KC_SEC2,   _______, _______,
      _______,  _______, _______,                  _______,                            _______,   _______,  _______,       _______, _______, _______, _______,   _______,          _______),



};
