#include QMK_KEYBOARD_H
#include "oxinai.h"

#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

enum layers {
    _L0 = 0,
/*    _L1,
    _L2,
    _L3,
    _L4,
    _L5,
    _L6,
    _L7,
    _L8,
    _L9
*/};
#define FN_ZERO LT(_L9, KC_0)

//static uint8_t current_layer;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*  .-----------.  .-----------.  .-----------.  .-----------.  .-----------.
 *  |  7|  8|  9|  |  +|  -|  *|  |  ^|  &|  !|  |VLU|Ver|WFD|  |VLU|NXT|FFD|
 *  |-----------|  |-----------|  |-----------|  |-----------|  |-----------|
 *  |  4|  5|  6|  |  /|  %|  ,|  |  D|  E|  F|  |MUT|C-W|CHR|  |MUT|STP|PLY|
 *  |-----------|  |-----------|  |-----------|  |-----------|  |-----------|
 *  |  1|  2|  3|  |  .|  =|Ent|  |  A|  B|  C|  |VLD|CMP|WBK|  |VLD|PRV|RWD|
 *  |-----------|  |-----------|  |-----------|  |-----------|  |-----------|
 *  |L0 |  _L9/0|  |L1 |  _L9  |  |L2 |  _L9  |  |L3 |  _L9  |  |L4 |  _L9  |
 *  *-----------*  *-----------*  *-----------*  *-----------*  *-----------*
 *  .-----------.  .-----------.  .-----------.  .-----------.  .-----------.
 *  |PgD| Up|PgU|  |   |   |   |  |MP1|   |MP2|  |   |   |RST|  |_L6|_L7|_L8|
 *  |-----------|  |-----------|  |-----------|  |-----------|  |-----------|
 *  |Lft|Dwn|Rgt|  |   |   |   |  |   |MRS|   |  |   |   |   |  |_L3|_L4|_L5|
 *  |-----------|  |-----------|  |-----------|  |-----------|  |-----------|
 *  |Hom|Ins|End|  |   |   |   |  |MR1|   |MR2|  |   |   |   |  |_L0|_L1|_L2|
 *  |-----------|  |-----------|  |-----------|  |-----------|  |-----------|
 *  |L5 |  _L9  |  |L6 |  _L9  |  |L7 |  _L9  |  |L8 |  _L9  |  |L9 |       |
 *  *-----------*  *-----------*  *-----------*  *-----------*  *-----------*
 * L9: MASTER CONTROL        
 * L0: Media & CopyPasteos,    
 * L1: Numpad Symbols        
 * L2: ... Maybe HexPad?     
 * L3: Volume & Misc?        
 * L4: NumPad                
 * L5: Nav Cluster & Ins/Del 
 * L6: Nothing               
 * L7: Dynamic Macros        
 * L8: RESET Top Right     */
//    [_L0] = {{KC_MPLY, KC_MPRV, KC_MNXT}, {KC_MUTE, KC_VOLD, KC_VOLU}, {XXXXXXX, BL_STEP, XXXXXXX}, {XXXXXXX, XXXXXXX, MO(_L9)}},
    [_L0] = {{KC_F19,  KC_F20,  KC_F21},  {KC_F16,  KC_F17,  KC_F18},  {KC_F13,  KC_F14,  KC_F15},  {XXXXXXX, XXXXXXX, KC_F24}},
/*    [_L1] = {{KC_PPLS, KC_PMNS, KC_PAST}, {KC_PSLS, KC_PERC, KC_COMM}, {KC_PDOT, KC_EQL,  KC_PENT}, {XXXXXXX, XXXXXXX, MO(_L9)}},
    [_L2] = {{KC_CIRC, KC_AMPR, KC_EXLM}, {S(KC_D), S(KC_E), S(KC_F)}, {S(KC_A), S(KC_B), S(KC_C)}, {XXXXXXX, XXXXXXX, MO(_L9)}},
    [_L3] = {{KC_SEC2, UC_M_OS, UC_M_WC}, {UC_FLIP, UC_DISA, UC_SHRG}, {KC_DMP1, KC_DMP2, KC_DMRS}, {XXXXXXX, XXXXXXX, MO(_L9)}},
    [_L4] = {{KC_7,    KC_8,    KC_9   }, {KC_4,    KC_5,    KC_6   }, {KC_1,    KC_2,    KC_3   }, {XXXXXXX, XXXXXXX, FN_ZERO}},
    [_L5] = {{KC_PGDN, KC_UP,   KC_PGUP}, {KC_LEFT, KC_DOWN, KC_RGHT}, {KC_HOME, KC_INS , KC_END }, {XXXXXXX, XXXXXXX, MO(_L9)}},
    [_L6] = {{_______, _______, _______}, {_______, _______, _______}, {_______, _______, _______}, {XXXXXXX, XXXXXXX, MO(_L9)}},
    [_L7] = {{KC_DMP1, _______, KC_DMP2}, {_______, KC_DMRS, _______}, {KC_DMR1, _______, KC_DMR2}, {XXXXXXX, XXXXXXX, MO(_L9)}},
    [_L8] = {{_______, _______, RESET  }, {BL_STEP, BL_TOGG, BL_BRTG}, {_______, _______, _______}, {XXXXXXX, XXXXXXX, MO(_L9)}},
    [_L9] = {{DF(_L6), DF(_L7), DF(_L8)}, {DF(_L3), DF(_L4), DF(_L5)}, {DF(_L0), DF(_L1), DF(_L2)}, {XXXXXXX, XXXXXXX, _______}},
*/};
