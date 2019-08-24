#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _RAISE,
    _LOWER
}

#define ESC_CTL LCTL_T(KC_ESC)
#define LOWER MO(LOWER)
#define RAISE MO(RAISE)

#define VOL_DN KC__VOLDOWN
#define VOL_UP KC__VOLUP
#define BRT_DN KC_BRMD
#define BRT_UP KC_BRMU

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_ortho_4x12(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        ESC_CTL, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        _______, KC_LCTL, KC_RALT, KC_LCMD, LOWER,  KC_ENT,   RAISE,   KC_SPC,  KC_RCMD, KC_LALT, KC_RCTL, KC_L
    ),
    [_RAISE] = LAYOUT_ortho_4x12(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_GRV ,
        _______, VOL_DN,  VOL_UP,  KC_MUTE, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
        _______, BRT_DN,  BRT_UP,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    ),
    [_LOWER] = LAYOUT_ortho_4x12(
        _______, KC_P7,   KC_P8,   KC_P9,   _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_P4,   KC_P5,   KC_P6,   _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
        _______, KC_P1,   KC_P2,   KC_P3,   _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_P0,   KC_PDOT, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    ),
};