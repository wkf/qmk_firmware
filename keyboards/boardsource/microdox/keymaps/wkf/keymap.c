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
    _SLOWER,
    _RAISE,
    _MEDIA,
    _FUNCTION,
};

enum custom_keycodes {
  CS_DT = SAFE_RANGE,
  CS_CM,
  CS_BS,
  CS_FS,
  CS_EQ,
  CS_SC,
  CS_QU,
  CS_1,
  CS_2,
  CS_3,
  CS_4,
  CS_5,
  CS_6,
  CS_7,
  CS_8,
  CS_9,
};

#define ____ KC_TRANSPARENT

#define U_RDO SCMD(KC_Z)
#define U_PST LCMD(KC_V)
#define U_CPY LCMD(KC_C)
#define U_CUT LCMD(KC_X)
#define U_UND LCMD(KC_Z)

#define MT_O LALT_T(KC_O)
#define MT_A LGUI_T(KC_A)
#define MT_I LCTL_T(KC_I)
#define MT_N LSFT_T(KC_N)
#define MT_H LSFT_T(KC_H)
#define MT_T LCTL_T(KC_T)
#define MT_S LGUI_T(KC_S)
#define MT_R LALT_T(KC_R)

#define LT_E LT(_LOWER,KC_E)
#define LT_L LT(_SLOWER,KC_L)
#define LT_D LT(_MEDIA,KC_D)
#define LT_SPC LT(_RAISE,KC_SPC)

#define MO_FUN MO(_FUNCTION)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_split_3x5_3(
  KC_J,  KC_C, KC_G, KC_F, KC_K,   KC_Z, KC_M, KC_U,  CS_QU, KC_Q,
  MT_R,  MT_S, MT_T, MT_H, KC_Y,   KC_W, MT_N, MT_I,  MT_A,  MT_O,
  CS_SC, KC_B, KC_P, LT_D, KC_V,   KC_X, LT_L, CS_CM, CS_DT, KC_MINS,
               ____, ____, LT_SPC, LT_E, ____, ____
),
/* [_BASE] = LAYOUT_split_3x5_3( */
/*   KC_Z,    KC_C, KC_W, KC_K, KC_J,    KC_MINS, KC_M, KC_U,  CS_QU, KC_Q, */
/*   MT_D,    MT_S, MT_T, MT_H, KC_Y,    KC_F,    MT_N, MT_I,  MT_A,  MT_O, */
/*   KC_B,    KC_G, KC_P, LT_R, KC_V,    KC_X,    LT_L, CS_CM, CS_DT, CS_SC, */
/*                  ____, ____, LT_SPC,  LT_E,    ____, ____ */
/* ), */
/* [_BASE] = LAYOUT_split_3x5_3( */
/*   KC_Z,    KC_C, KC_W, KC_B, KC_J,  KC_MINS, KC_M, KC_U, CS_QU, KC_Q, */
/*   MT_D,    MT_S, MT_T, MT_H, KC_K,  KC_V,    MT_N, MT_I, MT_A,  MT_O, */
/*   KC_F,    KC_G, KC_P, LT_R, CS_SC, KC_X,    LT_L, KC_Y, CS_CM, CS_DT, */
/*                  ____, ____, LT_SPC,  LT_E,  ____, ____ */
/* ), */
/* [_BASE] = LAYOUT_split_3x5_3( */
/*   KC_Z,    KC_C, KC_W, KC_M, KC_J,  KC_X,    KC_B, KC_U, CS_CM, KC_Q, */
/*   MT_D,    MT_S, MT_T, MT_H, KC_K,  KC_V,    MT_N, MT_I, MT_A,  MT_O, */
/*   KC_F,    KC_G, KC_P, LT_L, CS_SC, KC_MINS, LT_R, KC_Y, CS_DT, CS_QU, */
/*                  ____, ____, LT_E,  LT_SPC,  ____, ____ */
/* ), */

[_LOWER] = LAYOUT_split_3x5_3(
  CS_BS,   CS_4,    CS_5,    CS_6,    KC_GRV,  ____, ____, ____, ____, ____,
  CS_FS,   CS_1,    CS_2,    CS_3,    CS_EQ,   ____, ____, ____, ____, ____,
  KC_LBRC, CS_7,    CS_8,    CS_9,    KC_RBRC, ____, ____, ____, ____, ____,
                    ____,    ____,    KC_0,    ____, ____, ____
),

