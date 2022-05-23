/* Copyright 2021 Anton Chebotaev */

#include QMK_KEYBOARD_H
#include "config.h"

enum planck_layers {
  _QWERTY,
  _COLEMAK_DH,
  _LOWER,  // ↙︎
  _RAISE,  // ↗︎
  _ADJUST, // ↘︎
  _FN      // ↖︎
};


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *  You can use _______ in place for KC_TRNS (transparent)   *
 *  Or you can use XXXXXXX for KC_NO (NOOP)                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// Layer switching
#define FN      MO(_FN)
#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define ADJUST  MO(_ADJUST)
#define LOWER_T TG(_LOWER)
#define RAISE_T TG(_RAISE)
#define ENT_RSE LT(_RAISE, KC_ENT)
#define CMD_RSE LM(_RAISE, MOD_RGUI)

#define T_QWERT DF(_QWERTY)
#define T_COLEM DF(_COLEMAK_DH)

// Pre-baked shortcuts
#define PRV_TAB LCMD(KC_LCBR)
#define NXT_TAB LCMD(KC_RCBR)
#define CMD_ENT LCMD(KC_ENT)
#define CMD_S_4 SCMD(KC_4)            // macos screenshot
#define CMD_S_3 SCMD(KC_3)
#define LANG_SW LALT(KC_SPC)          // my language switching combo
#define UMLAUT  LALT(KC_U)            // umlaut prefix for ä and ö
#define A_RING  LALT(KC_A)            // umlaut prefix for ä and ö
#define LCTLTAB LCTL(KC_TAB)          // tabs switching


// Dual-role kombos
#define SHT_GRV MT(MOD_LSFT, KC_GRV)

#define OPT_TAB MT(MOD_LALT, KC_TAB)  // Tab on tap, Option on hold
#define CTL_ESC MT(MOD_LCTL, KC_ESC)  // Esc on tap, Ctrl on hold
#define OPT_ESC MT(MOD_LALT, KC_ESC)  // Tab on tap, Option on hold
#define CTL_TAB MT(MOD_LCTL, KC_TAB)  // Esc on tap,  Ctrl on hold
#define SHT_SPC MT(MOD_LSFT, KC_SPC)  // Space on tap, Shift on hold
#define SHT_ENT MT(MOD_LSFT, KC_ENT)  // Enter on tap, Shift on hold
#define SHT_ENT MT(MOD_LSFT, KC_ENT)  // Enter on tap, Shift on hold


// Helper combos to use layer as option key
#define OP_LEFT LALT(KC_LEFT) // Opt + left
#define OP_RGHT LALT(KC_RGHT) // Opt + right
#define OP_UP   LALT(KC_UP)   // Opt + up
#define OP_DOWN LALT(KC_DOWN) // Opt + down
#define OP_BSPC LALT(KC_BSPC) // Opt + backspace


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty 
 * ,-----------------------------------------------------------------------------------------------.
 * | esc/⌥ |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |   ⌫   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | tab/⌃ |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   ;   |   '   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |   `/⇧ |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   [   |   ]   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  FN   |   ↲   |   ⌫   |   ↗︎   |   ⌘   |   ⇧   | space |   ↙︎   |   ↲   |   ⌥   |   ⌃   | lng   |
 * `-----------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
    OPT_ESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    CTL_TAB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    SHT_GRV, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_LBRC, KC_RBRC,
    FN,      KC_ENT,  KC_BSPC, RAISE,   KC_LGUI, KC_LSFT, KC_SPC,  LOWER,   KC_ENT,  KC_RALT, KC_RCTL, LANG_SW
),

/* Colemak DH 
 * ,-----------------------------------------------------------------------------------------------.
 * | esc/⌥ |   Q   |   W   |   F   |   P   |   B   |   J   |   L   |   U   |   Y   |   ;   |   ⌫   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | tab/⌃ |   A   |   R   |   S   |   T   |   G   |   M   |   N   |   E   |   I   |   O   |   "   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |   `/⇧ |   Z   |   X   |   C   |   D   |   V   |   K   |   H   |   ,   |   .   |   [   |   ]   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  FN   |   ↲   |   ⌫   |   ↗︎   |   ⌘   |   ⇧   | space |   ↙︎   |   ↲   |   ⌥   |   ⌃   |  lng  |
 * `-----------------------------------------------------------------------------------------------'
 */
[_COLEMAK_DH] = LAYOUT_ortho_4x12(
    OPT_ESC, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    CTL_TAB, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    SHT_GRV, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_LBRC, KC_RBRC,
    FN,      KC_ENT,  KC_BSPC, RAISE,   KC_LGUI, KC_LSFT, KC_SPC,  LOWER,   KC_ENT,  KC_RALT, KC_RCTL, LANG_SW
),

/* Lower
 * ,-----------------------------------------------------------------------------------------------.
 * | TRNS  |   ~   |   |   |   *   |   &   |   <   |   >   |   _   |   +   |   -   |   =   |  ⌥ ⌫  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | TRNS  |   ?   |   #   |   @   |   !   |   (   |   )   |   ←   |   ↓   |   ↑   |   →   |   `   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | TRNS  |   /   |   ^   |   %   |   $   |   [   |   ]   |   ¨   |   {   |   }   |   \   |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       | TRNS  | TRNS  |   ↘︎   | TRNS  | TRNS  | TRNS  |       | TRNS  | TRNS  | TRNS  | TRNS  |
 * `-----------------------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
    _______, KC_TILD, KC_PIPE, KC_ASTR, KC_AMPR, KC_LT,   KC_GT,   KC_UNDS, KC_PLUS, KC_MINS, KC_EQL,  _______,
    _______, KC_QUES, KC_HASH, KC_AT,   KC_EXLM, KC_LPRN, KC_RPRN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_GRV,
    _______, KC_SLSH, KC_CIRC, KC_PERC, KC_DLR,  KC_LBRC, KC_RBRC, UMLAUT,  KC_LCBR, KC_RCBR, KC_BSLS, XXXXXXX,
    XXXXXXX, _______, _______, RAISE,   _______, _______, _______, XXXXXXX, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------------------.
 * | TRNS  |  tab  |   9   |   8   |   7   |       |       |   7   |   8   |   9   |       | TRNS  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | TRNS  |   0   |   3   |   2   |   1   |   .   |       |   1   |   2   |   3   |   0   |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | TRNS  |   å   |   6   |   5   |   4   |   ,   |       |   4   |   5   |   6   |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       | TRNS  | TRNS  |       | TRNS  | TRNS  | TRNS  |   ↘︎   | TRNS  | TRNS  | TRNS  | TRNS  |
 * `-----------------------------------------------------------------------------------------------'
  */
