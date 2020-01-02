#include "curry.h"

uint16_t copy_paste_timer;

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

__attribute__((weak)) bool process_record_secrets(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    xprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
    switch (keycode) {
        case KC_MAKE:
            if (!record->event.pressed) {
                uint8_t temp_mod = mod_config(get_mods());
                uint8_t temp_osm = mod_config(get_oneshot_mods());
                clear_mods();
                clear_oneshot_mods();
                send_string_with_delay_P(PSTR("make " QMK_KEYBOARD ":" QMK_KEYMAP), TAP_CODE_DELAY);
                if ((temp_mod | temp_osm) & MOD_MASK_SHIFT) {
                    send_string_with_delay_P(PSTR(":flash"), TAP_CODE_DELAY);
                }
                if ((temp_mod | temp_osm) & MOD_MASK_CTRL) {
                    send_string_with_delay_P(PSTR(" -j8 --output-sync"), TAP_CODE_DELAY);
                }
#ifdef RGB_MATRIX_SPLIT_RIGHT
                send_string_with_delay_P(PSTR(" RGB_MATRIX_SPLIT_RIGHT=yes"), TAP_CODE_DELAY);
#    ifndef OLED_DRIVER_ENABLE
                send_string_with_delay_P(PSTR(" OLED_DRIVER_ENABLE=no"), TAP_CODE_DELAY);
#    endif
#endif
                send_string_with_delay_P(PSTR(SS_TAP(X_ENTER)), TAP_CODE_DELAY);
            }

            break;

        case VRSN:  // Prints firmware version
            if (record->event.pressed) {
                send_string_with_delay_P(PSTR(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE), TAP_CODE_DELAY);
            }
            break;

        case KC_CCCV:  // One key copy/paste
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {  // Hold, copy
                    register_code(KC_LCTL);
                    tap_code(KC_C);
                    unregister_code(KC_LCTL);
                } else {  // Tap, paste
                    register_code(KC_LCTL);
                    tap_code(KC_V);
                    unregister_code(KC_LCTL);
                }
            }
            break;
#ifdef UNICODE_ENABLE
        case UC_FLIP:  // (ノಠ痊ಠ)ノ彡┻━┻
            if (record->event.pressed) {
                send_unicode_hex_string("0028 30CE 0CA0 75CA 0CA0 0029 30CE 5F61 253B 2501 253B");
            }
            break;
        case UC_TABL:  // ┬─┬ノ( º _ ºノ)
            if (record->event.pressed) {
                send_unicode_hex_string("252C 2500 252C 30CE 0028 0020 00BA 0020 005F 0020 00BA 30CE 0029");
            }
            break;
        case UC_SHRG:  // ¯\_(ツ)_/¯
            if (record->event.pressed) {
                send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
            }
            break;
        case UC_DISA:  // ಠ_ಠ
            if (record->event.pressed) {
                send_unicode_hex_string("0CA0 005F 0CA0");
            }
            break;
#endif
    }
    return process_record_keymap(keycode, record) &&
#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
           process_record_user_rgb(keycode, record) &&
#endif  // RGBLIGHT_ENABLE
           process_record_secrets(keycode, record);
}
