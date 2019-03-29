// Defines actions for my global custom keycodes. Defined in oxinai.h file, shamelessly stolen from Drashna :)
// Then runs the _keymap's record handler if not processed here
#include "oxinai.h"

uint16_t copy_paste_timer;

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

__attribute__ ((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

// If console is enabled, it will print the matrix position and status of each key pressed
#ifdef KEYLOGGER_ENABLE
  #if defined(KEYBOARD_ergodox_ez) || defined(KEYBOARD_iris_rev2)
    xprintf("KL: col: %u, row: %u, pressed: %u\n", record->event.key.row, record->event.key.col, record->event.pressed);
  #else
    xprintf("KL: col: %u, row: %u, pressed: %u\n", record->event.key.col, record->event.key.row, record->event.pressed);
  #endif
#endif //KEYLOGGER_ENABLE

// If dynamic macros are enabled, use 'em.
#ifdef DYNMAC_ENABLE
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }
#endif //DYNMAC_ENABLE
  switch (keycode) {
  //Switch Default layouts
  case KC_QWERTY:
    if (record->event.pressed) {
      persistant_default_layer_set(1UL<<_QWERTY);
    }
    break;
  case KC_COLEMAK:
    if (record->event.pressed) {
      persistant_default_layer_set(1UL<<_COLEMAK);
    }
    break;
  case KC_DVORAK:
    if (record->event.pressed) {
      persistant_default_layer_set(1UL<<_DVORAK);
    }
    break;
  case KC_WORKMAN:
    if (record->event.pressed) {
      persistant_default_layer_set(1UL<<_WORKMAN);
    }
    break;
  case KC_GREEK:
    if (record->event.pressed) {
      persistant_default_layer_set(1UL<<_GREEK);
    }
    break;
#if (defined(UNICODE_ENABLE) || defined(UNICODEMAP_ENABLE) || defined(UCIS_ENABLE))
  // Set OS for the Unicodes
  case OS_LIN:
    set_unicode_input_mode(UC_LNX);
    return false;
    break;
  case OS_MAC:
    set_unicode_input_mode(UC_OSX);
    return false;
    break;
  case OS_WIN:
    set_unicode_input_mode(UC_WIN);
    return false;
    break;
#endif
#ifdef UCIS_ENABLE
  case KC_UCIS:
    qk_ucis_start();
    return false;
    break;
#endif
  // Because hitting two or three keys at once is toooooo many D:
  case LOCKITM:
    SEND_STRING(SS_LCTRL(SS_LGUI("q")));
    return false;
    break;
  case LOCKITW:
    SEND_STRING(SS_LGUI("l"));
    return false;
    break;
  // Prints version if Console is enabled.
  case VRSN:
    if (record->event.pressed) {
      send_string_with_delay_P(PSTR(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE), MACRO_TIMER);
    }
    break;
#ifdef UNICODE_ENABLE
  case UC_FLIP: // (ノಠ痊ಠ)ノ彡┻━┻
    if (record->event.pressed) {
      send_unicode_hex_string("0028 30CE 0CA0 75CA 0CA0 0029 30CE 5F61 253B 2501 253B");
    }
    break;
  case UC_TABL: // ┬─┬ノ( º _ ºノ)
    if (record->event.pressed) {
      send_unicode_hex_string("252C 2500 252C 30CE 0028 0020 00BA 0020 005F 0020 00BA 30CE 0029");
    }
    break;
  case UC_SHRG: // ¯\_(ツ)_/¯
    if (record->event.pressed) {
      send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
    }
    break;
  case UC_DISA: // ಠ_ಠ
    if (record->event.pressed) {
      send_unicode_hex_string("0CA0 005F 0CA0");
    }
    break;
#endif
  case SL_SHRG:
    if (record->event.pressed) {
      send_string("/shrug");
    }
    break;
  case SL_FOOL:
    if (record->event.pressed) {
      send_string(":fool:");
    }
    break;
  case SL_THNK:
    if (record->event.pressed) {
      send_string(":thunking:");
    }
    break;
  case SL_JC:
    if (record->event.pressed) {
      send_string(":jimcannon:");
    }
    break;
  }
  return process_record_keymap(keycode, record) &&
  process_record_secrets(keycode, record);
}