[_RAISE] = LAYOUT_ortho_4x12(
    _______, KC_TAB,  KC_9,    KC_8,    KC_7,    XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, OP_BSPC,
    _______, KC_0,    KC_3,    KC_2,    KC_1,    KC_DOT,  XXXXXXX, KC_1,    KC_2,    KC_3,    KC_0,    XXXXXXX,
    _______, A_RING,  KC_6,    KC_5,    KC_4,    KC_COMM, XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, XXXXXXX,
    LCTLTAB, _______, _______, XXXXXXX, _______, _______, _______, LOWER,   _______, _______, _______, _______
),

/* Adjust
 * ,-----------------------------------------------------------------------------------------------.
 * | TRNS  |       |  ⌘ 9  |  ⌘ 8  |  ⌘ 7  |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | TRNS  |  ⌘ 0  |  ⌘ 3  |  ⌘ 2  |  ⌘ 1  |       |       |  ⌥ ←  |       |       |  ⌥ →  |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | TRNS  |       |  ⌘ 6  |  ⌘ 5  |  ⌘ 4  |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       | TRNS  | TRNS  |       | TRNS  | TRNS  | TRNS  |       | TRNS  | TRNS  | TRNS  | TRNS  |
 * `-----------------------------------------------------------------------------------------------'
  */
[_ADJUST] = LAYOUT_ortho_4x12(
    _______, XXXXXXX, G(KC_9), G(KC_8), G(KC_7), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, G(KC_0), G(KC_3), G(KC_2), G(KC_1), XXXXXXX, XXXXXXX, OP_LEFT, XXXXXXX, XXXXXXX, OP_RGHT, XXXXXXX,
    _______, XXXXXXX, G(KC_6), G(KC_5), G(KC_4), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, _______, _______, XXXXXXX, _______, _______, _______, XXXXXXX, _______, _______, _______, _______
),

/* FN Layer
 * ,-----------------------------------------------------------------------------------------------.
 * | reset |  F11  |  F9   |  F8   |  F7   |       |       |  F12  |  F13  | qwert | colem |  del  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | TRNS  |  F10  |  F3   |  F2   |  F1   |       |       |  F14  |  F15  |bcklght| brgh- | brgh+ |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | TRNS  |  ⇧⌘4  |  F6   |  F5   |  F4   |       |       |  F16  |  F17  | prev  | pause | next  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | TRNS  | TRNS  | TRNS  |       | TRNS  | TRNS  | TRNS  |       | TRNS  | vol-  | mute  | vol+  |
 * `-----------------------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_ortho_4x12(
    RESET,   KC_F11,  KC_F9,   KC_F8,   KC_F7,   XXXXXXX, XXXXXXX, KC_F12,  KC_F13,  T_QWERT, T_COLEM, KC_DEL,
    _______, KC_F10,  KC_F3,   KC_F2,   KC_F1,   XXXXXXX, XXXXXXX, KC_F14,  KC_F15,  RGB_TOG, KC_BRID, KC_BRIU,
    _______, CMD_S_4, KC_F6,   KC_F5,   KC_F4,   XXXXXXX, XXXXXXX, KC_F16,  KC_F17,  KC_MPRV, KC_MPLY, KC_MNXT,
    _______, _______, _______, XXXXXXX, _______, _______, _______, XXXXXXX, _______, KC_VOLD, KC_MUTE, KC_VOLU
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#define MY_HSV_PURPLE 200, 255, 255
#define MY_HSV_BLUE 150, 255, 255
#define MY_HSV_GREEN 85, 255, 255
#define MY_HSV_ORANGE 30, 255, 255
#define MY_HSV_WHITE 0, 0, 255
