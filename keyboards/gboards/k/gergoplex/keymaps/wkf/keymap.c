/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

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
[_BASE] = LAYOUT_gergoplex(
  KC_J,  KC_C, KC_Y, KC_F, KC_K,   KC_Z, KC_M, KC_U,  CS_QU, KC_Q,
  MT_R,  MT_S, MT_T, MT_H, KC_P,   KC_W, MT_N, MT_I,  MT_A,  MT_O,
  CS_SC, KC_V, KC_G, LT_D, KC_B,   KC_X, LT_L, CS_CM, CS_DT, KC_MINS,
               ____, ____, LT_SPC, LT_E, ____, ____
),
/* [_BASE] = LAYOUT_gergoplex( */
/*   KC_Z,    KC_C, KC_W, KC_K, KC_J,    KC_MINS, KC_M, KC_U,  CS_QU, KC_Q, */
/*   MT_D,    MT_S, MT_T, MT_H, KC_Y,    KC_F,    MT_N, MT_I,  MT_A,  MT_O, */
/*   KC_B,    KC_G, KC_P, LT_R, KC_V,    KC_X,    LT_L, CS_CM, CS_DT, CS_SC, */
/*                  ____, ____, LT_SPC,  LT_E,    ____, ____ */
/* ), */
/* [_BASE] = LAYOUT_gergoplex( */
/*   KC_Z,    KC_C, KC_W, KC_B, KC_J,  KC_MINS, KC_M, KC_U, CS_QU, KC_Q, */
/*   MT_D,    MT_S, MT_T, MT_H, KC_K,  KC_V,    MT_N, MT_I, MT_A,  MT_O, */
/*   KC_F,    KC_G, KC_P, LT_R, CS_SC, KC_X,    LT_L, KC_Y, CS_CM, CS_DT, */
/*                  ____, ____, LT_SPC,  LT_E,  ____, ____ */
/* ), */
/* [_BASE] = LAYOUT_gergoplex( */
/*   KC_Z,    KC_C, KC_W, KC_M, KC_J,  KC_X,    KC_B, KC_U, CS_CM, KC_Q, */
/*   MT_D,    MT_S, MT_T, MT_H, KC_K,  KC_V,    MT_N, MT_I, MT_A,  MT_O, */
/*   KC_F,    KC_G, KC_P, LT_L, CS_SC, KC_MINS, LT_R, KC_Y, CS_DT, CS_QU, */
/*                  ____, ____, LT_E,  LT_SPC,  ____, ____ */
/* ), */

[_LOWER] = LAYOUT_gergoplex(
  CS_BS,   CS_4,    CS_5,    CS_6,    KC_GRV,  ____, ____, ____, ____, ____,
  CS_FS,   CS_1,    CS_2,    CS_3,    CS_EQ,   ____, ____, ____, ____, ____,
  KC_LBRC, CS_7,    CS_8,    CS_9,    KC_RBRC, ____, ____, ____, ____, ____,
                    ____,    ____,    KC_0,    ____, ____, ____
),

[_SLOWER] = LAYOUT_gergoplex(
  KC_PLUS, KC_CIRC, KC_PERC, KC_DLR,  KC_TILD, ____, ____, ____, ____, ____,
  KC_LT,   KC_PIPE, KC_AT,   KC_HASH, KC_GT,   ____, ____, ____, ____, ____,
  KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, ____, ____, ____, ____, ____,
                    ____,    ____,    KC_RPRN, MO_FUN,    ____, ____
),

[_RAISE] = LAYOUT_gergoplex(
  ____, ____, ____, ____, ____, ____,    KC_TAB,  KC_ENT,  KC_ESC,  KC_DEL,
  ____, ____, ____, ____, ____, KC_CAPS, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT,
  ____, ____, ____, ____, ____, ____,    KC_HOME, KC_PGUP, KC_PGDN, KC_END,
                    ____, ____, ____,    KC_BSPC, ____, ____
),

[_MEDIA] = LAYOUT_gergoplex(
  ____, ____, ____, ____, ____, U_CUT,   U_CPY,   U_PST,   U_UND,   U_RDO,
  ____, ____, ____, ____, ____, KC_MUTE, KC_MPRV, KC_VOLU, KC_VOLD, KC_MNXT,
  ____, ____, ____, ____, ____, ____,    ____,    ____,    ____,    ____,
                    ____, ____, ____,    KC_MPLY, ____,    ____
),

