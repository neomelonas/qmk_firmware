/*
Copyright 2017 Danny Nguyen <danny@keeb.io>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Use I2C or Serial, not both */

// #define USE_SERIAL
#define USE_I2C

/* Select hand configuration */

//#define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS

#define is_command() (get_mods() == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_HOME)))

#ifdef RGBLIGHT_ENABLE
#   define RGB_DI_PIN D3
#   undef RGBLED_NUM
#   define RGBLED_NUM 18     // Number of LEDs
#   define RGBLED_SPLIT { 9, 9 }
#   define RGBLIGHT_HUE_STEP 12
#   define RGBLIGHT_SAT_STEP 12
#   define RGBLIGHT_VAL_STEP 12
#   define RGBLIGHT_EFFECT_KNIGHT_LENGTH 2
#   define RGBLIGHT_EFFECT_SNAKE_LENGTH 2

#   define RGBLIGHT_LIMIT_VAL 225
#endif // RGBLIGHT_ENABLE
