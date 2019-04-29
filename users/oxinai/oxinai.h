#pragma once
#include "quantum.h"
#include "version.h"
#include "eeprom.h"
#include "eeconfig.h"
#include "process_records.h"
/*
#ifdef UNICODEMAP_ENABLE
  #include "send_unicode.h"
#endif
*/
/*
#ifdef TAP_DANCE_ENABLE
  #include "tap_dances.h"
#endif
*/
/* Define layer names */
enum userspace_layers {
  _QWERTY = 0,
  _NUMLOCK = 0,
  _COLEMAK,
  _DVORAK,
  _WORKMAN,
  _GREEK,
  _FUNC,
  _RGB,
  _MODS,
  _EMOJI,
  _GAMEPAD,
  _MACROS,
  _MEDIA,
  _MOUSE,
  _SYSTEM,
  _LOWER,
  _RAISE,
  _ADJUST,
};

typedef union {
  uint8_t raw;
} userspace_config_t;

extern userspace_config_t userspace_config;
