#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _RAISE,
    _LOWER,
    _HEXPAD,
    _ADJUST
};



#define KC_V_DN KC__VOLDOWN
#define KC_V_UP KC__VOLUP

#define SCN_SHT LSFT(LGUI(LCTL(KC_4)))  // Take a screenshot (MacOS)
#define LCK_SCN LGUI(LCTL(KC_Q)) // lock screen

#define SFT_ENT SFT_T(KC_ENT)
#define CTL_ESC CTL_T(KC_ESC)

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define MOUSE MO(_MOUSE)
#define HEXPAD TG(_HEXPAD)
#define FN MO(_FN)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT_ortho_5x15(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_P7,   KC_P8,   KC_P9,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_P4,   KC_P5,   KC_P6,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_P1,   KC_P2,   KC_P3,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_PDOT, KC_P0,   KC_PENT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT, \
        _______, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_ENT,  KC_VOLD, KC_VOLU, KC_MPLY, KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
    ),
    [_RAISE] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, \
        _______, KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_U, _______, KC_F7,   KC_F8,   KC_F9,   _______, _______, _______, _______, _______, KC_DEL,  \
        _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, KC_F4,   KC_F5,   KC_F6,   _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
        _______, KC_ACL2, KC_ACL1, KC_ACL0, _______, _______, KC_F1,   KC_F2,   KC_F3,   _______, _______, _______, KC_PGUP, KC_PGDN, _______, \
        _______, _______, _______, _______, _______, _______, HEXPAD,  _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
    ),
    [_LOWER] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, KC_D,    KC_E,    KC_F,    _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, KC_A,    KC_B,    KC_C,    _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
        _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   _______, _______, _______, _______, _______, _______  \
    ),
    [_HEXPAD] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, KC_D,    KC_E,    KC_F,    _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, KC_A,    KC_B,    KC_C,    _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   _______, _______, _______, _______, _______, _______  \
    ),
    [_ADJUST] = LAYOUT_ortho_5x15(
        _______, AG_TOGG, CG_TOGG, _______, _______, _______, RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, RGB_HUI, RGB_SAI, RGB_VAI,  _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, RGB_M_B, RGB_M_R, RGB_M_SW,_______, _______, _______, _______, _______, _______, \
        RESET,   _______, _______, _______, _______, _______, RGB_SPI, RGB_SPD, RGB_M_G, _______, _______, _______, _______, _______, _______  \
    )
};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
