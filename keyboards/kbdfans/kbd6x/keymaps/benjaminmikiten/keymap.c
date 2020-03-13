/* Copyright 2018 MechMerlin
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "benjaminmikiten.h"
#include QMK_KEYBOARD_H


// stock hhkb as referenced by https://i.imgur.com/QoBTDHf.png

enum hhkb_keycodes {
  QWERTY = SAFE_RANGE,
  DVORAK,
  RAISE,
  LOWER,
  ADJUST
};

#define M_LOWER MO(_LOWER)
#define M_RAISE MO(_RAISE)

// EXTRA _______ ON EITHER SIDE OF THE BOTTOM ROW IS NECESSARY

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_wrapper(
      KC_ESC,  ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________, KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
      KC_TAB,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_LBRC, KC_RBRC, KC_BSPC,
      KC_LCTL, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, KC_QUOT, KC_ENT,
      KC_LSFT, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_RSFT, M_RAISE,
      _______, KC_LALT, KC_LGUI,                            KC_SPACE,                                    KC_RGUI, KC_RALT, _______
  ),

  [_DVORAK] = LAYOUT_wrapper(
      KC_ESC,  ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________, KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
      KC_TAB,  _________________DVORAK_L1_________________, _________________DVORAK_R1_________________, KC_LBRC, KC_RBRC, KC_BSPC,
      KC_LCTL, _________________DVORAK_L2_________________, _________________DVORAK_R2_________________, KC_QUOT, KC_ENT,
      KC_LSFT, _________________DVORAK_L3_________________, _________________DVORAK_R3_________________, KC_RSFT, M_RAISE,
      _______, KC_LALT, KC_LGUI,                            KC_SPACE,                                    KC_RGUI, KC_RALT, _______
  ),

  [_RAISE] = LAYOUT_wrapper(
      RESET,   _________________FUNC_LEFT_________________,  _________________FUNC_RIGHT________________, KC_F11,  KC_F12, KC_INS, KC_DEL,
      KC_CAPS, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP,   _______, _______,
      _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_MSTP, _______, KC_ASTR, KC_SLSH, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, _______,
      _______, RGB_TOG, RGB_MOD, _______, _______, _______, KC_PLUS, KC_UNDS, KC_END,  KC_PGDN, KC_DOWN, _______, _______,
      _______, _______, _______,                            _______,                                     _______, M_LOWER, _______
  ),

  [_LOWER] = LAYOUT_wrapper(
      _______, QWERTY,  DVORAK,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, RGB_TOG, RGB_MOD, RGB_M_B, RGB_M_R, RGB_M_SW,_______, _______, _______, _______, _______, _______, _______, _______,
      _______, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______,                            _______,                                     _______, _______, _______
  ),

  [_ADJUST] = LAYOUT_wrapper(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______,                            _______,                                     _______, _______, _______
  )
};



void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode){
      case QWERTY:
        if(record -> event.pressed){
          set_single_persistent_default_layer(_QWERTY);
        }
        return false;
        break;
      case DVORAK:
        if(record->event.pressed){
          set_single_persistent_default_layer(_DVORAK);
        }
        return false;
        break;
    //   case LOWER:
    //     if (record->event.pressed) {
    //       layer_on(_LOWER);
    //       update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //     } else {
    //       layer_off(_LOWER);
    //       update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //     }
    //     return false;
    //     break;
    //   case RAISE:
    //     if (record->event.pressed) {
    //       layer_on(_RAISE);
    //       update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //     } else {
    //       layer_off(_RAISE);
    //       update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //     }
    //     return false;
    //     break;

  }
  return true;
}
