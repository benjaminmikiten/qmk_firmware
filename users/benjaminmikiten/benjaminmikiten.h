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
    _MODS, /* layer 8 */
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


#define ________________NUMBER_LEFT________________        KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________        KC_6,    KC_7,    KC_8,    KC_9,    KC_0

#define _________________FUNC_LEFT_________________        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

#define ___________________BLANK___________________        _______, _______, _______, _______, _______

#define _______________WASD_ARROWS_1_______________        _______, KC_UP,   _______, _______, _______
#define _______________WASD_ARROWS_2_______________        KC_LEFT, KC_DOWN, KC_RGHT, _______, _______

#define _____________VIM_ARROWS____________                KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT

#define _______________MOUSE_ARROWS_1______________        KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, _______
#define _______________MOUSE_ARROWS_2______________        KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______
#define _______________MOUSE_ARROWS_3______________        KC_ACL0, KC_ACL1, KC_ACL2, _______, _______

#define _________________RAISE_L1__________________        _______, KC_UP,   _______, KC_MUTE, LCKSCRN
#define _________________RAISE_L2__________________        KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLU, KC_BRIU
#define _________________RAISE_L3__________________        KC_MPRV, KC_MNXT, KC_MPLY, KC_VOLD, KC_BRID

#define _________________RAISE_R1__________________        _______, _______, _______, _______, _______
#define _________________RAISE_R2__________________        _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC
#define _________________RAISE_R3__________________        _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END


#define _________________ADJUST_L1_________________        RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG
#define _________________ADJUST_L2_________________        RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD, _______
#define _________________ADJUST_L3_________________        RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RBG_M_G

#define _________________ADJUST_R1_________________        _______, _______, _______, _______, _______
#define _________________ADJUST_R2_________________        CG_TOGG, QWERTY,  _______, _______, _______
#define _________________ADJUST_R3_________________        MU_TOG , CK_TOGG, AU_ON,   AU_OFF,  CG_NORM

#endif
