/* Copyright 2019 Ethan Durrant (emdarcher)
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

#define INDICATOR_LED   B5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(/* Base */
                 LT(_FUNC, KC_INS), KC_HOME, KC_PGUP,
                 KC_DEL,    KC_END,     KC_PGDN,

                            KC_UP,
                 KC_LEFT,   KC_DOWN,    KC_RIGHT),
    [_FUNC] = LAYOUT(/* media function layer, toggled on a single tap */
                 KC_TRNS,   KC_MPRV,    KC_VOLU,

                            KC_A,
                 KC_K,      KC_Z,    KC_J),
};

layer_state_t layer_state_set_user(layer_state_t state){
    switch(get_highest_layer(state)){
        case _QWERTY:
            writePinHigh(INDICATOR_LED);
            break;
        case _FUNC:
            writePinLow(INDICATOR_LED);
            break;
        default:
            writePinHigh(INDICATOR_LED);
            break;
    }
    return state;
};

