#include QMK_KEYBOARD_H
#include "oxinai.h"

typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  SINGLE_TAP = 1,
  DOUBLE_TAP = 2,
  TRIPLE_TAP = 3,
};

enum keycodes {
    TD_Q,
    TD_W,
    TD_E,
    TD_R,
    TD_T,
    TD_Y,
    TD_U,
    TD_I,
    TD_O,
    TD_P,
    TD_L,
    TD_ENT,

};

void rsft_finished (qk_tap_dance_state_t *state, void *user_data);
void rsft_reset (qk_tap_dance_state_t *state, void *user_data);

void tap_dance_layer_finished(qk_tap_dance_state_t*, void*);
void tap_dance_layer_reset(qk_tap_dance_state_t*, void*);
void tap_dance_process_record(uint16_t);


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = KEYMAP_OXINAI(
        KC_GESC, TD(TD_Q),TD(TD_W),TD(TD_E),TD(TD_R),TD(TD_T),TD(TD_Y),TD(TD_U),TD(TD_I),TD(TD_O),TD(TD_P),KC_BSPC,
        FN_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    TD(TD_L),    TD(TD_ENT),
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  TG(_FUNC),  TG(_MODS)
    ),
    [_MODS] = KEYMAP_OXINAI(
        KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, F6, KC_F7, KC_F8, KC_F9, KC_EQL, KC_DEL,
        KC_CAPS, KC_4, KC_5, KC_6, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SCLN, KC_QUOT, KC_PSCR,
        KC_TRNS, KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_SLSH, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_FUNC] = KEYMAP_OXINAI(
        KC_GRV, KC_PGUP, KC_UP, KC_PGDN, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_DEL,
        KC_CAPS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR,
        KC_TRNS, KC_MPLY, KC_MPRV, KC_MNXT, BL_TOGG, BL_DEC, BL_INC, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS, RESET
    ),

};

// Q 1 F1
void q_td(qk_tap_dance_state_t *state, void *user_data){
    switch(state->count){
    case 1:
        register_code(KC_Q);
        break;
    case 2:
        register_code(KC_1);
        break;
    case 3:
        register_code(KC_F1);
        break;
    }
}
void q_td_done(qk_tap_dance_state_t *state, void *user_data){
    switch(state->count){
    case 1:
        unregister_code(KC_Q);
        break;
    case 2:
        unregister_code(KC_1);
        break;
    case 3:
        unregister_code(KC_F1);
        break;
    }
}

// W 2 F2
void w_td(qk_tap_dance_state_t *state, void *user_data){
    switch(state->count){
    case 1:
        register_code(KC_W);
        break;
    case 2:
        register_code(KC_2);
        break;
    case 3:
        register_code(KC_F2);
        break;
    }
}
void w_td_done(qk_tap_dance_state_t *state, void *user_data){
    switch(state->count){
    case 1:
        unregister_code(KC_W);
        break;
    case 2:
        unregister_code(KC_2);
        break;
    case 3:
        unregister_code(KC_F2);
        break;
    }
}

// E 3 F3
void e_td(qk_tap_dance_state_t *state, void *user_data){
    switch(state->count){
    case 1:
        register_code(KC_E);
        break;
    case 2:
        register_code(KC_3);
        break;
    case 3:
        register_code(KC_F3);
        break;
    }
}
void e_td_done(qk_tap_dance_state_t *state, void *user_data){
    switch(state->count){
    case 1:
        unregister_code(KC_E);
        break;
    case 2:
        unregister_code(KC_3);
        break;
    case 3:
        unregister_code(KC_F3);
        break;
    }
}

// R 4 F4
void r_td(qk_tap_dance_state_t *state, void *user_data){
    switch(state->count){
    case 1:
        register_code(KC_R);
        break;
    case 2:
        register_code(KC_4);
        break;
    case 3:
        register_code(KC_F4);
        break;
    }
}
void r_td_done(qk_tap_dance_state_t *state, void *user_data){
    switch(state->count){
    case 1:
        unregister_code(KC_R);
        break;
    case 2:
        unregister_code(KC_4);
        break;
    case 3:
        unregister_code(KC_F3);
        break;
    }
}

