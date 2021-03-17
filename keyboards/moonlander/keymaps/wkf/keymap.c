#include QMK_KEYBOARD_H
#include "version.h"
/* #include "keymap_german.h" */
/* #include "keymap_nordic.h" */
/* #include "keymap_french.h" */
/* #include "keymap_spanish.h" */
/* #include "keymap_hungarian.h" */
/* #include "keymap_swedish.h" */
/* #include "keymap_br_abnt2.h" */
/* #include "keymap_canadian_multilingual.h" */
/* #include "keymap_german_ch.h" */
/* #include "keymap_jp.h" */
/* #include "keymap_korean.h" */
/* #include "keymap_bepo.h" */
/* #include "keymap_italian.h" */
/* #include "keymap_slovenian.h" */
/* #include "keymap_danish.h" */
/* #include "keymap_norwegian.h" */
/* #include "keymap_portuguese.h" */
/* #include "keymap_contributions.h" */
/* #include "keymap_czech.h" */
/* #include "keymap_romanian.h" */
/* #include "keymap_russian.h" */
/* #include "keymap_uk.h" */
/* #include "keymap_estonian.h" */
/* #include "keymap_belgian.h" */
#include "keymap_us_international.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define MOON_LED_LEVEL LED_LEVEL

#define ____ KC_TRANSPARENT

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
};

/* enum combos { */
/*   QJ_ESCAPE, */
/*   WV_ENTER */
/* }; */

/* const uint16_t PROGMEM qj_combo[] = {KC_Q, KC_J, COMBO_END}; */
/* const uint16_t PROGMEM wv_combo[] = {KC_W, KC_V, COMBO_END}; */

/* combo_t key_combos[COMBO_COUNT] = { */
/*   [QJ_ESCAPE] = COMBO(qj_combo, KC_ESCAPE), */
/*   [WV_ENTER] = COMBO(wv_combo, KC_ENTER) */
/* }; */

/* enum dances { */
/*   TD_Q_ESC, */
/*   TD_SCOLON_SLASH, */
/* }; */

/* qk_tap_dance_action_t tap_dance_actions[] = { */
/*   [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESCAPE), */
/*   [TD_SCOLON_SLASH] = ACTION_TAP_DANCE_DOUBLE(KC_SCOLON, KC_SLASH) */
/* }; */

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_U):
          return TAPPING_TERM - 30;
        case RSFT_T(KC_H):
          return TAPPING_TERM - 30;
        /* case LT(1,KC_BSPACE): */
        /*   return TAPPING_TERM + 30; */
        /* case LT(2,KC_SPACE): */
        /*   return TAPPING_TERM + 30; */
        /* case LT(3,KC_ESCAPE): */
        /*   return TAPPING_TERM + 30; */
        /* case LT(4,KC_ENTER): */
        /*   return TAPPING_TERM + 30; */
        default:
            return TAPPING_TERM;
    }
}

