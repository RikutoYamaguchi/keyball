/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include "quantum.h"

/*
Combo Settings
*/
const uint16_t PROGMEM combo_J_K[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_W_E[] = {KC_W, KC_E, COMBO_END};

combo_t key_combos[] = {
  COMBO(combo_J_K, KC_BSPC),
  COMBO(combo_W_E, KC_ESC),
};

/*
Tap Dance Settings
*/
enum {
  TD_Q_ESC,
};
tap_dance_action_t tap_dance_actions[] = {
  [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default
  [0] = LAYOUT_universal(
    _______  , KC_Q , KC_W     , KC_E      , KC_R      , KC_T     ,                                        KC_Y     , KC_U     , KC_I     , KC_O     ,LALT_T(KC_P) , _______ ,
    _______ , LGUI_T(KC_A), KC_S     , LT(2,KC_D), LT(3,KC_F), KC_G ,                                    KC_H     , KC_J     , KC_K     , KC_L     , LGUI_T(KC_SCLN), _______,
    _______ , KC_Z, KC_X     , KC_C      , KC_V      , KC_B     ,                                        KC_N     , KC_M     , KC_COMM  , KC_DOT   , LT(3,KC_SLSH)  ,  _______ ,
              LSFT(KC_TAB),KC_TAB,     	KC_LCTL,KC_LSFT,KC_SPC,                                          KC_ENT, MO(1), _______,     _______  , C(S(G(KC_4)))
  ),

  [1] = LAYOUT_universal(
    _______ ,  KC_1    , KC_2      , KC_3    , KC_4    , KC_5       ,                                         KC_6    , KC_7     , KC_8     , KC_9     , KC_0     , _______ ,
    _______ ,  KC_LGUI , KC_LBRC, S(KC_9) , S(KC_0) , KC_RBRC ,                                         KC_LEFT , KC_DOWN  , KC_UP    , KC_RIGHT , KC_QUOT  , _______ ,
    _______ ,  KC_MINS,  KC_EQL  , _______ ,  KC_BSLS, KC_GRV    ,                                         KC_BSPC   , XXXXXXX  , XXXXXXX  , _______  , KC_SLSH , _______ ,
              LSFT(KC_TAB),KC_TAB,      KC_LNG2,KC_LSFT,KC_LNG1,                         _______  , _______  , _______       , _______  , _______
  ),

  [2] = LAYOUT_universal(
    _______  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                                              XXXXXXX , G(KC_BTN1)  , KC_ESC  , XXXXXXX  , C(S(G(KC_4)))  , XXXXXXX  ,
    _______  , XXXXXXX , KC_LALT , XXXXXXX , KC_LGUI , XXXXXXX  ,                                             XXXXXXX , KC_BTN1  , KC_BTN2, XXXXXXX  , XXXXXXX  , XXXXXXX  ,
    _______  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                                              XXXXXXX , XXXXXXX , XXXXXXX   ,XXXXXXX,S(G(KC_5)),XXXXXXX,
              LSFT(KC_TAB),KC_TAB,     	KC_LCTL,KC_LSFT,KC_SPC,                         _______   , _______  , _______       , _______  , XXXXXXX
  ),

  [3] = LAYOUT_universal(
    _______  , SCRL_DVD , CPI_I100 , KC_KB_VOLUME_UP , KC_F15 , KBC_SAVE ,                                   XXXXXXX , XXXXXXX, XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,
    _______  , SCRL_DVI , CPI_D100 , KC_KB_VOLUME_DOWN , KC_F14 , XXXXXXX  ,                                 S(G(KC_LBRC)) , G(KC_LBRC)  , G(KC_RBRC), S(G(KC_RBRC))  , XXXXXXX  , XXXXXXX  ,
    _______  , XXXXXXX  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                                            XXXXXXX , XXXXXXX , XXXXXXX   ,XXXXXXX,XXXXXXX,XXXXXXX,
              LSFT(KC_TAB),KC_TAB,     	KC_LCTL,KC_LSFT,KC_SPC,                    _______   , _______  , XXXXXXX       , XXXXXXX  , XXXXXXX
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
