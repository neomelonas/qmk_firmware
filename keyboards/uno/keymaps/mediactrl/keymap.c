#include QMK_KEYBOARD_H

enum uno_keycode
{
    UNO = SAFE_RANGE,
};

uint8_t action = 1;

enum encoder_names {
	_ENCODER,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
      [0] = LAYOUT(
            UNO
          )
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
	case UNO:
	    if (record->event.pressed) {
            if (action == 1) {
                action = 0; /* Set it to not adjust volume */
		        rgblight_sethsv_noeeprom(90, 255, 100); /* The LED indicates the function, green for other */
            } else {
		        action = 1;
                rgblight_sethsv_noeeprom(20, 255, 100); /* The LED indicates the funtion, orange for volume*/
		    }
	    } else {
            return true;
	    }
	default:
	    return true;
    }
};

void keyboard_post_init_user(void) { /*It does what ever you put here after set up when pluged in*/
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(20, 255, 100); /*Sets the LED to orange for volume*/
};


void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _ENCODER) { /* First encoder */
        if (action == 1) {
	        if (clockwise) {
                tap_code(KC_VOLD);
            } else {
                tap_code(KC_VOLU);
            }
	    } else {
	        if (clockwise) {
                tap_code(KC_MPRV);
                //unregister_code(KC_F);
            } else {
                tap_code(KC_MNXT);
                //register_code(KC_F);
            }
	    }
    }
};
