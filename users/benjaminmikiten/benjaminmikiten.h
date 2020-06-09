#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

// Short Macros
#define UNDO    LGUI(KC_Z)
#define REDO    LGUI(KC_Y)
#define COPY    LGUI(KC_C)
#define CUT     LGUI(KC_X)
#define PASTE   LGUI(KC_V)

#define CTL_ESC CTL_T(KC_ESC)
#define LCKSCRN C(G(KC_Q))

#define PXLSNAP G(S(A(KC_P)))
#define SIP     G(A(C(KC_P)))


/* Define layer names */
enum userspace_layers {
    _QWERTY  = 0,
    _GAME,
    _DVORAK,
    _MODS,
    _COLEMAK,
    _GAMEPAD,
    _MACROS,
    _MEDIA,
    _LOWER,
    _PLOVER,
    _NUMPAD,
    _RAISE,
    _ADJUST,
};


#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

#define KEYMAP_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_ortho_4x12_wrapper(...)       LAYOUT_ortho_4x12(__VA_ARGS__)
#define LAYOUT_ortho_5x12_wrapper(...)       LAYOUT_ortho_5x12(__VA_ARGS__)
#define LAYOUT_ergodox_wrapper(...)          LAYOUT_ergodox(__VA_ARGS__)
#define LAYOUT_ergodox_pretty_wrapper(...)   LAYOUT_ergodox_pretty(__VA_ARGS__)
// #define LAYOUT_hhkb_wrapper(...)             LAYOUT_hhkb_wrapper(__VA_ARGS__)


#define _____________VIM_ARROWS___________                 KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT

#define _____________________BOTTOM_L0______________________        _______, KC_LCTL, KC_ALT, KC_GUI, LOWER, KC_ENT
#define _____________________BOTTOM_R0______________________        KC_SPC, RAISE, _____________VIM_ARROWS____________

#define _________________QWERTY_L1_________________        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________        KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define _________________DVORAK_L1_________________        KC_QUOT, KC_COMM, KC_DOT, KC_P,     KC_Y
#define _________________DVORAK_L2_________________        KC_A,    KC_O,    KC_E,   KC_U,     KC_I
#define _________________DVORAK_L3_________________        KC_SCLN, KC_Q,    KC_J,   KC_K,     KC_X

#define _________________DVORAK_R1_________________        KC_F,    KC_G,    KC_C,    KC_R,    KC_L
#define _________________DVORAK_R2_________________        KC_D,    KC_H,    KC_T,    KC_N,    KC_S
#define _________________DVORAK_R3_________________        KC_B,    KC_M,    KC_W,    KC_V,    KC_Z

#define ________________COLEMAK_L1_________________        KC_Q,    KC_W,    KC_F,    KC_P,    KC_G
#define ________________COLEMAK_L2_________________        KC_A,    KC_R,    KC_S,    KC_T,    KC_D
#define ________________COLEMAK_L3_________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define ________________COLEMAK_R1_________________        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define ________________COLEMAK_R2_________________        KC_H,    KC_N,    KC_E,    KC_I,    KC_O
#define ________________COLEMAK_R3_________________        KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define ________________NUMBER_LEFT________________        KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________        KC_6,    KC_7,    KC_8,    KC_9,    KC_0

#define _________________FUNC_LEFT_________________        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

#define ___________________BLANK___________________        _______, _______, _______, _______, _______

#define _______________WASD_ARROWS_1_______________        _______, KC_UP,   _______, _______, _______
#define _______________WASD_ARROWS_2_______________        KC_LEFT, KC_DOWN, KC_RGHT, _______, _______

#define _______________MOUSE_ARROWS_1______________        KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, _______
#define _______________MOUSE_ARROWS_2______________        KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______
#define _______________MOUSE_ARROWS_3______________        KC_ACL0, KC_ACL1, KC_ACL2, _______, _______

#define _________________RAISE_L1__________________        KC_F11,  KC_F12,  _______, _______, _______
#define _________________RAISE_L2__________________        KC_VOLD, KC_VOLU, KC_MUTE, KC_MSTP, _______
#define _________________RAISE_L3__________________        _______, _______, _______, _______, _______

#define _________________RAISE_R1__________________        _______, _______, _______, _______, _______
#define _________________RAISE_R2__________________        KC_PGUP, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC
#define _________________RAISE_R3__________________        KC_PGDN, KC_HOME, KC_END, _______, KC_END

#define _________KP_0____________                          KC_KP_7, KC_KP_8, KC_KP_9
#define _________KP_1____________                          KC_KP_4, KC_KP_5, KC_KP_6
#define _________KP_2____________                          KC_KP_1, KC_KP_2, KC_KP_3
#define _________KP_3____________                          KC_PDOT, KC_KP_0, KC_PENT

#define _________________LOWER_L0__________________        _________KP_0____________, _______, _______
#define _________________LOWER_L1__________________        _________KP_1____________, _______, _______
#define _________________LOWER_L2__________________        _________KP_2____________, _______, _______
#define _________________LOWER_L3__________________        _________KP_3____________, _______, _______

#define _________________LOWER_R0__________________        _______, _______, _______, _______, _______
#define _________________LOWER_R1__________________        _______, _______, _______, _______, _______
#define _________________LOWER_R2__________________        _____________VIM_ARROWS___________, _______
#define _________________LOWER_R3__________________        _______, _______, _______, _______, _______

#define _________________ADJUST_L0_________________        RESET,   EEP_RST, _______, _______, _______
#define _________________ADJUST_L1_________________        _______, _______, _______, _______, _______
#define _________________ADJUST_L2_________________        CK_TOGG, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM
#define _________________ADJUST_L3_________________        MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON

#define _________________ADJUST_R0_________________        _______, _______, _______, _______, _______
#define _________________ADJUST_R1_________________        _______, TERM_ON, TERM_OFF,_______, _______
#define _________________ADJUST_R2_________________        AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______
#define _________________ADJUST_R3_________________        MI_OFF,  _______, RGB_TOG, RGB_MOD, RGB_M_SW

#endif
