#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"
#undef PRODUCT
#define PRODUCT IBM Model M122 Terminal Keyboard [Battleship]
#define RETRO_TAPPING
#undef IS_COMMAND
#define IS_COMMAND() (keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)))
#endif
