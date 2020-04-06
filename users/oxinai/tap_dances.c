#include "tap_dances.h"

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 8; //magic number. At some point this method will expand to work for more presses
}

//instanalize an instance of 'tap' for the 'rsft' tap dance.
static tap rsfttap_state = {
  .is_press_action = true,
  .state = 0
};

void rsft_finished (qk_tap_dance_state_t *state, void *user_data) {
  rsfttap_state.state = cur_dance(state);
  switch (rsfttap_state.state) {
    case SINGLE_TAP: register_code(KC_SLSH); break;
    case SINGLE_HOLD: register_code(KC_RSFT); break;
    case DOUBLE_TAP: register_code(KC_RSFT); register_code(KC_SLSH); break;
    case DOUBLE_HOLD: register_code(KC_PGUP); break;
    case DOUBLE_SINGLE_TAP: register_code(KC_SLSH); unregister_code(KC_SLSH); register_code(KC_SLSH); break;
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void rsft_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (rsfttap_state.state) {
    case SINGLE_TAP: unregister_code(KC_SLSH); break;
    case SINGLE_HOLD: unregister_code(KC_RSFT); break;
    case DOUBLE_TAP: unregister_code(KC_RSFT); unregister_code(KC_SLSH); break;
    case DOUBLE_HOLD: unregister_code(KC_PGUP); break;
    case DOUBLE_SINGLE_TAP: unregister_code(KC_SLSH); break;
  }
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_Q] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_1),
    [TD_W] = ACTION_TAP_DANCE_DOUBLE(KC_W, KC_2),
    [TD_E] = ACTION_TAP_DANCE_DOUBLE(KC_E, KC_3),
    [TD_R] = ACTION_TAP_DANCE_DOUBLE(KC_R, KC_4),
    [TD_T] = ACTION_TAP_DANCE_DOUBLE(KC_T, KC_5),
    [TD_Y] = ACTION_TAP_DANCE_DOUBLE(KC_Y, KC_6),
    [TD_U] = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_7),
    [TD_I] = ACTION_TAP_DANCE_DOUBLE(KC_I, KC_8),
    [TD_O] = ACTION_TAP_DANCE_DOUBLE(KC_O, KC_9),
    [TD_P] = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_0),
    [TD_L] = ACTION_TAP_DANCE_DOUBLE(KC_L, KC_QUOT),
    [TD_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_ENT),
    [TD_RSFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,rsft_finished, rsft_reset),
};
