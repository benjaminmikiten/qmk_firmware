#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _RAISE,
    _LOWER,
    _MOUSE,
    _ADJUST
};



#define KC_V_DN KC__VOLDOWN
#define KC_V_UP KC__VOLUP

#define SCN_SHT LSFT(LGUI(LCTL(KC_4)))  // Take a screenshot (MacOS)

#define SFT_ENT SFT_T(KC_ENT)
#define CTL_ESC CTL_T(KC_ESC)

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define MOUSE MO(_MOUSE)
#define FN MO(_FN)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT_ortho_5x15(
        KC_P7,   KC_P8,   KC_P9,   KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV, \
        KC_P4,   KC_P5,   KC_P6,   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
        KC_P1,   KC_P2,   KC_P3,   CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
        KC_PDOT, KC_P0,   KC_PENT, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT, \
        KC_VOLD, KC_VOLU, MC_MLPY, _______, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_ENT,  KC_SFT,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
    ),
    [_RAISE] = LAYOUT_ortho_5x15(
        KC_10,   KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        KC_7,    KC_8,    KC_9,    _______, KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_U, _______, _______, _______, _______, _______, _______, KC_DEL,  \
        KC_4,    KC_5,    KC_6,    _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
        KC_1,    KC_2,    KC_3,    _______, KC_ACL2, KC_ACL1, KC_ACL0, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, MC_MLPY  \
    ),
    [_LOWER] = LAYOUT_ortho_5x15(
        RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
        RGB_M_B, RGB_M_R, RGB_M_SW,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        RGB_SPI, RGB_SPD, RGB_M_G, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
    ),
    [_ADJUST] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
    )
};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
