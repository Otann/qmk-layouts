#pragma once
#include "config_common.h"

#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(PLANCK_SOUND)
#endif

#define PERMISSIVE_HOLD    // https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#permissive-hold
#define TAPPING_FORCE_HOLD // https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#tapping-force-hold

#undef TAPPING_TERM
#define TAPPING_TERM 200

// https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgblight
// #define RGBLIGHT_DEFAULT_HUE 190 
// #define RGBLIGHT_DEFAULT_SAT 0
// #define RGBLIGHT_DEFAULT_VAL 255
