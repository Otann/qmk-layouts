/* Copyright 2021 Anton Chebotaev */

#include QMK_KEYBOARD_H
#include "config.h"

enum preonic_layers {
  _QWERTY,
  _COLEMAK_DH,
  _LOWER,
  _RAISE,
  _FN
};


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *  You can use _______ in place for KC_TRNS (transparent)   *
 *  Or you can use XXXXXXX for KC_NO (NOOP)                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

enum my_keycodes {
  FOO = SAFE_RANGE,
  BAR
};


// Layer switching
#define FN MO(_FN)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define LOWER_T TG(_LOWER)
#define RAISE_T TG(_RAISE)
#define LFT_RSE LT(_RAISE, KC_LEFT)
#define FN_TAB LT(_FN, KC_TAB)

#define T_QWERT DF(_QWERTY)
#define T_COLEM DF(_COLEMAK_DH)

// Pre-baked shortcuts
#define EMOJI   C(G(KC_SPC))
#define PRV_TAB LCMD(KC_LCBR)
#define NXT_TAB LCMD(KC_RCBR)
#define CMD_ENT LCMD(KC_ENT)
#define CMD_S_4 SCMD(KC_4)
#define CMD_S_3 SCMD(KC_3)
#define LANG_SW LALT(KC_SPC)          // my language switching combo
#define UMLAUT  LALT(KC_U)

// Dual modifier?
#define SHT_CMD OSM(MOD_LSFT | MOD_LGUI)
#define SHT_OPT OSM(MOD_LSFT | MOD_LALT)
#define OSM_SHT OSM(MOD_LSFT)
#define OSM_CMD OSM(MOD_LGUI)
#define OSM_OPT OSM(MOD_LALT)

// Dual-role kombos
#define SHT_GRV MT(MOD_LSFT, KC_GRV)  // `   on tap, Shift on hold
#define OPT_TAB MT(MOD_LALT, KC_TAB)  // Tab on tap, Option on hold
#define CTL_ESC MT(MOD_LCTL, KC_ESC)  // Esc on tap, Ctrl on hold
#define OPT_ESC MT(MOD_LALT, KC_ESC)  // Tab on tap, Option on hold
#define CTL_TAB MT(MOD_LCTL, KC_TAB)  // Esc on tap, Ctrl on hold
#define SHT_SPC MT(MOD_LSFT, KC_SPC)  // Space on tap, Shift on hold
#define SHT_ENT MT(MOD_LSFT, KC_ENT)  // Enter on tap, Shift on hold

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty 
 * ,-----------------------------------------------------------------------------------------------.
 * |   1   |   2   |   3   |   4   |   5   | tab<  | tab>  |   6   |   7   |   8   |   9   |   0   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |   Q   |   W   |   E   |   R   |   T   |   [   |   ]   |   Y   |   U   |   I   |   O   |   P   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |   A   |   S   |   D   |   F   |   G   |   -   |   =   |   H   |   J   |   K   |   L   |   ;   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |   Z   |   X   |   C   |   V   |   B   |   `   |   '   |   N   |   M   |   ,   |   .   |   /   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | FNtab | ⌃/esc |   ⌥   |   ⌘   |   ⇧   |   ⇧   | space | space |   ↙︎   |   ↗︎   |  lang |   ↲   |
 * `-----------------------------------------------------------------------------------------------'
  */
[_QWERTY] = LAYOUT_preonic_grid(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    PRV_TAB, NXT_TAB, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_MINS, KC_EQL,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_GRV,  KC_QUOT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    FN_TAB,  CTL_ESC, KC_LALT, KC_LGUI, SHT_ENT, SHT_ENT, KC_SPC,  KC_SPC,  LOWER,   RAISE,   LANG_SW, KC_BSPC
),