[_FUNCTION] = LAYOUT_gergoplex(
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

/* #define BASE 0 // default layer */
/* #define SYMB 1 // symbols */
/* #define NUMB 2 // numbers/motion */

/* Combomap
 *
 * ,-----------------------------.       ,--------------------------------.
 * |      |    ESC    |     |     |      |     |    ESC    |    BSLH      |
 * |-----+-----+-----+-----+------|      |--------------------------------|
 * |      |   BSPC   ENT    |     |      |    LES   COLN  GRT    |        |
 * |-----+-----+-----+--RMB+-LMB--+		   |--------------------------------|
 * |      |   MINS    |     |     |      |    QUO   UNDR   |     |        |
 * `------+-----+-----+------+----'		   `--------------------------------'
 *  .-------------------------.           .-----------------.
 *  |        |       |        |           |        |    |   |
 *  '-------------------------'           '-----------------'
 */

// Blank template at the bottom
/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
/* Keymap 0: Basic layer
 *
 * ,-----------------------------.       ,--------------------------------.
 * |    Q |  W  |  E  |  R  |  T  |      |  Y  |  U  |  I  |  O  |    P   |
 * |-----+-----+-----+-----+------|      |--------------------------------|
 * |CTRL/A|  S  |  D  |  F  |  G  |      |  H  |  J  |  K  |  L  | CTRL/; |
 * |-----+-----+-----+-----+------+		   |--------------------------------|
 * |SHFT/Z|  X  |  C  |  V  |  B  |      |  N  |  M  |  <  |  >  | SHFT/? |
 * `------+-----+-----+------+----'		   `--------------------------------'
 *  .-------------------------.           .-----------------.
 *  |ESC/META|ENT/ALT|SPC(SYM)|           |SPC(NUM)|BSPC|TAB|
 *  '-------------------------'           '-----------------'
 */
/* [BASE] = LAYOUT_gergoplex( */
/*     KC_Q,  			 			 KC_W, KC_E, KC_R, KC_T,  	KC_Y, KC_U, KC_I,    KC_O, 	 KC_P,  */
/*     MT(MOD_LCTL, KC_A),KC_S, KC_D, KC_F, KC_G,  	KC_H, KC_J, KC_K,    KC_L, 	 MT(MOD_LCTL, KC_SCLN), */
/*     MT(MOD_RSFT, KC_Z),KC_X, KC_C, KC_V, KC_B,  	KC_N, KC_M, KC_COMM, KC_DOT, MT(MOD_RSFT, KC_SLSH), */

/*  		MT(MOD_LGUI, KC_ESC), MT(MOD_LALT, KC_ENT), LT(SYMB, KC_SPC),									// Left */
/* 		LT(NUMB, KC_SPC), KC_LSFT, MT(MOD_RSFT, KC_TAB)																// Right */
/*     ), */
/* Keymap 1: Symbols layer
 * ,-----------------------------.       ,--------------------------------.
 * |  !   |  @  |  {  |  }  |       |  `  |  ~  |     |     |    \   |
 * |-----+-----+-----+-----+------|      |--------------------------------|
 * |  #   |  $  |  (  |  )  | LMB |      |  +  |  -  |  /  |  *  |    '   |
 * |-----+-----+-----+-----+------+		   |--------------------------------|
 * |  %   |  ^  |  [  |  ]  | RMB |      |  &  |  =  |  ,  |  .  |   -    |
 * `------+-----+-----+------+----'		   `--------------------------------'
 *  				.-----------------.           .------------------.
 *  				|MMB |  ;  	|	 = 	|						|  =  |  ;  |  DEL |
 *  				'-----------------'           '------------------'
 */
/* [SYMB] = LAYOUT_gergoplex( */
/*     KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,   KC_GRV,  KC_TILD, KC_TRNS, KC_TRNS, KC_BSLS, */
/*     KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_BTN2,   KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_QUOT, */
/*     KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_BTN1,   KC_AMPR, KC_EQL,  KC_COMM, KC_DOT,  KC_MINS, */
/*                       CMB_TOG, KC_SCLN, KC_EQL,   KC_EQL,  KC_SCLN, KC_DEL */
/*     ), */
/* Keymap 2: Pad/Function layer
 * ,-----------------------------.       ,-------------------------------.
 * |  1   |  2  |  3  |  4  |  5  |      |  6  |  7  |  8  |  9  |   0   |
 * |-----+-----+-----+-----+------|      |-------------------------------|
 * |  F1  | F2  | F3  | F4  |  F5 |      | LFT | DWN | UP  | RGT | VOLUP |
 * |-----+-----+-----+-----+------+		   |-------------------------------|
 * |  F6  | F7  | F8  | F9  | F10 |      |MLFT | MDWN| MUP | MRGT| VOLDN |
 * `------+-----+-----+------+----'		   `-------------------------------'
 *  				.-----------------.           .-----------------.
 *  				| F11 | F12|	  	|						|     | PLY | SKP |
 *  				'-----------------'           '-----------------'
 */
/* [NUMB] = LAYOUT_gergoplex( */
/*     KC_1,  KC_2,  KC_3,  KC_4,  KC_5,		 		KC_6,  	KC_7, 	 KC_8, 		KC_9, 	 KC_0, */
/*     KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,   		KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLU, */
/*     KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,  		KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_VOLD, */
/*      						  KC_F11,KC_F12,KC_TRNS,  	KC_TRNS,KC_MPLY,KC_MNXT */
/*     ) */
/* }; */
