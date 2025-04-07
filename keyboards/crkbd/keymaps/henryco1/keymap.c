/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H

//========================================
// Constant Defines
//========================================

// Layer Defines
#define _QWERTY         (0U)
#define _NAVIGATE       (1U)
#define _NUMPAD         (2U)
#define _SYMBOL_LEFT    (3U)
#define _SYMBOL_RIGHT   (4U)
#define _FUNCTION       (5U)
#define _COLEMAK        (6U)

// The Navigate layer provides navigation shortcuts and home row modifiers
// Keycode Shortcuts
#define S_TAB        S(KC_TAB)
#define C_TAB        C(KC_TAB)    
#define CS_TAB       C(S(KC_TAB))
// Layer Trigger
#define SPC_NAV      LT(_NAVIGATE, KC_SPC)

// The Numpad layer provides numpad shortcuts
#define ENT_NUM      LT(_NUMPAD, KC_ENT)

// Special VIM configuration, placed on the natural position of the thumb when hjkl are used. 
#define ESC_NUM      LT(_NUMPAD, KC_ESC)

// The Symbol layer provides a convenient layer for symbols
#define L_SYM        MO(_SYMBOL_LEFT)
#define R_SYM        MO(_SYMBOL_RIGHT)

// Layer Shortcuts
#define L_QWRTY      DF(_QWERTY)                   // Activates base layer and deactivates all others
// The Colemak layer provides an alternative layout to qwerty
#define R_COLEM      TT(_COLEMAK)

// Home Row Mods, see https://precondition.github.io/home-row-mods#using-home-row-mods-with-qmk
// Have modifiers on the home row without having a separate layer
#define HR_A         LGUI_T(KC_A)
#define HR_S         LALT_T(KC_S)
#define HR_D         LCTL_T(KC_D)
#define HR_F         LSFT_T(KC_F)

#define HR_J         RSFT_T(KC_J)
#define HR_K         RCTL_T(KC_K)
#define HR_L         RALT_T(KC_L)
#define HR_SCLN      RGUI_T(KC_SCLN)

// Colemak Home Row Mods
#define HRC_A        LGUI_T(KC_R)
#define HRC_S        LALT_T(KC_T)
#define HR_R         LCTL_T(KC_R)
#define HR_T         LSFT_T(KC_T)

#define HR_N         RSFT_T(KC_N)
#define HR_E         RCTL_T(KC_E)
#define HR_I         RALT_T(KC_I)
#define HR_O         RSFT_T(KC_O)

// One shot mods
#define OS_LSFT      OSM(MOD_LSFT)
#define OS_RSFT      OSM(MOD_RSFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x6_3_ex2(
  //┌────────┼────────┼────────┼────────┼────────┼────────┼────────┐  ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┐
     CW_TOGG, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    QK_BOOT,    L_QWRTY, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  HR_A,    HR_S,    HR_D,    HR_F,    KC_G,    KC_G,       R_COLEM, KC_H,    HR_J,    HR_K,    HR_L,    HR_SCLN, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┘  └────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     OS_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OS_RSFT,
  //└────────┼────────┼────────┼────────┼────────┼────────┼────────┐  ┌────────└────────┼────────┼────────┼────────┼────────┼────────┘
                                         L_SYM,   MO(1),   SPC_NAV,    ESC_NUM, MO(2),   R_SYM
                                     // └────────┴────────┴────────┘  └────────┴────────┴────────┘

  ),

    [_COLEMAK] = LAYOUT_split_3x6_3_ex2(
  //┌────────┼────────┼────────┼────────┼────────┼────────┼────────┐  ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┐
     CW_TOGG, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_T,       _______, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  HR_A,    HR_R,    HR_S,    HR_T,    KC_G,    KC_G,       _______, KC_M,    HR_N,    HR_E,    HR_I,    HR_O,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┘  └────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     OS_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, OS_RSFT,
  //└────────┼────────┼────────┼────────┼────────┼────────┼────────┐  ┌────────└────────┼────────┼────────┼────────┼────────┼────────┘
                                         L_SYM,   MO(1),   SPC_NAV,    ESC_NUM, MO(2),   R_SYM
                                     // └────────┴────────┴────────┘  └────────┴────────┴────────┘
  ),

    [_NUMPAD] = LAYOUT_split_3x6_3_ex2(
  //┌────────┼────────┼────────┼────────┼────────┼────────┼────────┐  ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┐
     _______, KC_PSLS, KC_7,    KC_8,    KC_9,    KC_PMNS, KC_NUM,     _______, _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_BSPC, KC_PSCR,    _______, _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┘  └────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_PDOT, KC_4,    KC_5,    KC_6,    KC_EQL,                       _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
  //└────────┼────────┼────────┼────────┼────────┼────────┼────────┐  ┌────────└────────┼────────┼────────┼────────┼────────┼────────┘
                                         L_SYM,   MO(1),   SPC_NAV,    ESC_NUM, MO(2),   R_SYM
                                     // └────────┴────────┴────────┘  └────────┴────────┴────────┘
  ),
  [_SYMBOL_LEFT] = LAYOUT_split_3x6_3_ex2(
  //┌────────┼────────┼────────┼────────┼────────┼────────┼────────┐  ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┐
     _______, _______, KC_COLN, KC_LABK, KC_RABK, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_AT,   _______,    _______, KC_UNDS, KC_MINS, KC_EQL,  KC_PPLS, KC_PERC, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┘  └────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_EXLM, KC_LBRC, KC_RBRC, _______,                      _______, _______, _______, _______, _______, _______,
  //└────────┼────────┼────────┼────────┼────────┼────────┼────────┐  ┌────────└────────┼────────┼────────┼────────┼────────┼────────┘
                                         L_SYM,   MO(1),   SPC_NAV,    ESC_NUM, MO(2),   R_SYM
                                     // └────────┴────────┴────────┘  └────────┴────────┴────────┘
  ),
  [_SYMBOL_RIGHT] = LAYOUT_split_3x6_3_ex2(
  //┌────────┼────────┼────────┼────────┼────────┼────────┼────────┐  ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┐
     _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, KC_PIPE, KC_QUOT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_CIRC, KC_ASTR, KC_AMPR, KC_QUES, _______, _______,    _______, KC_HASH, KC_TILD, KC_SLSH, KC_DQUO, KC_DLR,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┘  └────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                      _______, _______, KC_BSLS, KC_GRV,  _______, _______,
  //└────────┼────────┼────────┼────────┼────────┼────────┼────────┐  ┌────────└────────┼────────┼────────┼────────┼────────┼────────┘
                                         L_SYM,   MO(1),   SPC_NAV,    ESC_NUM, MO(2),   R_SYM
                                     // └────────┴────────┴────────┘  └────────┴────────┴────────┘
  ),
};

