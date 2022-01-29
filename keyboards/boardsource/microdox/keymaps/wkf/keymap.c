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
    _0,
    _1,
    _2,
    _3,
    _4,
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
  CS_0,
};

#define ____ KC_TRANSPARENT

#define SFT(KC) LSFT_T(KC)
#define CMD(KC) LGUI_T(KC)
#define ALT(KC) LALT_T(KC)
#define CTL(KC) LCTL_T(KC)

#define L1(KC) LT(_1, KC)
#define L2(KC) LT(_2, KC)
#define L3(KC) LT(_3, KC)
#define L4(KC) LT(_4, KC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_0] = LAYOUT_split_3x5_3(
            KC_J,         KC_C,         KC_Y,      L4(KC_F),        KC_K,        KC_Z,         KC_M,      KC_U,         CS_QU,       KC_Q,
       CTL(KC_R),    ALT(KC_S),    CMD(KC_T),     SFT(KC_H),        KC_P,        KC_W,    SFT(KC_N), CMD(KC_I),     ALT(KC_A),  CTL(KC_O),
           CS_SC,         KC_V,         KC_G,      L3(KC_D),        KC_B,        KC_X,     L4(KC_L),     CS_CM,         CS_DT,    KC_MINS,
                                        ____,          ____,  L1(KC_SPC),    L2(KC_E),         ____,      ____
  ),

  [_1] = LAYOUT_split_3x5_3(
            ____,      KC_MUTE,      KC_MPLY,        KC_TAB,        ____,      KC_GRV,         CS_4,       CS_5,         CS_6,      CS_BS,
    CTL(KC_MPRV), ALT(KC_VOLD), CMD(KC_VOLU),  SFT(KC_MNXT),        ____,       CS_EQ,         CS_1,       CS_2,         CS_3,      CS_FS,
         KC_CAPS,         ____,         ____,        KC_SPC,        ____,     KC_LBRC,         CS_7,       CS_8,         CS_9,    KC_RBRC,
                                        ____,          ____,        ____,        CS_0,         ____,       ____
  ),

  [_2] = LAYOUT_split_3x5_3(
          KC_DEL,       KC_ESC,       KC_ENT,        KC_TAB,        ____,        ____,         ____,       ____,         ____,       ____,
         KC_LEFT,      KC_DOWN,        KC_UP,      KC_RIGHT,        ____,        ____,         ____,       ____,         ____,       ____,
         KC_HOME,      KC_PGDN,      KC_PGUP,        KC_END,        ____,        ____,         ____,       ____,         ____,       ____,
                                        ____,          ____,     KC_BSPC,        ____,         ____,       ____
  ),

  [_3] = LAYOUT_split_3x5_3(
            ____,         ____,         ____,          ____,        ____,     KC_TILD,       KC_DLR,    KC_PERC,      KC_CIRC,    KC_PLUS,
            ____,         ____,         ____,          ____,        ____,       KC_LT,      KC_PIPE,      KC_AT,      KC_HASH,      KC_GT,
            ____,         ____,         ____,          ____,        ____,     KC_LCBR,      KC_AMPR,    KC_ASTR,      KC_RPRN,    KC_RCBR,
                                        ____,          ____,      KC_SPC,     KC_LPRN,         ____,       ____
  ),

  [_4] = LAYOUT_split_3x5_3(
           KC_F5,        KC_F6,        KC_F7,         KC_F8,        ____,        ____,         ____,       ____,         ____,       ____,
           KC_F1,        KC_F2,        KC_F3,         KC_F4,        ____,        ____,         ____,       ____,         ____,       ____,
           KC_F9,       KC_F10,       KC_F11,        KC_F12,        ____,        ____,         ____,       ____,         ____,       ____,
                                        ____,          ____,      KC_TAB,        ____,         ____,       ____
  ),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT(KC_H):
            return TAPPING_TERM - 30;
        case SFT(KC_N):
            return TAPPING_TERM - 30;
        case SFT(KC_MNXT):
            return TAPPING_TERM - 30;
        case L3(KC_D):
            return TAPPING_TERM - 30;
        case L4(KC_F):
            return TAPPING_TERM - 30;
        default:
            return TAPPING_TERM;
    }
}

void keep_shift_state(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed){
        register_code(keycode);
    } else {
        unregister_code(keycode);
     }
}

void swap_shift_state(uint16_t from_keycode, uint16_t to_keycode, keyrecord_t *record ) {
    if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
            register_code(to_keycode);
        } else {
            register_code(from_keycode);
        }
    } else {
        unregister_code(to_keycode);
        unregister_code(from_keycode);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CS_DT:
            swap_shift_state(KC_DOT, KC_1, record);
            return false;
        case CS_CM:
            swap_shift_state(KC_COMMA, KC_SLASH, record);
            return false;
        case CS_BS:
            swap_shift_state(KC_BSLASH, KC_EQL, record);
            return false;
        case CS_FS:
            swap_shift_state(KC_SLASH, KC_COMMA, record);
            return false;
        case CS_EQ:
            swap_shift_state(KC_EQL, KC_DOT, record);
            return false;
        case CS_SC:
            swap_shift_state(KC_SCLN, KC_QUOT, record);
            return false;
        case CS_QU:
            swap_shift_state(KC_QUOT, KC_SCLN, record);
            return false;
        case CS_1:
            swap_shift_state(KC_1, KC_BSLASH, record);
            return false;
        case CS_2:
            keep_shift_state(KC_2, record);
            return false;
        case CS_3:
            keep_shift_state(KC_3, record);
            return false;
        case CS_4:
            keep_shift_state(KC_4, record);
            return false;
        case CS_5:
            keep_shift_state(KC_5, record);
            return false;
        case CS_6:
            keep_shift_state(KC_6, record);
            return false;
        case CS_7:
            keep_shift_state(KC_7, record);
            return false;
        case CS_8:
            keep_shift_state(KC_8, record);
            return false;
        case CS_9:
            swap_shift_state(KC_9, KC_0, record);
            return false;
        case CS_0:
            swap_shift_state(KC_0, KC_9, record);
            return false;
        default:
            return true;
  }
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master())
    return OLED_ROTATION_180;
  return rotation;
}

static void render_logo(void) {
  oled_write_P(PSTR("\n         < 3"), false);
}

static void render_status(void) {
  oled_write_ln_P(PSTR("0 1 2 3 4"), false);

   switch (get_highest_layer(layer_state)) {
    case _0:
      oled_write_ln_P(PSTR("^"), false);
      oled_write_ln_P(PSTR("Layer: 0"), false);
      break;
    case _1:
      oled_write_ln_P(PSTR("  ^"), false);
      oled_write_ln_P(PSTR("Layer: 1"), false);
      break;
    case _2:
      oled_write_ln_P(PSTR("    ^"), false);
      oled_write_ln_P(PSTR("Layer: 2"), false);
      break;
    case _3:
      oled_write_ln_P(PSTR("      ^"), false);
      oled_write_ln_P(PSTR("Layer: 3"), false);
      break;
    case _4:
      oled_write_ln_P(PSTR("        ^"), false);
      oled_write_ln_P(PSTR("Layer: 4"), false);
      break;
    default:
      oled_write_ln_P(PSTR(""), false);
      oled_write_ln_P(PSTR("Layer: ?"), false);
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
