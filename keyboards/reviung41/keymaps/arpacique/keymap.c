/* Copyright 2020 gtips
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _ARROW,
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ARROW  MO(_ARROW)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung41(
  KC_TAB,     KC_Q,        KC_W,        KC_E,       KC_R,         KC_T,                    KC_Y,  KC_U,        KC_I,        KC_O,        KC_P,           KC_BSPC,
  KC_ESC,     GUI_T(KC_A), ALT_T(KC_S), SFT_T(KC_D), CTL_T(KC_F), KC_G,                    KC_H,  CTL_T(KC_J), SFT_T(KC_K), ALT_T(KC_L), GUI_T(KC_SCLN), KC_QUOT,
  KC_LSFT,    KC_Z,        KC_X,        KC_C,       KC_V,         KC_B,                    KC_N,  KC_M,        KC_COMM,     KC_DOT,      KC_SLSH,        KC_SFTENT,
                                                   KC_LCTL,   LOWER,    LT(ARROW, KC_SPC),   RAISE,    KC_RGUI
  ),
  
  [_LOWER] = LAYOUT_reviung41(
    KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    KC_CAPS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,           KC_F12,  _______, _______, KC_HOME, KC_END , _______,
                                      _______,   _______,  _______,   _______,  _______
  ),
  
  [_RAISE] = LAYOUT_reviung41(
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  KC_CAPS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,               KC_F12,  KC_LABK, KC_RABK, KC_PGUP, KC_PGDN, _______,
                                      _______,   _______,  _______,  _______,  _______
  ),
  
  [_ADJUST] = LAYOUT_reviung41(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  XXXXXXX,   RGB_TOG,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, XXXXXXX,   XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            RESET,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                            _______,   _______,  XXXXXXX,  _______,  _______
  ),
  
  [_ARROW] = LAYOUT_reviung41(
    _______, _______, _______, KC_UP  , C(KC_HOME), KC_PGUP,          _______, KC_7, KC_8, KC_9,  KC_SLASH,    KC_BSPC,
    _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,    KC_END,           _______, KC_4, KC_5, KC_6,  KC_ASTERISK, KC_EQUAL,
    _______, _______, _______, _______, C(KC_END),  KC_PGDN,          _______, KC_1, KC_2, KC_3,  KC_MINUS,    KC_PLUS,
                                       _______,   _______,  _______,  KC_0,  KC_DOT
  )
};
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