// T 5 F5
void t_td(qk_tap_dance_state_t *state, void *user_data){
    switch(state->count){
    case 1:
        register_code(KC_T);
        break;
    case 2:
        register_code(KC_5);
        break;
    case 3:
        register_code(KC_F5);
        break;
    }
}
void t_td_done(qk_tap_dance_state_t *state, void *user_data){
    switch(state->count){
    case 1:
        unregister_code(KC_T);
        break;
    case 2:
        unregister_code(KC_5);
        break;
    case 3:
        unregister_code(KC_F5);
        break;
    }
}

// Y 6 F6
void y_td(qk_tap_dance_state_t *state, void *user_data){
    switch(state->count){
    case 1:
        register_code(KC_Y);
        break;
    case 2:
        register_code(KC_6);
        break;
    case 3:
        register_code(KC_F6);
        break;
    }
}
void y_td_done(qk_tap_dance_state_t *state, void *user_data){
    switch(state->count){
    case 1:
        unregister_code(KC_Y);
        break;
    case 2:
        unregister_code(KC_6);
        break;
    case 3:
        unregister_code(KC_F6);
        break;
    }
}

// U 7 F7
void u_td(qk_tap_dance_state_t *state, void *user_data){
    switch(state->count){
    case 1:
        register_code(KC_U);
        break;
    case 2:
        register_code(KC_7);
        break;
    case 3:
        register_code(KC_F7);
        break;
    }
}
void u_td_done(qk_tap_dance_state_t *state, void *user_data){
    switch(state->count){
    case 1:
        unregister_code(KC_U);
        break;
    case 2:
        unregister_code(KC_7);
        break;
    case 3:
        unregister_code(KC_F7);
        break;
    }
}

// I 8 F8
void i_td(qk_tap_dance_state_t *state, void *user_data){
    switch(state->count){
    case 1:
        register_code(KC_I);
        break;
    case 2:
        register_code(KC_8);
        break;
    case 3:
        register_code(KC_F8);
        break;
    }
}
void i_td_done(qk_tap_dance_state_t *state, void *user_data){
    switch(state->count){
    case 1:
        unregister_code(KC_I);
        break;
    case 2:
        unregister_code(KC_8);
        break;
    case 3:
        unregister_code(KC_F8);
        break;
    }
}

// O 9 F9
void o_td(qk_tap_dance_state_t *state, void *user_data){
    switch(state->count){
    case 1:
        register_code(KC_O);
        break;
    case 2:
        register_code(KC_9);
        break;
    case 3:
        register_code(KC_F9);
        break;
    }
}
void o_td_done(qk_tap_dance_state_t *state, void *user_data){
    switch(state->count){
    case 1:
        unregister_code(KC_O);
        break;
    case 2:
        unregister_code(KC_9);
        break;
    case 3:
        unregister_code(KC_F9);
        break;
    }
}

// P 0 F10
void p_td(qk_tap_dance_state_t *state, void *user_data){
    switch(state->count){
    case 1:
        register_code(KC_P);
        break;
    case 2:
        register_code(KC_0);
        break;
    case 3:
        register_code(KC_F10);
        break;
    }
}
void p_td_done(qk_tap_dance_state_t *state, void *user_data){
    switch(state->count){
    case 1:
        unregister_code(KC_P);
        break;
    case 2:
        unregister_code(KC_0);
        break;
    case 3:
        unregister_code(KC_F10);
        break;
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_Q] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,q_td, q_td_done),
    [TD_W] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,w_td, w_td_done),
    [TD_E] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,e_td, e_td_done),
    [TD_R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,r_td, r_td_done),
    [TD_T] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,t_td, t_td_done),
    [TD_Y] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,y_td, y_td_done),
    [TD_U] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,u_td, u_td_done),
    [TD_I] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,i_td, i_td_done),
    [TD_O] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,o_td, o_td_done),
    [TD_P] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,p_td, p_td_done),
    [TD_L] = ACTION_TAP_DANCE_DOUBLE(KC_L, KC_QUOT),
    [TD_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_ENT),
};

