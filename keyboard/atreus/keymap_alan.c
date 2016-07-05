#include "keymap_common.h"

/* The default Atreus layout. First layer is normal keys, second
   (momentary fn layer) is numbers, most punctuation, and
   arrows. Third (modal, persistent) layer is function keys and other
   rarely-used keys. */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {	\

  { /* FN layer 0, qwerty for OS based qwerty -> dvorak translation */
    {KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,                                      KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC }, \
    {ACTION_MODS_TAP_KEY(MOD_LSFT, ACTION_MODS_ONESHOT(MOD_LSFT)), KC_A, KC_S, KC_D, KC_F, KC_G,        KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT}, \
    {KC_LALT, KC_Z, KC_X, KC_C, KC_V, KC_B,                                      KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_FN3}, \
    {KC_LGUI, KC_DELETE, KC_ESC, KC_O, KC_BSPC, KC_FN13,                          ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ENT), KC_FN11, KC_KANA, KC_ESC, ACTION_MODS_TAP_KEY(MOD_RSFT, KC_ENT), KC_PGDN} \
  }, \

  { /* FN layer 1, numbers, arrows, and extended punctuation */
    {KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5,                                            KC_6, KC_7, KC_8, KC_9, KC_0, KC_RBRACKET }, \
    {KC_TRNS, SHIFT(KC_8), SHIFT(KC_7), SHIFT(KC_9), SHIFT(KC_0), SHIFT(KC_1),          KC_PGUP, KC_MINUS, KC_EQUAL, SHIFT(KC_MINUS), SHIFT(KC_EQUAL) , KC_BSLASH}, \
    {KC_TRNS, SHIFT(KC_GRAVE), SHIFT(KC_RBRACKET), KC_LEFT, KC_RIGHT, KC_RBRACKET,      KC_PGDN, KC_UP, KC_DOWN, KC_DOT, KC_SLSH, KC_FN5}, \
    {KC_TRNS, KC_BSPC, KC_FN1, KC_0, KC_RALT, KC_TRNS,                                  KC_TRNS, KC_TRNS, KC_RSFT, KC_FN1, ACTION_MODS_TAP_KEY(KC_RALT, KC_ENT), KC_PGDN} \
  },								       \

  { /* FN layer 2, F# and media keys */
    {KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                                      KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12 }, \
    {KC_NO, KC_0, KC_NO, KC_MEDIA_STOP, KC_NO, KC_AUDIO_VOL_UP,                     KC__VOLUP, KC_MEDIA_REWIND, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_FAST_FORWARD, KC_NO, KC_NO}, \
    {KC_FN5, KC_VOLU, KC_VOLD, KC_MPLY, KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN,           KC__VOLDOWN, KC__MUTE, KC_NO, KC_NO, KC_NO, KC_FN3}, \
    {KC_NO, KC_NO, KC_NO, KC_NO, KC_FN0, KC_FN0,                                    KC_FN2, KC_FN2, KC_NO, KC_NO, KC_RALT, KC_PGDN} \
  },									\

  { /* FN layer 3, hardware dvorak of layer 1 */
    {KC_TAB,  KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y,         KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLASH }, \
    {KC_LSFT, KC_A, KC_O, KC_E, KC_U, KC_I,                 KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINUS}, \
    {KC_LALT, KC_SCLN, KC_Q, KC_J, KC_K, KC_X,              KC_B, KC_M, KC_W, KC_V, KC_Z, KC_FN3}, \
    {KC_LGUI, KC_DELETE, KC_ESC, KC_RO, KC_BSPC, KC_FN6,    KC_LCTL, KC_FN12, KC_KANA, KC_ESC, KC_ENT, KC_PGDN}	\
  }, \

  { /* FN layer 4, hardwark dvorak of layer 2 */
    {KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5,                                            KC_6, KC_7, KC_8, KC_9, KC_0, KC_RBRACKET }, \
    {KC_LSFT, SHIFT(KC_8), SHIFT(KC_7), SHIFT(KC_9), SHIFT(KC_0), SHIFT(KC_1),          KC_PGUP, KC_LBRACKET, KC_RBRACKET, SHIFT(KC_LBRACKET), SHIFT(KC_RBRACKET) , KC_BSLASH}, \
    {KC_LALT, SHIFT(KC_GRAVE), SHIFT(KC_RBRACKET), KC_LEFT, KC_RIGHT, KC_RBRACKET,      KC_PGDN, KC_UP, KC_DOWN, KC_DOT, KC_SLSH, KC_FN10}, \
    {KC_LGUI, KC_BSPC, KC_ESC, KC_0, KC_RALT, KC_FN6,                                   KC_LCTL, KC_RALT, KC_RSFT, KC_FN1, KC_RALT, KC_PGDN} \
  },									\

  { /* FN layer 5, F# and media keys */
    {KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                                      KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12 }, \
    {KC_NO, KC_0, KC_NO, KC_MEDIA_STOP, KC_NO, KC_AUDIO_VOL_UP,                     KC__VOLUP, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_NO, KC_NO}, \
    {KC_FN10, KC_NO, KC_NO, KC_MEDIA_STOP, KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN,        KC__VOLDOWN, KC__MUTE, KC_NO, KC_NO, KC_NO, KC_FN3}, \
    {KC_NO, KC_NO, KC_NO, KC_NO, KC_FN0, KC_FN0,                                    KC_FN2, KC_FN2, KC_NO, KC_NO, KC_RALT, KC_PGDN} \
  },									\
};

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

  [11]  = ACTION_LAYER_TAP_KEY(1, KC_SPC), // FN11, to Fn overlap or space
  [12]  = ACTION_LAYER_TAP_KEY(4, KC_SPC), // FN12, to Fn overlap or space
  [12]  = ACTION_LAYER_TAP_KEY(1, KC_BSPC), // FN12, to Fn overlap or space
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
