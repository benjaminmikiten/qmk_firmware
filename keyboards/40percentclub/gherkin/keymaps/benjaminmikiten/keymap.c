#include QMK_KEYBOARD_H


// TAP DANCE LM -- 2x tap == LM


#define SPC_RSE  LT(1, KC_SPC)
#define ENT_LWR LT(2, KC_ENT)

#define COPY  LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define CUT   LCTL(KC_X)
#define UNDO  LCTL(KC_Z)

#define SSHT  SWIN(KC_S)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_ortho_3x10(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_BSPC,
    KC_Z,    KC_X,    KC_C,    KC_V,    ENT_LWR, SPC_RSE,  KC_B,    KC_N,    KC_M,    KC_LSFT
  ),

  [1] = LAYOUT_ortho_3x10(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_ESC,  SSHT,    _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,
    UNDO,    CUT,     COPY,    PASTE,   _______, _______, RESET,   _______, _______, _______
  ),

  [2] = LAYOUT_ortho_3x10(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,
    KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, _______, _______, _______, KC_SCLN,  KC_QUOT,
    RESET,   KC_F11,  KC_F12,  _______, _______, _______, KC_COMM, KC_DOT,  KC_SLSH,  _______
  ),


};

void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

  // Set our LED pins as output
  setPinOutput(D5);
  setPinOutput(B0);
}

void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
    writePinLow(D5);
  } else {
    writePinHigh(D5);
  }

  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinLow(B0);
  } else {
    writePinHigh(B0);
  }
}
