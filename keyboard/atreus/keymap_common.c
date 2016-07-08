/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

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
#include "keymap_common.h"

// Handle JP text conversion
#define MY_KANA KC_KANA
#define MY_RO   KC_RO

// Adjust macbook brightness
#define MY_BRUP KC_PAUSE
#define MY_BRDN KC_SCROLLLOCK

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {	\

    { /* FN layer 0, qwerty for OS based qwerty -> dvorak translation */
    {KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,                                      KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC }, \
    {KC_FN15, KC_A, KC_S, KC_D, KC_F, KC_G,                                      KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT}, \
    {KC_LALT, KC_Z, KC_X, KC_C, KC_V, KC_B,                                      KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_0}, \
    {KC_LGUI, KC_FN17, KC_ESC, MY_RO, KC_FN16, KC_FN13,                        KC_FN14, KC_FN11, MY_KANA, KC_ESC, KC_ENT, KC_PGDN} \
  }, \

  { /* FN layer 1, numbers, arrows, and extended punctuation */
    {KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5,                                            KC_6, KC_7, KC_8, KC_9, KC_0, KC_RBRACKET }, \
    {KC_TRNS, KC_FN23, KC_FN24, KC_FN25, KC_FN26, KC_FN27,                              KC_PGUP, KC_MINUS, KC_EQUAL, KC_FN28, KC_FN29, KC_BSLASH}, \
    {KC_TRNS, KC_FN30, KC_FN31, KC_LEFT, KC_RIGHT, KC_RBRACKET,                         KC_PGDN, KC_UP, KC_DOWN, KC_DOT, KC_SLSH, KC_FN5}, \
    {KC_TRNS, KC_TRNS, KC_FN1, KC_TRNS, KC_TRNS, KC_TRNS,                               KC_TRNS, KC_TRNS, KC_TRNS, KC_FN1, KC_TRNS, KC_TRNS} \
  },								       \

  { /* FN layer 2, F# and media keys */
    {KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                                      KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12 }, \
    {KC_NO, KC_0, KC_NO, KC_NO, KC_NO, MY_BRUP,                                     KC_VOLU, KC_MEDIA_REWIND, KC_MPLY, KC_MEDIA_FAST_FORWARD, KC_NO, KC_NO}, \
    {KC_FN5, KC_VOLU, KC_VOLD, KC_MPLY, KC_AUDIO_MUTE, MY_BRDN,                     KC_VOLD, KC_MUTE, KC_NO, KC_NO, KC_NO, KC_FN3}, \
    {KC_NO, KC_FN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_FN2, KC_PGDN} \
  },									\

  { /* FN layer 3, hardware dvorak of layer 1 */
    {KC_TAB,  KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y,         KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLASH }, \
    {KC_FN15, KC_A, KC_O, KC_E, KC_U, KC_I,                 KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINUS}, \
    {KC_LALT, KC_SCLN, KC_Q, KC_J, KC_K, KC_X,              KC_B, KC_M, KC_W, KC_V, KC_Z, KC_FN3}, \
    {KC_LGUI, KC_FN17, KC_ESC, KC_RO, KC_FN16, KC_FN20,    KC_FN14, KC_FN18, KC_KANA, KC_ESC, KC_ENT, KC_PGDN} \
  }, \

  { /* FN layer 4, hardware dvorak of layer 2 */
    {KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5,                                            KC_6, KC_7, KC_8, KC_9, KC_0, KC_RBRACKET }, \
    {KC_TRNS, KC_FN23, KC_FN24, KC_FN25, KC_FN26, KC_FN27,                              KC_PGUP, KC_LBRACKET, KC_RBRACKET, KC_FN21, KC_FN22, KC_BSLASH}, \
    {KC_TRNS, KC_FN30, KC_FN31, KC_LEFT, KC_RIGHT, KC_RBRACKET,                         KC_PGDN, KC_UP, KC_DOWN, KC_DOT, KC_SLSH, KC_FN10}, \
    {KC_TRNS, KC_TRNS, KC_FN7, KC_TRNS, KC_TRNS, KC_TRNS,                               KC_TRNS, KC_TRNS, KC_TRNS, KC_FN7, KC_TRNS, KC_TRNS} \
  },								       \

  { /* FN layer 5, F# and media keys */
    {KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                                      KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12 }, \
    {KC_NO, KC_0, KC_NO, KC_NO, KC_NO, MY_BRUP,                                     KC_VOLU, KC_MEDIA_REWIND, KC_MPLY, KC_MEDIA_FAST_FORWARD, KC_NO, KC_NO}, \
    {KC_FN10, KC_VOLU, KC_VOLD, KC_MPLY, KC_AUDIO_MUTE, MY_BRDN,                    KC_VOLD, KC_MUTE, KC_NO, KC_NO, KC_NO, KC_FN3}, \
    {KC_NO, KC_FN8, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_FN8, KC_PGDN} \
  },									\
};

