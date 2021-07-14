/* Copyright 2021 Anton Chebotaev */

#include QMK_KEYBOARD_H
#include "config.h"

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FN
};


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *  You can use _______ in place for KC_TRNS (transparent)   *
 *  Or you can use XXXXXXX for KC_NO (NOOP)                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define LOWER_T TG(_LOWER)
#define RAISE_T TG(_RAISE)
#define FN_GRV LT(_FN, KC_GRV)

#define PRV_TAB LCMD(KC_LCBR)
#define NXT_TAB LCMD(KC_RCBR)
#define CMD_ENT LCMD(KC_ENT)
#define CMD_S_4 SCMD(KC_4)
#define CMD_S_3 SCMD(KC_3)

#define OPT_ECS MT(MOD_LALT, KC_ESC)  // Esc on tap, Option on hold
#define CTL_TAB MT(MOD_LCTL, KC_TAB)  // Tab on tap, Ctrl on hold
#define SHFT_SP MT(MOD_LSFT, KC_SPC)  // Space on tap, Shift on hold
#define LANG_SW LALT(KC_SPC)          // my language switching combo

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty 
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  FN  |   /  |   ⌃  |   ⌥  |   ⌘  |    Space    |Lower |Raise | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
    OPT_ECS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    CTL_TAB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_ENT,
    FN_GRV,  LANG_SW, KC_LCTL, KC_LALT, KC_LGUI, SHFT_SP, SHFT_SP, LOWER,   RAISE ,  KC_LEFT, KC_DOWN, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | TRNS |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS |      |      |      |      |      |      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS |      | TRNS | TRNS | TRNS |    Enter    | TRNS |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, _______, _______, _______, KC_ENT,  KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS |   !  |   @  |   {  |   }  |   %  |   ^  |  &   |  *   |   _  |   +  | TRNS |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS |   ?  |   #  |   (  |   )  |      |      |  <   |  >   |   -  |   =  |   `  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS |   /  |   $  |   [  |   ]  |      |      |  |   |  \   |   ~  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS |      | TRNS | TRNS | TRNS |  Cmd-Enter  |      | TRNS |      |      |      |
 * `-----------------------------------------------------------------------------------'
  */
[_RAISE] = LAYOUT_preonic_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, KC_AMPR, KC_ASTR, KC_UNDS, KC_PLUS, _______,
    _______, KC_QUES, KC_HASH, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX, KC_LT,   KC_GT,   KC_MINS, KC_EQL,  KC_GRV,
    _______, KC_SLSH, KC_DLR,  KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, KC_PIPE, KC_BSLS, KC_TILD, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, _______, _______, _______, CMD_ENT, CMD_ENT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* FN Layer
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |reset |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS |      |      | ⇧⌘3  | ⇧⌘4  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS |      |      |      |      |      |      |      |      |      |brgh- |brgh+ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS |      | TRNS | TRNS | TRNS |  play/pause |raiseT|lowerT| vol- | mute | vol+ |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_preonic_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
    _______, XXXXXXX, XXXXXXX, CMD_S_3, CMD_S_4, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU,
    _______, XXXXXXX, _______, _______, _______, KC_MPLY, KC_MPLY, LOWER_T, RAISE_T, KC_VOLD, KC_MUTE, KC_VOLU
)

};