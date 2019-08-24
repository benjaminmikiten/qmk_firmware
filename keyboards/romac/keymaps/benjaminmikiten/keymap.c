/* Copyright 2018 Jack Humbert
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

#include QMK_KEYBOARD_H

#define _BASE 0
#define _TENKEY 1
#define _LAYERS 2
#define _FN1 3
#define _APPS 4
#define _MOUSE 5
#define _EMOJI 6
#define _SWEARS 7

#define LAYERS MO(_LAYERS)
#define BASE TO(_BASE)
#define FN1 TO(_FN1)
#define APPS TO(_APPS)
#define MOUSE TO(_MOUSE)
#define EMOJI TO(_EMOJI)
#define SWEARS TO(_SWEARS)
#define TENKEY TO(_TENKEY)

// custom macros
#define SCN_SHT LSFT(LCTL(LGUI(KC_4)))  // Take a screenshot to clipboard (MacOS)
#define SCN_LCK LCTL(LGUI(KC_Q))

enum custom_keycodes {
    CHROME = SAFE_RANGE,
    ENTER_EMOJI,
    CLEAR_EMOJI,
    SPOTIF,
    ITERM,
    SLACK,
    VSCODE,
    FUCK,
    SHIT,
    DAMN,
    DANGOL,
    HECK,
    SHOOT,
    PISS,
    MFER,
    GDMIT,
    HELL,
    ASS
};

enum unicode_names {
    POOP,
    HEARTEY,
    CLAP,
    THUMB_U,
    THUMB_D,
    COOL,
    SKULL,
    MAGE,
    FIRE,
    BUTT,
    PENIS,
    CUM
};


const uint32_t PROGMEM unicode_map[] = {
    [POOP] = 0x1F4A9,
    [HEARTEY] = 0x1F60D,
    [CLAP] = 0x1F44F,
    [THUMB_U] = 0x1F44D,
    [THUMB_D] = 0x1F44E,
    [COOL] = 0x1F60E,
    [SKULL] = 0x1F480,
    [FIRE] = 0x1F525,
    [MAGE] = 0x1F9D9,
    [BUTT] = 0x1F351,
    [PENIS] = 0x1F346,
    [CUM] = 0x1F4A6,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_P7, KC_P8, KC_P9, \
        KC_P4, KC_P5, KC_P6, \
        KC_P1, KC_P2, KC_P3, \
        LAYERS, KC_P0, KC_PENT \
    ),
    [_TENKEY] = LAYOUT (
        KC_PSLS, KC_PAST, KC_PMNS, \
        KC_NLCK, KC_PEQL, KC_PPLS, \
        XXXXXXX, XXXXXXX, KC_PDOT, \
        BASE   , XXXXXXX, KC_PENT \
    ),
    [_LAYERS] = LAYOUT(
        TENKEY, FN1 ,    APPS   ,\
        MOUSE , EMOJI  , SWEARS, \
        XXXXXXX, XXXXXXX, XXXXXXX,\
        LAYERS , _______, _______ \
    ),
     [_FN1] = LAYOUT(
        SCN_SHT, SCN_LCK, XXXXXXX, \
        KC_MRWD, KC_MFFD, KC_MFFD, \
        KC__MUTE, KC__VOLUP, KC__VOLDOWN, \
        BASE   , XXXXXXX, XXXXXXX \
    ),
    [_APPS] = LAYOUT(
        ITERM  , SPOTIF , CHROME , \
        SLACK  , VSCODE , XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, \
        BASE   , XXXXXXX, XXXXXXX \
    ),
    [_MOUSE] = LAYOUT(
        KC_BTN1, KC_MS_U , KC_BTN2 , \
        KC_MS_L , KC_MS_D , KC_MS_R, \
        KC_ACL0, KC_WH_U, KC_ACL1, \
        BASE   , KC_WH_D, KC_ACL2 \
    ),
    [_EMOJI] = LAYOUT(
       X(THUMB_U), X(CLAP) , X(THUMB_D) , \
        X(FIRE), X(SKULL) , X(MAGE), \
        X(BUTT), X(PENIS), X(HEARTEY), \
        BASE   , X(COOL), X(POOP) \
    ),
    [_SWEARS] = LAYOUT(
        FUCK, SHIT, DAMN, \
        DANGOL, HECK, SHOOT, \
        PISS, MFER, GDMIT, \
        BASE   , HELL, ASS \
    ),
};

void matrix_init_user(){
    set_unicode_input_mode(UC_OSX);
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case FUCK:
        SEND_STRING("FUCK");
        return false;
        break;
      case DAMN:
        SEND_STRING("DAMN");
        return false;
        break;
      case SHIT:
        SEND_STRING("SHIT");
        return false;
        break;
      case DANGOL:
        SEND_STRING("DANG 'OL");
        return false;
        break;
      case HECK:
        SEND_STRING("HECK");
        return false;
        break;
      case SHOOT:
        SEND_STRING("SHOOT");
        return false;
        break;
      case PISS:
        SEND_STRING("PISS");
        return false;
        break;
      case MFER:
        SEND_STRING("MOTHERFUCKER");
        return false;
        break;
      case GDMIT:
        SEND_STRING("GODDAMMIT");
        return false;
        break;
      case HELL:
        SEND_STRING("HELL");
        return false;
        break;
      case ASS:
        SEND_STRING("ASS");
        return false;
        break;
      case ITERM:
        SEND_STRING(SS_LGUI(SS_TAP(X_SPACE)));
        _delay_ms(100);
        SEND_STRING("iterm");
        _delay_ms(100);
        SEND_STRING(SS_TAP(X_ENTER));
        return false;
        break;
      case VSCODE:
        SEND_STRING(SS_LGUI(SS_TAP(X_SPACE)));
        _delay_ms(100);
        SEND_STRING("vscode");
        _delay_ms(100);
        SEND_STRING(SS_TAP(X_ENTER));
        return false;
        break;
      case SPOTIF:
        SEND_STRING(SS_LGUI(SS_TAP(X_SPACE)));
        _delay_ms(100);
        SEND_STRING("spotify");
        _delay_ms(100);
        SEND_STRING(SS_TAP(X_ENTER));
        return false;
        break;
      case SLACK:  // Open Slack
        SEND_STRING(SS_LGUI(SS_TAP(X_SPACE)));
        _delay_ms(100);
        SEND_STRING("slack");
        _delay_ms(100);
        SEND_STRING(SS_TAP(X_ENTER));
        return false;
        break;
      case CHROME:  // Open Chrome
        SEND_STRING(SS_LGUI(SS_TAP(X_SPACE)));
        _delay_ms(100);
        SEND_STRING("chrome");
        _delay_ms(100);
        SEND_STRING(SS_TAP(X_ENTER));
        return false;
        break;
    }
  }
  return true;
}
