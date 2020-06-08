#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _QWERTY 0
#define _DVORAK 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 16

enum custom_keycodes { QWERTY = SAFE_RANGE, DVORAK };

// Mod Taps
#define SFT_ENT SFT_T(KC_ENT)
#define CTL_ESC CTL_T(KC_ESC)

// Macros
#define SCN_SHT LSFT(LGUI(LCTL(KC_4)))  // Take a screenshot (MacOS)

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_ortho_4x12(
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC, \
      CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,\
      SFT_ENT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT,\
      _______, KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_ENT, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT),


    [_DVORAK] = LAYOUT_ortho_4x12(
      KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
      CTL_ESC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
      KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    SFT_ENT, \
      _______, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_ENT,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT ),

    [_RAISE] = LAYOUT_ortho_4x12(
      KC_GRV,  KC_1,     KC_2,        KC_3,      KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
      _______, KC__MUTE, KC_MRWD,     KC_MFFD,   SCN_SHT, XXXXXXX, XXXXXXX, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
      _______, KC_MPLY,  KC__VOLDOWN, KC__VOLUP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
      _______,  _______, _______,     _______,   _______, _______, _______, _______, _______, _______, _______, _______),

    [_LOWER] = LAYOUT_ortho_4x12(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, KC_PSLS, KC_P7, KC_P8,   KC_P9,   KC_PMNS, _______, \
      _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, KC_PAST, KC_P4, KC_P5,   KC_P6,   KC_PPLS, _______, \
      _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, KC_PMNS, KC_P1, KC_P2,   KC_P3,   KC_PDOT, _______, \
      _______, _______, _______, _______, _______, _______, _______, KC_P0, _______, _______, _______, _______),

    [_ADJUST] = LAYOUT_ortho_4x12(
      _______, RESET,   DEBUG,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
      _______, QWERTY,  DVORAK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
      _______, CG_SWAP, AG_SWAP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)

};

uint32_t layer_state_set_user(uint32_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
     case DVORAK:
        if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
        }
        return false;
        break;
  }
  return true;
}
