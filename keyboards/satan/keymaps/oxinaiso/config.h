/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

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

#ifndef CONFIG_H
#define CONFIG_H
#endif
/*#include "../../config.h"*/
#include "config_common.h"

/* Tap Dance */
#ifdef TAP_DANCE_ENABLE
#define TAPPING_TERM 200
#define GRAVE_ESC_ALT_OVERRIDE
#define PREVENT_STUCK_MODIFIERS
#define IGNORE_MOD_TAP_INTERRUPT
#endif

#ifdef RGBLIGHT_ENABLE
#undef RGB_DI_PIN
#define RGB_DI_PIN B2
#undef RGBLED_NUM
#define RGBLED_NUM 16        // Number of LEDs
#undef RGBLIGHT_HUE_STEP
#define RGBLIGHT_HUE_STEP 8
#undef RGBLIGHT_SAT_STEP
#define RGBLIGHT_SAT_STEP 8
#undef RGBLIGHT_VAL_STEP
#define RGBLIGHT_VAL_STEP 8
#endif

#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 250

#define QMK_ESC_OUTPUT F0 // usually COL
#define QMK_ESC_INPUT D0 // usually ROW
#define QMK_LED B6
