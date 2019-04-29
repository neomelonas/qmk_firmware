#include QMK_KEYBOARD_H
#include "oxinai.h"

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define TAPPING_TOGGLE 2

#define FN_MENU LT(_FUNC, KC_APP)

enum greekeys {
    alpha,
    beta,
    gamma,
    delta,
    epsilon,
    zeta,
    eta,
    theta,
    iota,
    kappa,
    lambda,
    mu,
    nu,
    xi,
    omicron,
    pi,
    rho,
    ssigma,
    sigma,
    tau,
    upsilon,
    phi,
    chi,
    psi,
    omega,
    larr,
    rarr,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _QWERTY: (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
   * |-----------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |Alt |Gui |FN  |Ctrl |
   * `-----------------------------------------------------------'
   */
[_QWERTY] = LAYOUT_60_ansi(
  KC_GESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS, \
  FN_CTRL,    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,  \
  KC_LSFT,       KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,         KC_RSFT, \
  KC_LCTL, KC_LGUI, KC_LALT,               KC_SPC,                             KC_RALT,  KC_RGUI, FN_FUNC, CTRLENT),


[_GREEK] = LAYOUT_60_ansi(
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
  _______,KC_SCLN,X(ssigma),X(epsilon),X(rho),X(tau),X(upsilon),X(theta),X(iota),X(omicron),X(pi),X(larr),X(rarr),_______, \
  _______,X(alpha),X(sigma),X(delta),X(phi),X(gamma),X(eta),X(xi),X(kappa),X(lambda),_______,_______,   _______,      \
   _______,   X(zeta),X(chi),X(psi),X(omega),X(beta),X(nu),X(mu),_______,_______,_______,     _______,        \
  _______,_______,_______,                    _______,                            _______,_______,FN_MENU,_______),


  /* Keymap _FUNC: Function Layer
   * ,-----------------------------------------------------------.
   * | ` |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|  Del  |
   * |-----------------------------------------------------------|
   * |     |PUp| Up|PDn|Hom|Ins|   |   |   |   |   |   |   |RESET|
   * |-----------------------------------------------------------|
   * |      |Lft|Dn |Rgt|End|Del|Lft|Dn | Up|Rgt|   |   |        |
   * |-----------------------------------------------------------|
   * |        |Mut|Vo-|Vo+|BLt|BLs|   |   |Ply|Prv|Nxt|          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |Lay0|    |
   * `-----------------------------------------------------------'
   */
[_FUNC] = LAYOUT_60_ansi(
  KC_GRV,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_F12,KC_DEL, \
  _______,KC_PGUP,KC_UP,KC_PGDN,KC_HOME,KC_INS,KC_WH_U,_______,_______,_______,_______,_______,_______,RESET, \
  _______,KC_LEFT,KC_DOWN,KC_RGHT,KC_END,KC_DEL,KC_WH_D,_______,_______,_______,_______,VRSN,_______, \
  _______,KC_MPLY,KC_MPRV,KC_MNXT,_______,BL_STEP,_______,KC_MUTE,KC_VOLD,KC_VOLU,_______,_______, \
  _______,_______,_______,                _______,                        _______,OSL(_MODS),_______,_______),

[_MODS] = LAYOUT_60_ansi(
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
  _______,QWERTY,OS_WIN,_______,_______,_______,_______,KC_UCIS,_______,_______,_______,_______,_______,_______, \
  _______,KC_SEC2,_______,_______,_______,GREEK,_______,_______,_______,OS_LIN,_______,_______,   _______,      \
   _______,   _______,_______,_______, VRSN, _______,_______,OS_MAC, _______,_______,_______,     _______,        \
  _______,_______,_______,                    _______,                            _______,_______,_______,_______),
};

const uint32_t PROGMEM unicode_map[] = {
    [alpha]   = 0x03B1,
    [beta]    = 0x03B2,
    [gamma]   = 0x03B3,
    [delta]   = 0x03B4,
    [epsilon] = 0x03B5,
    [zeta]    = 0x03B6,
    [eta]     = 0x03B7,
    [theta]   = 0x03B8,
    [iota]    = 0x03B9,
    [kappa]   = 0x03BA,
    [lambda]  = 0x03BB,
    [mu]      = 0x03BC,
    [nu]      = 0x03BD,
    [xi]      = 0x03BE,
    [omicron] = 0x03BF,
    [pi]      = 0x03C0,
    [rho]     = 0x03C1,
    [ssigma]  = 0x03C2,
    [sigma]   = 0x03C3,
    [tau]     = 0x03C4,
    [upsilon] = 0x03C5,
    [phi]     = 0x03C6,
    [chi]     = 0x03C7,
    [psi]     = 0x03C8,
    [omega]   = 0x03C9,
    [larr]    = 0x027EA,
    [rarr]    = 0x027EB,
};
