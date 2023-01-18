// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H
#include "features/achordion.h"

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
#define ALL(KC) HYPR_T(KC)

#define L1(KC) LT(_1, KC)
#define L2(KC) LT(_2, KC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_0] = LAYOUT_split_3x5_3(
         KC_J,      KC_C,       KC_Y,       KC_F, KC_K,      KC_Z,     KC_M,       KC_U,     CS_QU,      KC_Q,
    CMD(KC_R), ALT(KC_S),  CTL(KC_T),  SFT(KC_H), KC_P,      KC_W, SFT(KC_N), CTL(KC_I), ALT(KC_A), CMD(KC_O),
        CS_SC,      KC_V,       KC_G,       KC_D, KC_B,      KC_X,      KC_L,     CS_CM,     CS_DT,   KC_MINS,
        KC_ESC, L2(KC_SPC), KC_TAB, KC_BSPC,  L1(KC_E),    KC_ENT
  ),

  [_1] = LAYOUT_split_3x5_3(
    KC_HOME, KC_PGDN, KC_PGUP,   KC_END,    ____,    ____,      KC_F4,      KC_F5,      KC_F6,      KC_F11,
    KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, CW_TOGG,    ____, SFT(KC_F1), CTL(KC_F2), ALT(KC_F3), CMD(KC_F10),
       ____,    ____,    ____,     ____,    ____,    ____,      KC_F7,      KC_F8,      KC_F9,      KC_F12,
                                ____,     ____,    ____, QK_BOOT,       ____,     QK_RBT
),

  [_2] = LAYOUT_split_3x5_3(
    KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, ____,  KC_GRV, CS_4,   CS_5, CS_6,   CS_BS,
    KC_LCMD, KC_LALT, KC_LCTL, KC_LSFT, ____,   CS_EQ, CS_1,   CS_2, CS_3,   CS_FS,
       ____,    ____,    ____,    ____, ____, KC_LBRC, CS_7,   CS_8, CS_9, KC_RBRC,
                              KC_SPC,    ____, ____,  KC_DEL, CS_0, KC_INS
  ),
};

void matrix_scan_user(void) {
  achordion_task();
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
        if (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT)){
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
        if (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT)){
            tap_code16(to_keycode);
        } else {
            tap_code16(from_keycode);
        }
        return false;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) { return false; }

    switch (keycode) {
        case SFT(CS_1):
            return swap_mod_tap_shift_state(KC_1, KC_BSLS, record);
        case CTL(CS_2):
            return keep_mod_tap_shift_state(KC_2, record);
        case ALT(CS_3):
            return keep_mod_tap_shift_state(KC_3, record);
        case CMD(CS_FS):
            return swap_mod_tap_shift_state(KC_SLASH, KC_DOT, record);
        case CS_DT:
            return swap_shift_state(KC_DOT, KC_1, record);
        case CS_CM:
            return swap_shift_state(KC_COMMA, KC_SLASH, record);
        case CS_BS:
            return swap_shift_state(KC_BSLS, KC_EQL, record);
        case CS_FS:
            return swap_shift_state(KC_SLASH, KC_DOT, record);
        case CS_EQ:
            return swap_shift_state(KC_EQL, KC_COMMA, record);
        case CS_SC:
            return swap_shift_state(KC_SCLN, KC_QUOT, record);
        case CS_QU:
            return swap_shift_state(KC_QUOT, KC_SCLN, record);
        case CS_1:
            return swap_shift_state(KC_1, KC_BSLS, record);
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

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {

  // Also allow same-hand holds when the other key is in the rows below the
  // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
  if (other_record->event.key.col >= 3) { return true; }
  if (tap_hold_record->event.key.col >= 3) { return true; }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  return 500;  // Otherwise use a timeout of 800 ms.
}

bool achordion_eager_mod(uint8_t mod) {
  switch (mod) {
    case MOD_LSFT:
    case MOD_RSFT:
    case MOD_LCTL:
    case MOD_RCTL:
      return true;  // Eagerly apply Shift and Ctrl mods.

    default:
      return false;
  }
}

#ifdef OLED_ENABLE

static void render_status(void) {
  oled_write_P(PSTR("Layer: "), false);

  switch (get_highest_layer(layer_state)) {
    case _0:
      oled_write_P(PSTR("Base"), false);
      break;
    case _1:
      oled_write_P(PSTR("Navigation"), false);
      break;
    case _2:
      oled_write_P(PSTR("Numbers"), false);
      break;
    default:
      oled_write_P(PSTR("Unknown"), false);
  }

  oled_write_ln_P(is_caps_word_on() ? PSTR(" (!)") : PSTR("    "), false);
}

static void render_message(void) {
  oled_write_P(PSTR("Know thyself."), false);
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status();
  } else {
    render_message();
  }
  return false;
}

#endif

