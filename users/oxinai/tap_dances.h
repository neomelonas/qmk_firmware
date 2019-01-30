#pragma once
#include "oxinai.h"

typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7,
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
    TD_RSFT,
};

void rsft_finished (qk_tap_dance_state_t *state, void *user_data);
void rsft_reset (qk_tap_dance_state_t *state, void *user_data);

void tap_dance_layer_finished(qk_tap_dance_state_t*, void*);
void tap_dance_layer_reset(qk_tap_dance_state_t*, void*);
void tap_dance_process_record(uint16_t);
