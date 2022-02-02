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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_0] = LAYOUT_split_3x5_3(
            KC_J,         KC_C,         KC_Y,          KC_F,        KC_K,        KC_Z,         KC_M,      KC_U,         CS_QU,        KC_Q,
       CTL(KC_R),    ALT(KC_S),    CMD(KC_T),     SFT(KC_H),        KC_P,        KC_W,    SFT(KC_N), CMD(KC_I),     ALT(KC_A),   CTL(KC_O),
           CS_SC,         KC_V,         KC_G,          KC_D,        KC_B,        KC_X,         KC_L,     CS_CM,         CS_DT,     KC_MINS,
                                        ____,          ____,  L2(KC_SPC),    L1(KC_E),         ____,      ____
  ),

  [_1] = LAYOUT_split_3x5_3(
            ____,         ____,         ____,          ____,        ____,        ____,        KC_F4,      KC_F5,        KC_F6,      KC_F11,
    CTL(KC_LEFT), ALT(KC_DOWN),   CMD(KC_UP), SFT(KC_RIGHT),        ____,     KC_CAPS,   SFT(KC_F1), CMD(KC_F2),   ALT(KC_F3), CTL(KC_F10),
         KC_HOME,      KC_PGDN,      KC_PGUP,        KC_END,        ____,        ____,        KC_F7,      KC_F8,        KC_F9,      KC_F12,
                                        ____,          ____,        ____,        ____,         ____,       ____
  ),

  [_2] = LAYOUT_split_3x5_3(
            ____,         ____,       KC_SPC,          ____,        ____,      KC_GRV,         CS_4,       CS_5,         CS_6,       CS_BS,
     CTL(KC_ESC),  ALT(KC_TAB),  CMD(KC_ENT),  SFT(KC_BSPC),        ____,       CS_EQ,    SFT(CS_1),  CMD(CS_2),    ALT(CS_3),  CTL(CS_FS),
            ____,         ____,         ____,        KC_DEL,        ____,     KC_LBRC,         CS_7,       CS_8,         CS_9,     KC_RBRC,
                                        ____,          ____,        ____,        CS_0,         ____,       ____
  ),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT(KC_H):
        case SFT(KC_N):
        case SFT(KC_RIGHT):
        case SFT(KC_F1):
        case SFT(KC_BSPC):
        case SFT(CS_1):
            return TAPPING_TERM - 30;
        default:
            return TAPPING_TERM;
    }
}

bool keep_shift_state(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed){
        register_code(keycode);
    } else {
        unregister_code(keycode);
    }
    return false;
}

bool swap_shift_state(uint16_t from_keycode, uint16_t to_keycode, keyrecord_t *record ) {
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
    return false;
}

bool keep_mod_tap_shift_state(uint16_t keycode, keyrecord_t *record) {
    if (record->tap.count && record->event.pressed) {
        tap_code16(keycode);
        return false;
    }
    return true;
}

 bool swap_mod_tap_shift_state(uint16_t from_keycode, uint16_t to_keycode, keyrecord_t *record ) {
    if (record->tap.count && record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
            tap_code16(to_keycode);
        } else {
            tap_code16(from_keycode);
        }
        return false;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT(CS_1):
            return swap_mod_tap_shift_state(KC_1, KC_BSLASH, record);
        case CMD(CS_2):
            return keep_mod_tap_shift_state(KC_2, record);
        case ALT(CS_3):
            return keep_mod_tap_shift_state(KC_3, record);
        case CTL(CS_FS):
            return swap_mod_tap_shift_state(KC_SLASH, KC_DOT, record);
        case CS_DT:
            return swap_shift_state(KC_DOT, KC_1, record);
        case CS_CM:
            return swap_shift_state(KC_COMMA, KC_SLASH, record);
        case CS_BS:
            return swap_shift_state(KC_BSLASH, KC_EQL, record);
        case CS_FS:
            return swap_shift_state(KC_SLASH, KC_DOT, record);
        case CS_EQ:
            return swap_shift_state(KC_EQL, KC_COMMA, record);
        case CS_SC:
            return swap_shift_state(KC_SCLN, KC_QUOT, record);
        case CS_QU:
            return swap_shift_state(KC_QUOT, KC_SCLN, record);
        case CS_1:
            return swap_shift_state(KC_1, KC_BSLASH, record);
        case CS_2:
            return keep_shift_state(KC_2, record);
        case CS_3:
            return keep_shift_state(KC_3, record);
        case CS_4:
            return keep_shift_state(KC_4, record);
        case CS_5:
            return keep_shift_state(KC_5, record);
        case CS_6:
            return keep_shift_state(KC_6, record);
        case CS_7:
            return keep_shift_state(KC_7, record);
        case CS_8:
            return keep_shift_state(KC_8, record);
        case CS_9:
            return swap_shift_state(KC_9, KC_0, record);
        case CS_0:
            return swap_shift_state(KC_0, KC_9, record);
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
  oled_write_P(PSTR("\n         <3"), false);
}

static void render_status(void) {
  oled_write_ln_P(PSTR("0 1 2"), false);

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
