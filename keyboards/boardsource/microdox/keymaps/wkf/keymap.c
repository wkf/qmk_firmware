/*
Copyright 2020 Cole Smith <cole@boadsource.xyz>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "split_util.h"

enum layers {
    _BASE,
    _LOWER,
    _RAISE,
    _MEDIA,
    _FUNCTION,
};

enum custom_keycodes {
  CS_DTEX = SAFE_RANGE,
  CS_CMQS,
  CS_BSLT,
  CS_FSGT,
  CS_1AMP,
  CS_2PPE,
  CS_3CIR,
  CS_4AT,
  CS_6PND,
  CS_7DLR,
};

#define ____ KC_TRANSPARENT

#define MT_O LALT_T(KC_O)
#define MT_A LGUI_T(KC_A)
#define MT_I LCTL_T(KC_I)
#define MT_N LSFT_T(KC_N)
#define MT_H LSFT_T(KC_H)
#define MT_T LCTL_T(KC_T)
#define MT_S LGUI_T(KC_S)
#define MT_R LALT_T(KC_R)

#define LT_E LT(_RAISE,KC_E)
#define LT_SPC LT(_LOWER,KC_SPC)

#define LT_0 LT(_MEDIA,KC_0)
#define LT_BSPC LT(_FUNCTION,KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_split_3x5_3(
  KC_QUOT, CS_CMQS, KC_U,    KC_M,    KC_Q,    KC_K,   KC_F,   KC_G,   KC_C, KC_J,
  MT_O,    MT_A,    MT_I,    MT_N,    KC_W,    KC_P,   MT_H,   MT_T,   MT_S, MT_R,
  KC_SCLN, CS_DTEX, KC_Y,    KC_L,    KC_X,    KC_Z,   KC_D,   KC_B,   KC_V, KC_MINS,
                    ____,    ____,    LT_SPC,  LT_E, ____, ____
),

[_LOWER] = LAYOUT_split_3x5_3(
  ____, ____, ____, ____, ____, KC_LBRC, CS_7DLR, KC_8,    KC_9,    KC_RBRC,
  ____, ____, ____, ____, ____, CS_BSLT, CS_4AT,  KC_5,    CS_6PND, CS_FSGT,
  ____, ____, ____, ____, ____, KC_GRV,  CS_1AMP, CS_2PPE, CS_3CIR, KC_EQL,
              ____, ____, ____, LT_0,    ____, ____
),

[_RAISE] = LAYOUT_split_3x5_3(
  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  ____,    ____, ____, ____, ____, ____,
  KC_DEL,  KC_ESC,  KC_ENT,  KC_TAB,  KC_CAPS, ____, ____, ____, ____, ____,
  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, ____,    ____, ____, ____, ____, ____,
                    ____,    ____,    LT_BSPC, ____, ____, ____
),

[_MEDIA] = LAYOUT_split_3x5_3(
  ____,    ____,    ____,    ____,    ____,    ____, ____, ____, ____, ____,
  KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MUTE, ____, ____, ____, ____, ____,
  ____,    ____,    ____,    ____,    ____,    ____, ____, ____, ____, ____,
                    ____,    ____,    KC_MPLY, ____, ____, ____
),

[_FUNCTION] = LAYOUT_split_3x5_3(
  ____, ____, ____, ____, ____, ____, KC_F5, KC_F6, KC_F7, KC_F12,
  ____, ____, ____, ____, ____, ____, KC_F4, KC_F5, KC_F6, KC_F11,
  ____, ____, ____, ____, ____, ____, KC_F1, KC_F2, KC_F3, KC_F10,
              ____, ____, ____, ____, ____,  ____
)

};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_U):
          return TAPPING_TERM - 30;
        case RSFT_T(KC_H):
          return TAPPING_TERM - 30;
        default:
            return TAPPING_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CS_DTEX:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code(KC_1);
        } else {
          register_code(KC_DOT);
        }
      } else {
        unregister_code(KC_1);
        unregister_code(KC_DOT);
      }
      return false;
    case CS_CMQS:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code(KC_SLSH);
        } else {
          register_code(KC_COMM);
        }
      } else {
        unregister_code(KC_SLSH);
        unregister_code(KC_COMM);
      }
      return false;
    case CS_BSLT:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code(KC_COMMA);
        } else {
          register_code(KC_BSLASH);
        }
      } else {
        unregister_code(KC_COMMA);
        unregister_code(KC_BSLASH);
      }
      return false;
    case CS_FSGT:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code(KC_DOT);
        } else {
          register_code(KC_SLASH);
        }
      } else {
        unregister_code(KC_DOT);
        unregister_code(KC_SLASH);
      }
      return false;
    case CS_1AMP:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code(KC_7);
        } else {
          register_code(KC_1);
        }
      } else {
        unregister_code(KC_7);
        unregister_code(KC_1);
      }
      return false;
    case CS_2PPE:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code(KC_BSLASH);
        } else {
          register_code(KC_2);
        }
      } else {
        unregister_code(KC_BSLASH);
        unregister_code(KC_2);
      }
      return false;
    case CS_3CIR:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code(KC_6);
        } else {
          register_code(KC_3);
        }
      } else {
        unregister_code(KC_6);
        unregister_code(KC_3);
      }
      return false;
    case CS_4AT:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code(KC_2);
        } else {
          register_code(KC_4);
        }
      } else {
        unregister_code(KC_2);
        unregister_code(KC_4);
      }
      return false;
    case CS_6PND:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code(KC_3);
        } else {
          register_code(KC_6);
        }
      } else {
        unregister_code(KC_3);
        unregister_code(KC_6);
      }
      return false;
    case CS_7DLR:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code(KC_4);
        } else {
          register_code(KC_7);
        }
      } else {
        unregister_code(KC_4);
        unregister_code(KC_7);
      }
      return false;
  }
  return true;
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master())
    return OLED_ROTATION_180;
  return rotation;
}

static void render_logo(void) {
  oled_write_P(PSTR("\n         λ"), false);
}

static void render_status(void) {
  oled_write_ln_P(PSTR("B L R M F"), false);

   switch (get_highest_layer(layer_state)) {
    case _BASE:
      oled_write_ln_P(PSTR("^"), false);
      oled_write_ln_P(PSTR("Layer: Base"), false);
      break;
    case _LOWER:
      oled_write_ln_P(PSTR("  ^"), false);
      oled_write_ln_P(PSTR("Layer: Lower"), false);
      break;
    case _RAISE:
      oled_write_ln_P(PSTR("    ^"), false);
      oled_write_ln_P(PSTR("Layer: Raise"), false);
      break;
    case _MEDIA:
      oled_write_ln_P(PSTR("      ^"), false);
      oled_write_ln_P(PSTR("Layer: Media"), false);
      break;
    case _FUNCTION:
      oled_write_ln_P(PSTR("        ^"), false);
      oled_write_ln_P(PSTR("Layer: Function"), false);
      break;
    default:
      oled_write_ln_P(PSTR(""), false);
      oled_write_ln_P(PSTR("Layer: Other"), false);
  }
}

void oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status();
  } else {
    render_logo();
  }
}

#endif
