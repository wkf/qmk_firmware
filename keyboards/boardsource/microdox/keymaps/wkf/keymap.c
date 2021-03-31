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
    _ALPHAS,
    _NUMBERS,
    _NAVIGATION,
    _SYMBOLS,
    _MEDIA,
    _FUNCTION,
    _MOUSE,
};

enum custom_keycodes {
  CS_DTQS = SAFE_RANGE,
  CS_CMEX,
  CS_BSLT,
  CS_FSGT,
  CS_P1PE
};

#define ____ KC_TRANSPARENT

#define MT_A LALT_T(KC_A)
#define MT_O LGUI_T(KC_O)
#define MT_E LCTL_T(KC_E)
#define MT_U LSFT_T(KC_U)
#define MT_H LSFT_T(KC_H)
#define MT_T LCTL_T(KC_T)
#define MT_N LGUI_T(KC_N)
#define MT_S LALT_T(KC_S)

#define LT_BSPC LT(1,KC_BSPC)
#define LT_SPC LT(2,KC_SPC)
#define LT_ESC LT(3,KC_ESC)
#define LT_ENT LT(4,KC_ENT)
#define LT_DEL LT(5,KC_DEL)
#define LT_TAB LT(6,KC_TAB)


/* [\- \. \u \m \q \k \f \c \g \j */
/*  \o \a \i \n \w \p \h \s \t \r */
/*  \' \, \y \l \x \v \d \b \z \; */
/*  \e \space] */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_ALPHAS] = LAYOUT_split_3x5_3(
  KC_QUOT, CS_CMEX, CS_DTQS, KC_P,    KC_Y,    KC_F,   KC_G,   KC_C,   KC_R, KC_L,
  MT_A,    MT_O,    MT_E,    MT_U,    KC_I,    KC_D,   MT_H,   MT_T,   MT_N, MT_S,
  KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,   KC_M,   KC_W,   KC_V, KC_Z,
                    LT_DEL,  LT_ESC,  LT_BSPC, LT_SPC, LT_ENT, LT_TAB
),

[_NUMBERS] = LAYOUT_split_3x5_3(
  ____, ____, ____, ____, ____, KC_LBRC, KC_7,    KC_8, KC_9, KC_RBRC,
  ____, ____, ____, ____, ____, CS_BSLT, KC_4,    KC_5, KC_6, CS_FSGT,
  ____, ____, ____, ____, ____, KC_EQL,  CS_P1PE, KC_2, KC_3, KC_GRV,
              ____, ____, ____, KC_0,    KC_MINS, ____
),

[_NAVIGATION] = LAYOUT_split_3x5_3(
  ____,    ____,    ____,    ____,    ____,   ____, ____, ____, ____, ____,
  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, ____,   ____, ____, ____, ____, ____,
  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  ____,   ____, ____, ____, ____, ____,
                    ____,    KC_CAPS, KC_TAB, ____, ____, ____
),

[_SYMBOLS] = LAYOUT_split_3x5_3(
  ____, ____, ____, ____, ____, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,
  ____, ____, ____, ____, ____, KC_LT,   KC_DLR,  KC_PERC, KC_CIRC, KC_GT,
  ____, ____, ____, ____, ____, KC_PLUS, KC_PIPE, KC_AT,   KC_HASH, KC_PLUS,
              ____, ____, ____, KC_RPRN, KC_UNDS, ____
),

[_MEDIA] = LAYOUT_split_3x5_3(
  ____,    ____,    ____,    ____,    ____, ____, ____, ____, ____, ____,
  KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, ____, ____, ____, ____, ____, ____,
  ____,    ____,    ____,    ____,    ____, ____, ____, ____, ____, ____,
                    ____,    KC_MUTE, KC_MPLY, ____, ____, ____
),

[_FUNCTION] = LAYOUT_split_3x5_3(
  ____, ____, ____, ____, ____, ____, KC_F5, KC_F6, KC_F7, KC_F12,
  ____, ____, ____, ____, ____, ____, KC_F4, KC_F5, KC_F6, KC_F11,
  ____, ____, ____, ____, ____, ____, KC_F1, KC_F2, KC_F3, KC_F10,
              ____, ____, ____, ____, ____,  ____
),

[_MOUSE] = LAYOUT_split_3x5_3(
  ____,    ____,    ____,    ____,    ____,    ____, ____, ____, ____, ____,
  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, ____,    ____, ____, ____, ____, ____,
  ____,    KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, ____, ____, ____, ____, ____,
                    ____,    KC_BTN2, KC_BTN1, ____, ____, ____
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
    case CS_DTQS:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code(KC_SLSH);
        } else {
          register_code(KC_DOT);
        }
      } else {
        unregister_code(KC_SLSH);
        unregister_code(KC_DOT);
      }
      return false;
    case CS_CMEX:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code(KC_1);
        } else {
          register_code(KC_COMM);
        }
      } else {
        unregister_code(KC_1);
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
    case CS_P1PE:
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
  oled_write_ln_P(PSTR("A N n S M F m"), false);

   switch (get_highest_layer(layer_state)) {
    case _ALPHAS:
      oled_write_ln_P(PSTR("^"), false);
      oled_write_ln_P(PSTR("Layer: Alphas"), false);
      break;
    case _NUMBERS:
      oled_write_ln_P(PSTR("  ^"), false);
      oled_write_ln_P(PSTR("Layer: Numbers"), false);
      break;
    case _NAVIGATION:
      oled_write_ln_P(PSTR("    ^"), false);
      oled_write_ln_P(PSTR("Layer: Navigation"), false);
      break;
    case _SYMBOLS:
      oled_write_ln_P(PSTR("      ^"), false);
      oled_write_ln_P(PSTR("Layer: Symbols"), false);
      break;
    case _MEDIA:
      oled_write_ln_P(PSTR("        ^"), false);
      oled_write_ln_P(PSTR("Layer: Media"), false);
      break;
    case _FUNCTION:
      oled_write_ln_P(PSTR("          ^"), false);
      oled_write_ln_P(PSTR("Layer: Function"), false);
      break;
    case _MOUSE:
      oled_write_ln_P(PSTR("            ^"), false);
      oled_write_ln_P(PSTR("Layer: Mouse"), false);
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
