#include "benjaminmikiten.h"
#include QMK_KEYBOARD_H

enum dz65rgb_keycodes {
    QWERTY = SAFE_RANGE,
    RAISE,
    LOWER,
    ADJUST
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define ADJUST MO(_ADJUST)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_65_ansi_wrapper(
        KC_GESC, ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________, KC_MINS, KC_EQL,  KC_BSPC, KC_GRV,
        KC_TAB,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_LBRC, KC_RBRC, KC_BSLS, KC_MUTE,
        KC_LCTL, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, KC_QUOT,          KC_ENT,  KC_VOLU,
        KC_LSFT,          _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_RSFT, KC_UP,   KC_VOLD,
        LOWER,   KC_LALT, KC_LGUI,                            KC_SPC,                    KC_RALT, RAISE,   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_RAISE] = LAYOUT_65_ansi_wrapper(
        _______, _________________FUNC_LEFT_________________, _________________FUNC_RIGHT________________, KC_F11,  KC_F12,  KC_DEL,  KC_HOME,
        _______, ____________________RGB0___________________, _______, _______, _____FUNCTION_BLOCK_0____, _______, _______, _______, KC_PGUP,
        _______, _____________HHKB_MEDIA___________, _______, _______, _______, _____FUNCTION_BLOCK_1____, _______,          _______, KC_PGDN,
        KC_LSFT,          _______, _______, _______, _______, _______, _______, _____FUNCTION_BLOCK_2____, _______, _______, KC_VOLU, KC_MUTE,
        RESET,   _______, _______,                            _______,                   _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
    ),
    [_LOWER] = LAYOUT_65_ansi_wrapper(
       KC_GESC, _________________FUNC_LEFT_________________, _________________FUNC_RIGHT________________, KC_F11,  KC_F12,  KC_DEL,  KC_HOME,
       _______, ____________________RGB0___________________, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP,
       _______, ____________________RGB1___________________, _______, _____________VIM_ARROWS___________, _______,          _______, KC_PGDN,
       KC_LSFT,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU, KC_MUTE,
       RESET,   _______, _______,                            _______,                   _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
    ),
    [_ADJUST] = LAYOUT_65_ansi_wrapper(
       KC_GESC, _________________FUNC_LEFT_________________, _________________FUNC_RIGHT________________, KC_F11,  KC_F12,  KC_DEL,  KC_HOME,
       _______, ____________________RGB0___________________, _______, _______, _____FUNCTION_BLOCK_0____, _______, _______, _______, KC_PGUP,
       _______, ____________________RGB1___________________, _______, _______, _____FUNCTION_BLOCK_1____, _______,          _______, KC_PGDN,
       KC_LSFT,          _______, _______, _______, _______, _______, _______, _____FUNCTION_BLOCK_2____, _______, _______, KC_VOLU, KC_MUTE,
       RESET,   _______, _______,                            _______,                   _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
