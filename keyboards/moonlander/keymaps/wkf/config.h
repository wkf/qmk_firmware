/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef TAPPING_TERM
#define TAPPING_TERM 140
#define TAPPING_TERM_PER_KEY

#define PERMISSIVE_HOLD

#define IGNORE_MOD_TAP_INTERRUPT

#define BILATERAL_COMBINATIONS

/* #define NO_AUTO_SHIFT_ALPHA */
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP

#define RETRO_SHIFT 500

#undef RGB_DISABLE_TIMEOUT
#define RGB_DISABLE_TIMEOUT 60000

#define FIRMWARE_VERSION u8"L4xAX/GMbWa"
#define RGB_MATRIX_STARTUP_SPD 60

/* #undef COMBO_COUNT */
/* #define COMBO_COUNT 2 */
