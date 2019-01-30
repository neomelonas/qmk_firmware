#include QMK_KEYBOARD_H
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
    TD_RSFT,
};

void rsft_finished (qk_tap_dance_state_t *state, void *user_data);
void rsft_reset (qk_tap_dance_state_t *state, void *user_data);

void tap_dance_layer_finished(qk_tap_dance_state_t*, void*);
void tap_dance_layer_reset(qk_tap_dance_state_t*, void*);
void tap_dance_process_record(uint16_t);

#define RGB_STA RGB_M_P //rgb static
#define RGB_BRE RGB_M_B //rgb breathe
#define RGB_RAI RGB_M_R //rgb rainbow
#define RGB_SWI RGB_M_SW //rgb swirl
#define RGB_SNA RGB_M_SN //rgb snake
#define RGB_KNI RGB_M_K //rgb knight
#define RGB_GRA RGB_M_G //rgb gradient

#define rgb_dn LT(_RGB, KC_PGDN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   /* Keymap: (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
   * |-----------------------------------------------------------|
   * |CAPS/MO|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |Alt |Gui |MO  |Ctrl |
   * `-----------------------------------------------------------'
   */
    [_QWERTY] = LAYOUT_60_b_ansi(
        KC_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , XXXXXXX, KC_BSPC,
        KC_TAB ,          KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
        FN_CTRL ,         KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,          KC_ENT ,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT,         TD(TD_RSFT),  KC_UP,   rgb_dn,
        KC_LCTL,          KC_LGUI, KC_LALT,           KC_SPC, KC_SPC, KC_SPC,              KC_RCTRL, MO(_FUNC), KC_LEFT, KC_DOWN, KC_RGHT),

    /* Keymap : Second Layer (WASD and Media)
   * ,-----------------------------------------------------------.
   * |ESC| F1| F2| F3  |   |   |   |   |   |   |   |   |   | DEL |
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
   * |-----------------------------------------------------------|
   * |      |   |   |   |   |   |   |   |   |   |   |   |        |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
    [_FUNC] = LAYOUT_60_b_ansi(
        KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, KC_SLEP,
        _______,          KC_PGUP, KC_UP,   KC_PGDN, KC_HOME, KC_INS,  _______, _______, _______, _______, _______, _______, _______, RESET  ,
        _______,          KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_DEL,  _______, _______, _______, _______, _______, _______,          _______,
        _______,          KC_MPLY, KC_MPRV, KC_MNXT, _______, BL_STEP, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______,
        _______,          _______, _______,           _______, _______, _______,                 _______, _______, _______, _______,          _______),
   /* Keymap : Third Layer (RGB / Reset)
   * ,-----------------------------------------------------------.
   * | ` |   |   |   |   |   |   |   |   |   |   |   |   |       |
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
   * |-----------------------------------------------------------|
   * |      |   |   |   |   |   |   |       |   |   |   |        |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */

    [_RGB] = LAYOUT_60_b_ansi(
        KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, KC_SLEP,
        _______,          RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, RESET  ,
        _______,          RGB_STA, RGB_BRE, RGB_RAI, RGB_SWI, RGB_SNA, RGB_KNI, RGB_GRA, _______, _______, _______, _______,          _______,
                 _______, BL_DEC , BL_TOGG, BL_INC , BL_STEP, _______, _______, _______, _______,          _______, _______, _______, _______,
        _______,          _______, _______,           _______, _______, _______,                 _______, _______, _______, _______,          _______),

};

void led_set_user(uint8_t usb_led) {
    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        DDRB |= (1 << 2); PORTB &= ~(1 << 2);
    } else {
        DDRB &= ~(1 << 2); PORTB &= ~(1 << 2);
    }
}

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
        case _QWERTY:
            rgblight_setrgb(0x00, 0xff, 0x00);
            break;
        case _FUNC:
            rgblight_setrgb(0xff, 0x80, 0x00);
            break;
        case _RGB:
            rgblight_setrgb(0x4c, 0x00 , 0x99);
            break;
        default:
            rgblight_setrgb(0xff, 0xff, 0xff);
            break;
    }
    return state;
}

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
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_RSFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,rsft_finished, rsft_reset),
};
