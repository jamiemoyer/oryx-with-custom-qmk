#include QMK_KEYBOARD_H
#include "version.h"
#include "features/achordion.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
};

void matrix_scan_user(void) {
  achordion_task();
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,        
    KC_ESCAPE,      MT(MOD_LCTL, KC_A),MT(MOD_LALT, KC_S),MT(MOD_LGUI, KC_D),MT(MOD_LSFT, KC_F),ALL_T(KC_G),                                    ALL_T(KC_H),    MT(MOD_RSFT, KC_J),MT(MOD_RGUI, KC_K),MT(MOD_RALT, KC_L),MT(MOD_RCTL, KC_SCLN),KC_QUOTE,       
    KC_LEFT_SHIFT,  KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RIGHT_SHIFT, 
                                                    KC_SPACE,       LT(1,KC_DELETE),                                MT(MOD_LALT | MOD_LCTL | MOD_LSFT | MOD_LGUI, KC_ENTER),KC_BSPC
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_LBRC,        KC_LPRN,        KC_RPRN,        KC_RBRC,        KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_LCBR,        KC_PGDN,        KC_PAGE_UP,     KC_RCBR,        KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const uint16_t PROGMEM combo0[] = { MT(MOD_LSFT, KC_F), KC_R, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_COMMA, KC_M, COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_LEFT_SHIFT, KC_RIGHT_SHIFT, COMBO_END};
const uint16_t PROGMEM combo4[] = { KC_V, MT(MOD_LSFT, KC_F), COMBO_END};
const uint16_t PROGMEM combo5[] = { MT(MOD_LGUI, KC_D), MT(MOD_LSFT, KC_F), COMBO_END};
const uint16_t PROGMEM combo6[] = { MT(MOD_RSFT, KC_J), MT(MOD_RGUI, KC_K), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_GRAVE),
    COMBO(combo1, KC_LBRC),
    COMBO(combo2, KC_RBRC),
    COMBO(combo3, TG(1)),
    COMBO(combo4, KC_TILD),
    COMBO(combo5, KC_HYPR),
    COMBO(combo6, KC_HYPR),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_TAB:
            return TAPPING_TERM -50;
        case MT(MOD_LCTL, KC_A):
            return TAPPING_TERM + 45;
        case MT(MOD_LALT, KC_S):
            return TAPPING_TERM + 45;
        case MT(MOD_LGUI, KC_D):
            return TAPPING_TERM + 45;
        case MT(MOD_LSFT, KC_F):
            return TAPPING_TERM + 45;
        case ALL_T(KC_G):
            return TAPPING_TERM + 45;
        case LT(1,KC_DELETE):
            return TAPPING_TERM -25;
        case KC_BSLS:
            return TAPPING_TERM -50;
        case ALL_T(KC_H):
            return TAPPING_TERM + 45;
        case MT(MOD_RSFT, KC_J):
            return TAPPING_TERM + 45;
        case MT(MOD_RGUI, KC_K):
            return TAPPING_TERM + 45;
        case MT(MOD_RALT, KC_L):
            return TAPPING_TERM + 45;
        case MT(MOD_RCTL, KC_SCLN):
            return TAPPING_TERM + 45;
        case MT(MOD_LALT | MOD_LCTL | MOD_LSFT | MOD_LGUI, KC_ENTER):
            return TAPPING_TERM -25;
        default:
            return TAPPING_TERM;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [1] = { {76,244,238}, {220,218,204}, {86,255,255}, {86,255,255}, {86,255,255}, {220,218,204}, {76,244,238}, {220,218,204}, {86,255,255}, {86,255,255}, {86,255,255}, {220,218,204}, {0,0,0}, {220,218,204}, {86,255,255}, {86,255,255}, {86,255,255}, {220,218,204}, {0,0,0}, {220,218,204}, {86,255,255}, {86,255,255}, {86,255,255}, {220,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {40,233,255}, {40,233,255}, {40,233,255}, {0,0,0}, {76,244,238}, {0,0,0}, {40,233,255}, {0,0,0}, {40,233,255}, {0,0,0}, {76,244,238}, {139,235,255}, {139,235,255}, {139,235,255}, {139,235,255}, {255,218,204}, {76,244,238}, {139,235,255}, {139,235,255}, {139,235,255}, {139,235,255}, {255,218,204}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 1:
      set_layer_color(1);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   if (!process_achordion(keycode, record)) { return false; }
  switch (keycode) {

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}