/* translates key to keycode */
uint8_t keymap_key_to_keycode(uint8_t layer, keypos_t key)
{
  // Need pgm_read_word to access flash section of memory
  return pgm_read_word(&keymaps[(layer)][(key.row)][(key.col)]);
}

/* translates Fn keycode to action */
action_t keymap_fn_to_action(uint8_t keycode)
{
  // Need pgm_read_word to access flash section of memory
  return (action_t){ .code = pgm_read_word(&fn_actions[FN_INDEX(keycode)]) };
}

void bootloader() {
  clear_keyboard();
  print("\n\nJump to bootloader... ");
  _delay_ms(250);
  *(uint16_t *)0x0800 = 0x7777; // these two are a-star-specific
  bootloader_jump();
  print("not supported.\n");
}


const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_LAYER_MOMENTARY(1),   // FN0, to Fn overlay
  [1]  = ACTION_LAYER_ON(2, 1),       // FN1, enable layer 2
  [2]  = ACTION_LAYER_OFF(2, 1),      // FN2, disable layer 2
  [3]  = ACTION_FUNCTION(BOOTLOADER), // FN3, Reset BIOS
  [4]  = ACTION_LAYER_MOMENTARY(2),   // FN4, to Fn overlay

  [5]  = ACTION_LAYER_ON(3, 1),       // FN5, to hard dvorak

  [6]  = ACTION_LAYER_MOMENTARY(4),   // FN6, to hard dvorak's fn
  [7]  = ACTION_LAYER_ON(5, 1),       // FN7, enable layer 5
  [8]  = ACTION_LAYER_OFF(5, 1),      // FN8, disable layer 5
  [9]  = ACTION_LAYER_MOMENTARY(4),   // FN9, to Fn overlay - NOT USED
  [10] = ACTION_LAYER_OFF(3, 1),      // disable hard dvorak

  [11]  = ACTION_LAYER_TAP_KEY(1, KC_SPC),  // FN11, to Fn overlap or space
  // [12]  = ACTION_LAYER_TAP_KEY(4, KC_SPC),  // FN12, to Fn overlap or space
  [13]  = ACTION_LAYER_TAP_KEY(1, KC_BSPC), // FN13, to Fn overlap or backspace

  [14]  = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENT), // FN14, CTRL or Enter
  [15]  = ACTION_MODS_ONESHOT(MOD_LSFT), // FN15, one shot mod for shift
  [16]  = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_BSPC), // FN16, CTRL or Enter
  [17]  = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_DELETE), // FN17, CTRL or Enter

  [18]  = ACTION_LAYER_TAP_KEY(4, KC_SPC),  // FN18, to Fn overlap or space
  // [19]  = ACTION_LAYER_TAP_KEY(4, KC_SPC),  // FN18, to Fn overlap or space
  [20]  = ACTION_LAYER_TAP_KEY(4, KC_BSPC), // FN20, to Fn overlap or backspace
  
  // Handle "shifted" keys
  [21]  = ACTION_MODS_KEY(MOD_LSFT, KC_LBRACKET),
  [22]  = ACTION_MODS_KEY(MOD_LSFT, KC_RBRACKET),
  [23]  = ACTION_MODS_KEY(MOD_LSFT, KC_8),
  [24]  = ACTION_MODS_KEY(MOD_LSFT, KC_7),
  [25]  = ACTION_MODS_KEY(MOD_LSFT, KC_9),
  [26]  = ACTION_MODS_KEY(MOD_LSFT, KC_0),
  [27]  = ACTION_MODS_KEY(MOD_LSFT, KC_1),
  [28]  = ACTION_MODS_KEY(MOD_LSFT, KC_MINUS),
  [29]  = ACTION_MODS_KEY(MOD_LSFT, KC_EQUAL),
  [30]  = ACTION_MODS_KEY(MOD_LSFT, KC_GRAVE),
  [31]  = ACTION_MODS_KEY(MOD_LSFT, KC_RBRACKET),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}

// ACTION_FUNCTION(id, opt)
// ACTION_FUNCTION_TAP(id, opt)
/* const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) */
/* { */
/*   switch (id) { */
/*   case HELLO: */
/*     return (record->event.pressed ? */
/* 	    MACRO( I(0), T(H), T(E), T(L), T(L), W(255), T(O), END ) : */
/* 	    MACRO_NONE ); */
/*   case ALT_TAB: */
/*     return (record->event.pressed ? */
/* 	    MACRO( D(LALT), D(TAB), END ) : */
/* 	    MACRO( U(TAB), END )); */
/*   } */
/*   return MACRO_NONE; */
/* } */
