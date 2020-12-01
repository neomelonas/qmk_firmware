#include "oxinai.h"

userspace_config_t userspace_config;
#if (defined(UNICODE_ENABLE) || defined(UNICODEMAP_ENABLE) || defined(UCIS_ENABLE))
    #define OXINAI_UNICODE_MODE UC_LNX
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
#ifndef GIT_ENABLE
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

    SEQ_ONE_KEY(KC_V) {
      SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION " ");
      tap(KC_ENTER);
      SEND_STRING ("Built at: " QMK_BUILDDATE);
    }
#endif
#ifdef GIT_ENABLE
    // git add
    SEQ_ONE_KEY(KC_A){
      SEND_STRING("git add ");
    }
    // git branch
    SEQ_ONE_KEY(KC_B){
      SEND_STRING("git branch ");
    }
    // git checkout
    SEQ_TWO_KEYS(KC_C, KC_O){
      SEND_STRING("git checkout ");
    }
    // git commit
    SEQ_ONE_KEY(KC_C){
      SEND_STRING("git commit -m \"\""SS_TAP(X_LEFT));
    }
    // git diff
    SEQ_ONE_KEY(KC_D){
      SEND_STRING("git diff ");
    }
    // git fetch
    SEQ_ONE_KEY(KC_F){
      SEND_STRING("git fetch ");
    }
    // git grep
    SEQ_ONE_KEY(KC_G){
      SEND_STRING("git grep ");
    }
    // git init
    SEQ_ONE_KEY(KC_I){
      SEND_STRING("git init");
    }
    // git log
    SEQ_ONE_KEY(KC_L){
      SEND_STRING("git log --decorate --oneline --graph");
    }
    // git merge
    SEQ_ONE_KEY(KC_M){
      SEND_STRING("git merge ");
    }
    // git mergetool
    SEQ_TWO_KEYS(KC_M, KC_T){
      SEND_STRING("git mergetool");
    }
    // git pull
    SEQ_TWO_KEYS(KC_P, KC_L){
      SEND_STRING("git pull ");
    }
    // git push
    SEQ_TWO_KEY(KC_P, KC_S){
      SEND_STRING("git push ");
    }
    // git rebase
    SEQ_TWO_KEYS(KC_R, KC_B){
      SEND_STRING("git rebase ");
    }
    // git remote
    SEQ_ONE_KEY(KC_R){
      SEND_STRING("git remote ");
    }
    // git status
    SEQ_ONE_KEY(KC_S){
      SEND_STRING("git status ");
    }
    // git tag
    SEQ_ONE_KEY(KC_T){
      SEND_STRING("git tag ");
    }
#endif
  }
#ifndef NO_SECRETS
  matrix_scan_secrets();
#endif // !NO_SECRETS

  matrix_scan_keymap();
}
#endif
