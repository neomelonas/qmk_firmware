#pragma once
#include "config_common.h"
#define USB_MAX_POWER_CONSUMPTION 100
#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE
#define PERMISSIVE_HOLD
#define RGB_DI_PIN D0
#define RGBLED_NUM 3
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_CUSTOM_LED_INIT
#define RGBLIGHT_SLEEP
#define IS_COMMAND() ( keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) )