#define MOD_LSALT MOD_LALT | MOD_LSFT
#define MOD_RSALT MOD_RALT | MOD_RSFT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
                          ____,                 ____,                    ____,               ____,              ____,                 ____,          ____,
                          ____,                 ____,                    ____,               ____,              ____,                 ____,          ____,

                          ____,                 KC_QUOTE,                KC_COMMA,           KC_DOT,            KC_P,                 KC_Y,          ____,
                          ____,                 KC_F,                    KC_G,               KC_C,              KC_R,                 KC_L,          ____,

                          ____,                 LALT_T(KC_A),            LGUI_T(KC_O),       LCTL_T(KC_E),      LSFT_T(KC_U),         KC_I,          ____,
                          ____,                 KC_D,                    RSFT_T(KC_H),       RCTL_T(KC_T),      RGUI_T(KC_N),         RALT_T(KC_S),  ____,

                          ____,                 KC_SCOLON,               KC_Q,               KC_J,              KC_K,                 KC_X,
                          KC_B,                 KC_M,                    KC_W,               KC_V,              KC_Z,                 ____,

                          ____,                 ____,                    ____,               ____,              LT(5,KC_DELETE),      ____,
                          ____,                 LT(6,KC_TAB),            ____,               ____,              ____,                 ____,

                          LT(1,KC_BSPACE),      LT(3,KC_ESCAPE),         ____,
                          ____,                 LT(4,KC_ENTER),          LT(2,KC_SPACE)
                          ),

  [1] = LAYOUT_moonlander(
                          ____,                 ____,                    ____,               ____,              ____,                 ____,          ____,
                          ____,                 ____,                    ____,               ____,              ____,                 ____,          ____,

                          ____,                 ____,                    ____,               ____,              ____,                 ____,          ____,
                          ____,                 KC_LBRC,                 KC_7,               KC_8,              KC_9,                 KC_RBRC,       ____,

                          ____,                 ____,                    ____,               ____,              ____,                 ____,          ____,
                          ____,                 KC_EQUAL,                KC_4,               KC_5,              KC_6,                 KC_SLASH,      ____,

                          ____,                 ____,                    ____,               ____,              ____,                 ____,
                          KC_BSLASH,            KC_1,                    KC_2,               KC_3,              KC_GRAVE,             ____,

                          ____,                 ____,                    ____,               ____,              ____,                 ____,
                          ____,                 ____,                    ____,               ____,              ____,                 ____,

                          ____,                 ____,                    ____,
                          ____,                 KC_MINUS,                KC_0
                          ),

  [2] = LAYOUT_moonlander(
                          ____,                 ____,                    ____,               ____,              ____,                 ____,          ____,
                          ____,                 ____,                    ____,               ____,              ____,                 ____,          ____,

                          ____,                 ____,                    ____,               ____,              ____,                 ____,          ____,
                          ____,                 ____,                    ____,               ____,              ____,                 ____,          ____,

                          ____,                 KC_LEFT,                 KC_DOWN,            KC_UP,             KC_RIGHT,             KC_CAPS,       ____,
                          ____,                 ____,                    ____,               ____,              ____,                 ____,          ____,

                          ____,                 KC_HOME,                 KC_PGDOWN,          KC_PGUP,           KC_END,               ____,
                          ____,                 ____,                    ____,               ____,              ____,                 ____,

                          ____,                 ____,                    ____,               ____,              ____,                 ____,
                          ____,                 ____,                    ____,               ____,              ____,                 ____,

                          ____,                 ____,                    ____,
                          ____,                 ____,                    ____
                          ),

  [3] = LAYOUT_moonlander(
                          ____,                 ____,                    ____,               ____,              ____,                 ____,          ____,
                          ____,                 ____,                    ____,               ____,              ____,                 ____,          ____,

                          ____,                 ____,                    ____,               ____,              ____,                 ____,          ____,
                          ____,                 KC_LCBR,                 KC_AMPR,            KC_ASTR,           KC_LPRN,              KC_RCBR,       ____,

                          ____,                 ____,                    ____,               ____,              ____,                 ____,          ____,
                          ____,                 KC_PLUS,                 KC_DLR,             KC_PERC,           KC_CIRC,              KC_QUES,       ____,

                          ____,                 ____,                    ____,               ____,              ____,                 ____,
                          KC_PIPE,              KC_EXLM,                 KC_AT,              KC_HASH,           KC_TILD,              ____,

                          ____,                 ____,                    ____,               ____,              ____,                 ____,
                          ____,                 ____,                    ____,               ____,              ____,                 ____,

                          ____,                 ____,                    ____,
                          ____,                 KC_UNDS,                 KC_RPRN
                          ),

  [4] = LAYOUT_moonlander(

                          ____,                 ____,                    ____,               ____,              ____,                 ____,          ____,
                          ____,                 ____,                    ____,               ____,              ____,                 ____,          ____,

                          ____,                 ____,                    ____,               LGUI(LSFT(KC_3)),  LGUI(LSFT(KC_4)),     ____,          ____,
                          ____,                 ____,                    ____,               ____,              ____,                 ____,          ____,

                          ____,                 KC_MEDIA_PREV_TRACK,     KC_AUDIO_VOL_DOWN,  KC_AUDIO_VOL_UP,   KC_MEDIA_NEXT_TRACK,  ____,          ____,
                          ____,                 ____,                    ____,               ____,              ____,                 ____,          ____,

                          ____,                 ____,                    ____,               ____,              LGUI(KC_BSLASH),      ____,
                          ____,                 ____,                    ____,               ____,              ____,                 ____,

                          ____,                 ____,                    ____,               ____,              ____,                 ____,
                          ____,                 ____,                    ____,               ____,              ____,                 ____,

                          KC_MEDIA_PLAY_PAUSE,  KC_AUDIO_MUTE,           ____,
                          ____,                 ____,                    ____
                          ),

  [5] = LAYOUT_moonlander(
                          ____,                 ____,                    ____,               ____,              ____,                 ____,          ____,
                          ____,                 ____,                    ____,               ____,              ____,                 ____,          ____,

                          ____,                 ____,                    ____,               ____,              ____,                 ____,          ____,
                          ____,                 KC_F5,                   KC_F6,              KC_F7,             KC_F12,               ____,          ____,

                          ____,                 ____,                    ____,               ____,              ____,                 ____,          ____,
                          ____,                 KC_F4,                   KC_F5,              KC_F6,             KC_F11,               ____,          ____,

                          ____,                 ____,                    ____,               ____,              ____,                 ____,
                          ____,                 KC_F1,                   KC_F2,              KC_F3,             KC_F10,               ____,

                          ____,                 ____,                    ____,               ____,              ____,                 ____,
                          ____,                 ____,                    ____,               ____,              ____,                 ____,

                          ____,                 ____,                    ____,
                          ____,                 RESET,                   ____
                          ),
  [6] = LAYOUT_moonlander(
                          ____,                 ____,                    ____,               ____,              ____,                 ____,          ____,
                          ____,                 ____,                    ____,               ____,              ____,                 ____,          ____,

                          ____,                 ____,                    ____,               ____,              ____,                 ____,          ____,
                          ____,                 ____,                    ____,               ____,              ____,                 ____,          ____,

                          ____,                 KC_MS_LEFT,              KC_MS_DOWN,         KC_MS_UP,          KC_MS_RIGHT,          ____,          ____,
                          ____,                 ____,                    ____,               ____,              ____,                 ____,          ____,

                          ____,                 KC_MS_WH_LEFT,           KC_MS_WH_DOWN,      KC_MS_WH_UP,       KC_MS_WH_RIGHT,       ____,
                          ____,                 ____,                    ____,               ____,              ____,                 ____,

                          ____,                 ____,                    ____,               ____,              ____,                 ____,
                          ____,                 ____,                    ____,               ____,              ____,                 ____,

                          KC_MS_BTN1,           KC_MS_BTN2,              ____,
                          ____,                 ____,                    ____
                          ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

#define C_NONE {0,0,0}
#define C_GREEN {85,203,158}
#define C_YELLOW {32,176,255}
#define C_ORANGE {10,225,255}
#define C_PINK {243,222,234}
#define C_BLUE {134,255,213}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
  [0] = {
    C_NONE,    C_NONE,    C_NONE,    C_NONE,    C_NONE,
    C_NONE,    C_GREEN,   C_YELLOW,  C_GREEN,   C_NONE,
    C_NONE,    C_GREEN,   C_YELLOW,  C_GREEN,   C_NONE,
    C_NONE,    C_GREEN,   C_YELLOW,  C_GREEN,   C_NONE,
    C_NONE,    C_GREEN,   C_YELLOW,  C_GREEN,   C_PINK,
    C_NONE,    C_GREEN,   C_GREEN,   C_GREEN,
    C_NONE,    C_NONE,    C_NONE,
    C_ORANGE,  C_BLUE,    C_NONE,    C_NONE,

    C_NONE,    C_NONE,    C_NONE,    C_NONE,    C_NONE,
    C_NONE,    C_GREEN,   C_YELLOW,  C_GREEN,   C_NONE,
    C_NONE,    C_GREEN,   C_YELLOW,  C_GREEN,   C_NONE,
    C_NONE,    C_GREEN,   C_YELLOW,  C_GREEN,   C_NONE,
    C_NONE,    C_GREEN,   C_YELLOW,  C_GREEN,   C_PINK,
    C_NONE,    C_GREEN,   C_GREEN,   C_GREEN,
    C_NONE,    C_NONE,    C_NONE,
    C_ORANGE,  C_BLUE,    C_NONE,    C_NONE
  },

  [1] = {
    C_NONE,    C_NONE,    C_NONE,    C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_YELLOW,  C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_YELLOW,  C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_YELLOW,  C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_YELLOW,  C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_NONE,
    C_ORANGE,  C_NONE,    C_NONE,    C_NONE,

    C_NONE,    C_NONE,    C_NONE,    C_NONE,    C_NONE,
    C_NONE,    C_ORANGE,  C_ORANGE,  C_ORANGE,  C_NONE,
    C_NONE,    C_ORANGE,  C_ORANGE,  C_ORANGE,  C_NONE,
    C_NONE,    C_ORANGE,  C_ORANGE,  C_ORANGE,  C_NONE,
    C_NONE,    C_ORANGE,  C_ORANGE,  C_ORANGE,  C_NONE,
    C_NONE,    C_ORANGE,  C_ORANGE,  C_ORANGE,
    C_NONE,    C_NONE,    C_NONE,
    C_ORANGE,  C_ORANGE,  C_NONE,    C_NONE
  },

  [2] = {
    C_NONE,    C_NONE,    C_NONE,    C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_ORANGE,  C_ORANGE,  C_NONE,
    C_NONE,    C_NONE,    C_ORANGE,  C_ORANGE,  C_NONE,
    C_NONE,    C_NONE,    C_ORANGE,  C_ORANGE,  C_NONE,
    C_NONE,    C_NONE,    C_ORANGE,  C_ORANGE,  C_NONE,
    C_NONE,    C_NONE,    C_ORANGE,  C_NONE,
    C_NONE,    C_NONE,    C_NONE,
    C_ORANGE,  C_ORANGE,  C_NONE,    C_NONE,

    C_NONE,    C_NONE,    C_NONE,    C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_YELLOW,  C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_YELLOW,  C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_YELLOW,  C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_YELLOW,  C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_NONE,
    C_ORANGE,  C_NONE,    C_NONE,    C_NONE
  },

  [3] = {
    C_NONE,    C_NONE,    C_NONE,    C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_YELLOW,  C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_YELLOW,  C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_YELLOW,  C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_YELLOW,  C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_NONE,
    C_NONE,    C_BLUE,    C_NONE,    C_NONE,

    C_NONE,    C_NONE,    C_NONE,    C_NONE,    C_NONE,
    C_NONE,    C_BLUE,    C_BLUE,    C_BLUE,    C_NONE,
    C_NONE,    C_BLUE,    C_BLUE,    C_BLUE,    C_NONE,
    C_NONE,    C_BLUE,    C_BLUE,    C_BLUE,    C_NONE,
    C_NONE,    C_BLUE,    C_BLUE,    C_BLUE,    C_NONE,
    C_NONE,    C_BLUE,    C_BLUE,    C_BLUE,
    C_NONE,    C_NONE,    C_NONE,
    C_BLUE,    C_BLUE,    C_NONE,    C_NONE
  },

  [4] = {
    C_NONE,    C_NONE,    C_NONE,    C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_BLUE,    C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_BLUE,    C_NONE,    C_NONE,
    C_NONE,    C_BLUE,    C_BLUE,    C_BLUE,    C_NONE,
    C_NONE,    C_BLUE,    C_BLUE,    C_BLUE,    C_NONE,
    C_NONE,    C_NONE,    C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_NONE,
    C_BLUE,    C_BLUE,    C_NONE,    C_NONE,

    C_NONE,    C_NONE,    C_NONE,    C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_YELLOW,  C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_YELLOW,  C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_YELLOW,  C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_YELLOW,  C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_NONE,
    C_NONE,    C_BLUE,    C_NONE,    C_NONE
  },

  [5] = {
    C_NONE,    C_NONE,    C_NONE,    C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_YELLOW,  C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_YELLOW,  C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_YELLOW,  C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_YELLOW,  C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_NONE,
    C_NONE,    C_PINK,    C_NONE,    C_NONE,

    C_NONE,    C_NONE,    C_NONE,    C_NONE,    C_NONE,
    C_NONE,    C_PINK,    C_PINK,    C_PINK,    C_NONE,
    C_NONE,    C_PINK,    C_PINK,    C_PINK,    C_NONE,
    C_NONE,    C_PINK,    C_PINK,    C_PINK,    C_NONE,
    C_NONE,    C_PINK,    C_PINK,    C_PINK,    C_NONE,
    C_NONE,    C_PINK,    C_PINK,    C_PINK,
    C_NONE,    C_NONE,    C_NONE,
    C_PINK,    C_PINK,    C_NONE,    C_NONE
  },

  [6] = {
    C_NONE,    C_NONE,    C_NONE,    C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_PINK,    C_PINK,    C_NONE,
    C_NONE,    C_NONE,    C_PINK,    C_PINK,    C_NONE,
    C_NONE,    C_NONE,    C_PINK,    C_PINK,    C_NONE,
    C_NONE,    C_NONE,    C_PINK,    C_PINK,    C_NONE,
    C_NONE,    C_NONE,    C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_NONE,
    C_PINK,    C_PINK,    C_NONE,    C_NONE,

    C_NONE,    C_NONE,    C_NONE,    C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_YELLOW,  C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_YELLOW,  C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_YELLOW,  C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_YELLOW,  C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_NONE,    C_NONE,
    C_NONE,    C_NONE,    C_NONE,
    C_NONE,    C_PINK,    C_NONE,    C_NONE
  },
};


void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
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

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}