[_SLOWER] = LAYOUT_split_3x5_3(
  KC_PLUS, KC_CIRC, KC_PERC, KC_DLR,  KC_TILD, ____, ____, ____, ____, ____,
  KC_LT,   KC_PIPE, KC_AT,   KC_HASH, KC_GT,   ____, ____, ____, ____, ____,
  KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, ____, ____, ____, ____, ____,
                    ____,    ____,    KC_RPRN, MO_FUN,    ____, ____
),

[_RAISE] = LAYOUT_split_3x5_3(
  ____, ____, ____, ____, ____, ____,    KC_TAB,  KC_ENT,  KC_ESC,  KC_DEL,
  ____, ____, ____, ____, ____, KC_CAPS, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT,
  ____, ____, ____, ____, ____, ____,    KC_HOME, KC_PGUP, KC_PGDN, KC_END,
                    ____, ____, ____,    KC_BSPC, ____, ____
),

[_MEDIA] = LAYOUT_split_3x5_3(
  ____, ____, ____, ____, ____, U_CUT,   U_CPY,   U_PST,   U_UND,   U_RDO,
  ____, ____, ____, ____, ____, KC_MUTE, KC_MPRV, KC_VOLU, KC_VOLD, KC_MNXT,
  ____, ____, ____, ____, ____, ____,    ____,    ____,    ____,    ____,
                    ____, ____, ____,    KC_MPLY, ____,    ____
),

[_FUNCTION] = LAYOUT_split_3x5_3(
  KC_F11, KC_F4, KC_F5, KC_F6, ____, ____, ____, ____, ____, ____,
  KC_F10, KC_F1, KC_F2, KC_F3, ____, ____, ____, ____, ____, ____,
  KC_F12, KC_F7, KC_F8, KC_F9, ____, ____, ____, ____, ____, ____,
                 ____,  ____,  ____, ____, ____,  ____
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
    case CS_DT:
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
    case CS_CM:
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
    case CS_BS:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code(KC_EQL);
        } else {
          register_code(KC_BSLASH);
        }
      } else {
        unregister_code(KC_EQL);
        unregister_code(KC_BSLASH);
      }
      return false;
    case CS_FS:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code(KC_COMMA);
        } else {
          register_code(KC_SLASH);
        }
      } else {
        unregister_code(KC_COMMA);
        unregister_code(KC_SLASH);
      }
      return false;
    case CS_EQ:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code(KC_DOT);
        } else {
          register_code(KC_EQL);
        }
      } else {
        unregister_code(KC_DOT);
        unregister_code(KC_EQL);
      }
      return false;
    case CS_SC:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code(KC_QUOT);
        } else {
          register_code(KC_SCLN);
        }
      } else {
        unregister_code(KC_QUOT);
        unregister_code(KC_SCLN);
      }
      return false;
    case CS_QU:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code(KC_SCLN);
        } else {
          register_code(KC_QUOT);
        }
      } else {
        unregister_code(KC_SCLN);
        unregister_code(KC_QUOT);
      }
      return false;
    case CS_1:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code(KC_BSLASH);
        } else {
          register_code(KC_1);
        }
      } else {
        unregister_code(KC_BSLASH);
        unregister_code(KC_1);
      }
      return false;
    case CS_2:
      if (record->event.pressed){
        register_code(KC_2);
      } else {
        unregister_code(KC_2);
      }
      return false;
    case CS_3:
      if (record->event.pressed){
        register_code(KC_3);
      } else {
        unregister_code(KC_3);
      }
      return false;
    case CS_4:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code(KC_6);
        } else {
          register_code(KC_4);
        }
      } else {
        unregister_code(KC_6);
        unregister_code(KC_4);
      }
      return false;
    case CS_5:
      if (record->event.pressed){
        register_code(KC_5);
      } else {
        unregister_code(KC_5);
      }
      return false;
    case CS_6:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code(KC_4);
        } else {
          register_code(KC_6);
        }
      } else {
        unregister_code(KC_4);
        unregister_code(KC_6);
      }
      return false;
    case CS_7:
      if (record->event.pressed){
        register_code(KC_7);
      } else {
        unregister_code(KC_7);
      }
      return false;
    case CS_8:
      if (record->event.pressed){
        register_code(KC_8);
      } else {
        unregister_code(KC_8);
      }
      return false;
    case CS_9:
      if (record->event.pressed){
        register_code(KC_9);
      } else {
        unregister_code(KC_9);
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
    case _SLOWER:
      oled_write_ln_P(PSTR("  ^"), false);
      oled_write_ln_P(PSTR("Layer: Shifted Lower"), false);
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