/* Lower
 * ,-----------------------------------------------------------------------------------------------.
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |   !   |   @   |   {   |   }   |   %   |       |       |   ^   |  &    |  *    |   -   |   =   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |   ?   |   $   |   (   |   )   |   <   |       |       |   >   |   ←   |   ↓   |   ↑   |   →   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |   /   |   #   |   [   |   ]   |   ~   |       |       |   \   |  ¨    |  |    |   _   |   +   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | TRNS  | TRNS  | TRNS  | TRNS  | TRNS  | TRNS  | TRNS  | TRNS  | TRNS  | TRNS  | TRNS  | TRNS  |
 * `-----------------------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PERC, XXXXXXX, XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,
    KC_QUES, KC_DLR,  KC_LPRN, KC_RPRN, KC_LT,   XXXXXXX, XXXXXXX, KC_GT,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    KC_SLSH, KC_HASH, KC_LBRC, KC_RBRC, KC_TILD, XXXXXXX, XXXXXXX, KC_BSLS, UMLAUT,  KC_PIPE, KC_UNDS, KC_PLUS,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------------------.
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |   7   |   8   |   9   |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |   4   |   5   |   6   |   0   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |   1   |   2   |   3   |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | TRNS  | TRNS  | TRNS  | TRNS  | TRNS  | TRNS  | TRNS  | TRNS  | TRNS  | TRNS  | TRNS  | TRNS  |
 * `-----------------------------------------------------------------------------------------------'
  */
[_RAISE] = LAYOUT_preonic_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    KC_0,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* FN Layer
 * ,-----------------------------------------------------------------------------------------------.
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | reset |  F7   |  F8   |  F9   |  F10  |  F11  |  F12  |       |       |       |       |  RGB  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  ⇧⌘4  |  F4   |  F5   |  F6   | mute  | vol-  | vol+  |       |       |       |       | brgh+ |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |  F1   |  F2   |  F3   | pause | prev  | next  |       |       |       |       | brgh- |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | TRNS  | TRNS  | TRNS  | TRNS  | TRNS  | TRNS  | TRNS  | TRNS  | TRNS  | TRNS  | TRNS  | TRNS  |
 * `-----------------------------------------------------------------------------------------------'
  */
[_FN] = LAYOUT_preonic_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RESET,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,
    CMD_S_4, KC_F4,   KC_F5,   KC_F6,   KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRIU,
    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID,
    _______, _______, _______, _______, KC_LSFT, KC_LSFT, _______, _______, _______, _______, _______, KC_DEL
)

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case FOO:
      if (record->event.pressed) {
        // Do something when pressed
        println("foo pressed");
      } else {
        // Do something else when release
        println("foo released");
      }
      return false; // Skip all further processing of this key
    case KC_ENTER:
      // Play a tone when enter is pressed
      if (record->event.pressed) {
        println("enter pressed");
      }
      return true; // Let QMK send the enter press/release events
    default:
      return true; // Process all other keycodes normally
  }
}



#ifdef RGBLIGHT_ENABLE

#define MY_HSV_PURPLE 200, 255, 255
#define MY_HSV_BLUE 150, 255, 255
#define MY_HSV_GREEN 85, 255, 255
#define MY_HSV_ORANGE 30, 255, 255
#define MY_HSV_WHITE 0, 0, 255

void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_sethsv_noeeprom(200, 255, 255);
  rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
  if (IS_LAYER_ON_STATE(state, _COLEMAK_DH)) {
      rgblight_sethsv_noeeprom(MY_HSV_GREEN);    
  } else {
      rgblight_sethsv_noeeprom(MY_HSV_PURPLE);    
  }        
  return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
  case _LOWER:
      rgblight_sethsv_noeeprom(MY_HSV_BLUE); break;
  case _RAISE:
      rgblight_sethsv_noeeprom(MY_HSV_BLUE); break;
  case _FN:
      rgblight_sethsv_noeeprom(MY_HSV_WHITE); break;      
  default:
    switch (biton32(default_layer_state)) {
      case _COLEMAK_DH:
        rgblight_sethsv_noeeprom(MY_HSV_GREEN); break;
      default:
        rgblight_sethsv_noeeprom(MY_HSV_PURPLE);  break;
      }
    break;
  }
  return state;
}
#endif