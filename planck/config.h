#pragma once
#include "config_common.h"

#define STARTUP_SONG SONG(PLANCK_SOUND)

#define PERMISSIVE_HOLD    // https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#permissive-hold
#define TAPPING_FORCE_HOLD // https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#tapping-force-hold

#undef TAPPING_TERM
#define TAPPING_TERM 200
