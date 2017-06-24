#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"


#include "keymap_german.h"

#include "keymap_nordic.h"



enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = KEYMAP(KC_EQUAL,KC_1,KC_2,KC_3,KC_4,KC_5,KC_LEFT,KC_DELETE,KC_Q,KC_W,KC_E,KC_R,KC_T,TG(1),KC_BSPACE,KC_A,KC_S,KC_D,KC_F,KC_G,KC_LSHIFT,CTL_T(KC_Z),KC_X,KC_C,KC_V,KC_B,ALL_T(KC_NO),KC_TRANSPARENT,KC_QUOTE,LALT(KC_LSHIFT),KC_LEFT,KC_RIGHT,ALT_T(KC_APPLICATION),KC_LGUI,KC_HOME,KC_SPACE,KC_BSPACE,KC_END,KC_RIGHT,KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINUS,TG(1),KC_Y,KC_U,KC_I,KC_O,KC_P,KC_BSLASH,KC_H,KC_J,KC_K,KC_L,LT(2,KC_SCOLON),GUI_T(KC_QUOTE),MEH_T(KC_NO),KC_N,KC_M,KC_COMMA,KC_DOT,CTL_T(KC_SLASH),KC_RSHIFT,KC_UP,KC_DOWN,KC_LBRACKET,KC_RBRACKET,MO(1),KC_LALT,CTL_T(KC_ESCAPE),KC_PGUP,KC_PGDOWN,KC_TAB,KC_ENTER),

  [1] = KEYMAP(KC_AMPR,KC_1,KC_2,KC_3,KC_4,KC_5,KC_LBRACKET,KC_PIPE,KC_QUOTE,KC_COMMA,KC_DOT,KC_P,KC_Y,KC_LPRN,KC_CAPSLOCK,KC_A,KC_O,KC_E,KC_U,KC_I,KC_UNDS,KC_SCOLON,KC_Q,KC_J,KC_K,KC_X,KC_DELETE,MO(2),KC_SLASH,KC_EXLM,KC_LEFT,KC_RIGHT,KC_LALT,KC_HOME,KC_LSHIFT,KC_SPACE,KC_BSPACE,KC_LCTL,KC_RBRACKET,KC_6,KC_7,KC_8,KC_9,KC_0,KC_PLUS,KC_RPRN,KC_F,KC_G,KC_C,KC_R,KC_L,KC_KP_ASTERISK,KC_D,KC_H,KC_T,KC_N,KC_S,KC_MINUS,KC_INSERT,KC_B,KC_M,KC_W,KC_V,KC_Z,KC_EQUAL,KC_UP,KC_DOWN,KC_QUES,KC_GRAVE,KC_TRANSPARENT,KC_END,KC_ESCAPE,KC_RSHIFT,KC_LCTL,KC_TAB,KC_ENTER),

  [2] = KEYMAP(KC_TRANSPARENT,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_UP,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_BTN1,KC_MS_BTN2,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_TRANSPARENT,KC_KP_7,KC_KP_8,KC_KP_9,KC_TRANSPARENT,KC_TRANSPARENT,KC_F12,KC_KP_4,KC_KP_5,KC_KP_6,KC_TRANSPARENT,KC_TRANSPARENT,KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT,KC_KP_1,KC_KP_2,KC_KP_3,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_KP_0,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,MO(3),KC_KP_ASTERISK,KC_KP_MINUS,KC_KP_SLASH,KC_KP_DOT,KC_KP_PLUS,KC_EQUAL),

  [3] = KEYMAP(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_EXLM,KC_AT,KC_LCBR,KC_RCBR,KC_PIPE,KC_TRANSPARENT,KC_TRANSPARENT,KC_HASH,KC_DLR,KC_LPRN,KC_RPRN,KC_GRAVE,KC_TRANSPARENT,KC_PERC,KC_CIRC,KC_LBRACKET,KC_RBRACKET,KC_TILD,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_SCOLON,KC_QUES,KC_COMMA,KC_MINUS,KC_DOT,KC_TRANSPARENT,KC_SLASH,KC_BSLASH,KC_QUOTE,KC_AMPR,KC_ASTR,KC_TRANSPARENT,KC_TRANSPARENT,KC_COLN,KC_UNDS,KC_DQUO,KC_LABK,KC_RABK,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;
    
  }
  return true;
}

void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

};
