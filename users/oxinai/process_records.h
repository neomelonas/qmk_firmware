#pragma once
#include "oxinai.h"

#if defined(KEYMAP_SAFE_RANGE)
  #define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
  #define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

enum userspace_custom_keycodes {
  VRSN = PLACEHOLDER_SAFE_RANGE,              // Prints QMK Firmware and board info
  KC_QWERTY,         // Sets default layer to QWERTY
  KC_COLEMAK,        // Sets default layer to COLEMAK
  KC_DVORAK,         // Sets default layer to DVORAK
  KC_WORKMAN,        // Sets default layer to WORKMAN
  KC_GREEK,          // Sets default layer to GREEK
  KC_FUNCTIONS,      // Sets default layer to FUNCTION
  LAY_QWE,
  LAY_COL,
  LAY_WOR,
  LAY_DVO,
  KC_SALT,           // See drashna.c for details
  KC_RGB_T,          // Toggles RGB Layer Indication mode
  KC_UCIS,           // Start UCIS stuff
  KC_SECRET_1,       // test1
  KC_SECRET_2,       // test2
  KC_SECRET_3,       // test3
  KC_SECRET_4,       // test4
  KC_SECRET_5,       // test5
  UC_FLIP,           // (ಠ痊ಠ)┻━┻
  UC_TABL,           // ┬─┬ノ( º _ ºノ)
  UC_SHRG,           // ¯\_(ツ)_/¯
  UC_DISA,           // ಠ_ಠ
  SL_THNK,
  SL_FOOL,
  SL_SHRG,
  SL_JC,
  OS_LIN,            // Linux
  OS_MAC,            // MacOSX
  OS_WIN,            // Windows
  LOCKITM,
  LOCKITW,
//  DYNAMIC_MACRO_RANGE,// DYN MACROS
  NEW_SAFE_RANGE     //use "NEWPLACEHOLDER for keymap specific codes
};
/*
#ifdef TAP_DANCE_ENABLE
enum td {
    TD_co = 0,
    TD_xo,
    TD_ps
};
#endif
*/

bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define FN_CAPS LT(_FUNC, KC_CAPS)
#define FN_TAB  LT(_FUNC, KC_TAB)
#define LO_TAB LT(_LOWER, KC_TAB)
#define FN_FUNC MO(_FUNC)
#define FN_CTRL LT(_FUNC, KC_LCTRL)
#define CTRLENT MT(MOD_RCTL, KC_ENT)

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define TG_MODS TG(_MODS)
#define TG_GAME TG(_GAMEPAD)

#define KC_DMR1 DYN_REC_START1
#define KC_DMR2 DYN_REC_START2
#define KC_DMP1 DYN_MACRO_PLAY1
#define KC_DMP2 DYN_MACRO_PLAY2
#define KC_DMRS DYN_REC_STOP

#define KC_SEC1 KC_SECRET_1
#define KC_SEC2 KC_SECRET_2
#define KC_SEC3 KC_SECRET_3
#define KC_SEC4 KC_SECRET_4
#define KC_SEC5 KC_SECRET_5

#define QWERTY KC_QWERTY
#define DVORAK KC_DVORAK
#define COLEMAK KC_COLEMAK
#define WORKMAN KC_WORKMAN
#define GREEK KC_GREEK
#define FUNCS KC_FUNCTIONS
#define MACRS KC_MACROS

#define KC_RESET RESET
#define KC_RST KC_RESET

#ifdef SWAP_HANDS_ENABLE
#define KC_C1R3 SH_TT
#else // SWAP_HANDS_ENABLE
#define KC_C1R3 KC_BSPC
#endif // SWAP_HANDS_ENABLE

#define BK_LWER LT(_LOWER, KC_BSPC)
#define SP_LWER LT(_LOWER, KC_SPC)
#define DL_RAIS LT(_RAISE, KC_DEL)
#define ET_RAIS LT(_RAISE, KC_ENTER)

/* OSM keycodes, to keep things clean and easy to change */
#define KC_MLSF OSM(MOD_LSFT)
#define KC_MRSF OSM(MOD_RSFT)

#define OS_LGUI OSM(MOD_LGUI)
#define OS_RGUI OSM(MOD_RGUI)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_RALT)
#define OS_MEH  OSM(MOD_MEH)
#define OS_HYPR OSM(MOD_HYPR)

#define ALT_APP ALT_T(KC_APP)

#define MG_NKRO MAGIC_TOGGLE_NKRO

#define UC_IRNY UC(0x2E2E)
#define UC_CLUE UC(0x203D)
