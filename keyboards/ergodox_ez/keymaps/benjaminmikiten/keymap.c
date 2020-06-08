// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
#include "benjaminmikiten.h"
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

enum ergodox_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   `    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  TAB   |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |  BSPC  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  LCTRL |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |  QUOT  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LSHIFT |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | SFT/ENT|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LKSCRN |  CTL |  ALT | GUI | LOWER |                                       |RAISE | LEFT | DOWN |  UP  | RIGHT |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,--------------------.
 *                                        | PLAY | MUTE |       | RBG TOG | RGB MOD |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | VOL+ |       | PgUp |        |      |
 *                                 | ENTER|SPACE |------|       |------| ENTER  | SPACE|
 *                                 |      |      | VOL- |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */


[_QWERTY] = LAYOUT_ergodox_wrapper(
        // left hand
        KC_ESC,  ________________NUMBER_LEFT________________, XXXXXXX,
        KC_TAB,  _________________QWERTY_L1_________________, KC_DEL,
        KC_LCTL, _________________QWERTY_L2_________________,
        KC_LSPO, _________________QWERTY_L3_________________, KC_BSPC,
        LCKSCRN, KC_LCTL, KC_LALT, KC_LGUI, LOWER,
                                                     KC_MPLY, KC_MUTE,
                                                              KC_VOLU,
                                            KC_ENT, KC_SPACE, KC_VOLD,
        // right hand
        XXXXXXX, ________________NUMBER_RIGHT_______________, KC_GRV,
        KC_DEL,  _________________QWERTY_R1_________________, KC_BSPC,
                 _________________QWERTY_R2_________________, KC_QUOT,
        XXXXXXX, _________________QWERTY_R3_________________, KC_RSPC,
                           RAISE, _____________VIM_ARROWS____________,
        RGB_TOG, RGB_MOD,
        KC_PGUP,
        KC_PGDN,
        KC_ENT, KC_SPACE
    ),

/*
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |  DEL   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |   -  |   =  |   [  |   ]  |    \   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */


/*
 * RAISE LAYER CONCEPT
 * - The top row is left blank to access the numbers, as I frequently reach for
 * shifted numbers while holding down RAISE. This causes me to insert a debug
 * breakpoint in VSCode which is a pain.
 *  - The RAISE RH default is great for this, as I'm using the same symbol
 * row on all my ortho keyboards.
 *
 *  - RAISE LH is custom, a change from the template because we don't need all
 * the media stuff in it since this board has room for all the media stuff
 *
 */

[_RAISE] = LAYOUT_ergodox_wrapper(
       // left hand
       RESET,   ___________________BLANK___________________, _______,
       _______, _______, KC_UP,   _______, KC_PGUP, _______, _______,
       _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDOWN, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                                    _______, _______,
                                                             _______,
                                            _______,_______, _______,
       // right hand
       _______, ___________________BLANK___________________, _______,
       _______, _________________RAISE_R1__________________, KC_DEL,
                _________________RAISE_R2__________________, KC_BSLS,
       _______, _________________RAISE_R3__________________, _______,
                         _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),

/*
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |       |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[_LOWER] = LAYOUT_ergodox_wrapper(
       _______, _________________FUNC_LEFT_________________, _______,
       _______, _______________MOUSE_ARROWS_1______________, _______,
       _______, _______________MOUSE_ARROWS_2______________,
       _______, _______________MOUSE_ARROWS_3______________, _______,
       _______, _______, _______, _______, _______,
                                                    _______, _______,
                                                             _______,
                                           _______, _______, _______,
    // right hand
       _______, _________________FUNC_RIGHT________________, _______,
       _______, _______, _______, _______, _______, _______, _______,
                KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
                         _______, _______, _______, _______, _______,
       _______, _______,
       PXLSNAP,
       SIP,     _______, _______
),

/*
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | MsUp |      |      |      |      |           |      |      |   7  |   8  |   9  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |MsLeft|MsDown|MsRght|      |      |------|           |------|      |   4  |   5  |   6  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |   .  |   0  |  ENT |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |PXLSNP|      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       | SIP  |      |      |
 *                                 `--------------------'       `--------------------'
 */


[_NUMPAD] = LAYOUT_ergodox_wrapper(
       _______, _________________FUNC_LEFT_________________, _______,
       _______, _______________MOUSE_ARROWS_1______________, _______,
       _______, _______________MOUSE_ARROWS_2______________,
       _______, _______________MOUSE_ARROWS_3______________, _______,
       _______, _______, _______, _______, _______,
                                                    _______, _______,
                                                             _______,
                                           _______, _______, _______,
    // right hand
       _______, _________________FUNC_RIGHT________________, _______,
       _______, _______, KC_P7,   KC_P8,   KC_P9,   _______, _______,
                _______, KC_P4,   KC_P5,   KC_P6,   _______, _______,
       _______, _______, KC_P1,   KC_P2,   KC_P3,   _______, _______,
                         _______, KC_P0,   KC_PENT, _______, _______,
       _______, _______,
       PXLSNAP,
       SIP,     _______, _______
),


[_ADJUST] = LAYOUT_ergodox_wrapper(
       _______, _______, _______, _______, _______, _______, _______,
       _______, _________________ADJUST_L1_________________, _______,
       _______, _________________ADJUST_L2_________________,
       _______, _________________ADJUST_L3_________________, _______,
       _______, _______, _______, _______, _______,
                                                    _______, _______,
                                                             _______,
                                           _______, _______, _______,
    // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  _________________ADJUST_R1_________________, _______,
                 _________________ADJUST_R2_________________, _______,
       _______,  _________________ADJUST_R3_________________, _______,
                          _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),



};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        default:
          break;
    }
    return true;
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  switch (layer) {
    // TODO: Make this relevant to the ErgoDox EZ.
    case _RAISE:
      ergodox_right_led_3_on();
      break;
    case _LOWER:
      ergodox_right_led_2_on();
      break;
    case _ADJUST:
      ergodox_right_led_1_on();
      break;
    default:
      // none
      break;
  }

};
