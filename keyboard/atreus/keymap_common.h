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
#ifndef KEYMAP_COMMON_H
#define KEYMAP_COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"

extern const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS];
extern const uint16_t fn_actions[];

#define KEYMAP_PCBDOWN( \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, \
  K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
  K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A \
) {                                                                     \
  { K09, K08, K07, K06, K05, KC_NO, K04, K03, K02, K01, K00 }, \
  { K19, K18, K17, K16, K15, KC_NO, K14, K13, K12, K11, K10 }, \
  { K29, K28, K27, K26, K25, K35,   K24, K23, K22, K21, K20 }, \
  { K3A, K39, K38, K37, K36, K34,   K33, K32, K31, K30, K2A } \
}

#define KEYMAP_PCBUP( \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, \
  K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
  K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A \
) {                                                                     \
  { K00, K01, K02, K03, K04, KC_NO, K05, K06, K07, K08, K09 }, \
  { K10, K11, K12, K13, K14, KC_NO, K15, K16, K17, K18, K19 }, \
  { K20, K21, K22, K23, K24, K34,   K25, K26, K27, K28, K29 }, \
  { K2A, K30, K31, K32, K33, K35,   K36, K37, K38, K39, K3A }      \
}

#ifdef PCBDOWN
#define KEYMAP KEYMAP_PCBDOWN
#else
#define KEYMAP KEYMAP_PCBUP
#endif

enum function_id {
  BOOTLOADER,
};

void bootloader(void);

#endif
