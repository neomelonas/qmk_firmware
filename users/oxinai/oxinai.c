#include "oxinai.h"

userspace_config_t userspace_config;
#if (defined(UNICODE_ENABLE) || defined(UNICODEMAP_ENABLE) || defined(UCIS_ENABLE))
    #define OXINAI_UNICODE_MODE UC_OSX
#else
    #define OXINAI_UNICODE_MODE 2
#endif

void tap(uint16_t keycode){ register_code(keycode); unregister_code(keycode);  }

__attribute__ ((weak))
void matrix_init_keymap(void) {}

__attribute__ ((weak))
void startup_keymap(void) {}

__attribute__ ((weak))
void suspend_power_down_keymap(void) {}

__attribute__ ((weak))
void suspend_wakeup_init_keymap(void) {}

__attribute__ ((weak))
void matrix_scan_keymap(void) {}

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}
// old
__attribute__ ((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  return true;
}
///endold
__attribute__ ((weak))
void matrix_scan_secrets(void) {}

__attribute__ ((weak))
uint32_t layer_state_set_keymap (uint32_t state) {
  return state;
}

__attribute__ ((weak))
uint32_t default_layer_state_set_keymap (uint32_t state) {
  return state;
}

__attribute__ ((weak))
void led_set_keymap(uint8_t usb_led) {}

// Call user matrix init, set default RGB colors and then
// call the keymap's init function
void matrix_init_user(void) {
  userspace_config.raw = eeconfig_read_user();

  #if (defined(UNICODE_ENABLE) || defined(UNICODEMAP_ENABLE) || defined(UCIS_ENABLE))
    set_unicode_input_mode(OXINAI_UNICODE_MODE);
    get_unicode_input_mode();
  #endif //UNICODE_ENABLE


  matrix_init_keymap();
}

void startup_user (void) {
  startup_keymap();
}

void suspend_power_down_user(void)
{
    suspend_power_down_keymap();
}

void suspend_wakeup_init_user(void)
{
  suspend_wakeup_init_keymap();
  #ifdef KEYBOARD_ergodox_ez
  wait_ms(10);
  #endif
}

void eeconfig_init_user(void) {
  userspace_config.raw = 0;
  eeconfig_update_user(userspace_config.raw);
  #if (defined(UNICODE_ENABLE) || defined(UNICODEMAP_ENABLE) || defined(UCIS_ENABLE))
    set_unicode_input_mode(OXINAI_UNICODE_MODE);
    get_unicode_input_mode();
  #else
    eeprom_update_byte(EECONFIG_UNICODEMODE, OXINAI_UNICODE_MODE);
  #endif
}
#ifdef LEADER_ENABLE
LEADER_EXTERNS();
// No global matrix scan code, so just run keymap's matrix
// scan function
void matrix_scan_user(void) {
  static bool has_ran_yet;
  if (!has_ran_yet) {
    has_ran_yet = true;
    startup_user();
  }
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // Mac Lock (Leader -> q)
    SEQ_ONE_KEY(KC_Q) {
      SEND_STRING(SS_LCTRL(SS_LGUI("q")));
    }
    // Win Lock (Leader -> l)
    SEQ_ONE_KEY(KC_L) {
      SEND_STRING(SS_LGUI("l"));
    }

    SEQ_THREE_KEYS(KC_L, KC_I, KC_O) {
        SEND_STRING("test");
    }

    SEQ_ONE_KEY(KC_B) {
      SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION " ");
      tap(KC_ENTER);
      SEND_STRING ("Built at: " QMK_BUILDDATE);
    }
#ifndef NO_SECRETS
    matrix_scan_secrets();
#endif // !NO_SECRETS
  }

  matrix_scan_keymap();
}
#endif
