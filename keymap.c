/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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
#include "version.h"
#include "keymap_german.h"

enum layers {
    DVORAK, // default layer
    SYMBOL,
    MOVE_A,
    QWERTY,
    MOVE_B,
};

const key_override_t eql_override = ko_make_basic(MOD_MASK_SHIFT, KC_EQL, KC_BSLS);

const key_override_t **key_overrides = (const key_override_t *[]) {
    &eql_override,
    NULL // Null terminate the array of overrides!
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DVORAK] = LAYOUT(
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,             KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,
        KC_EQL,  KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Y,    LGUI(KC_F11), RGUI(KC_F12), KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
        KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_ESC,            KC_RGUI, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT,
        KC_DEL,  KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,                                KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RCTL,
        KC_LCTL, KC_LGUI, XXXXXXX, KC_LALT, KC_SPC,           DF(QWERTY),      DF(QWERTY),         KC_BSPC, KC_RALT, KC_RGUI, XXXXXXX, XXXXXXX,
                                            KC_LSFT, MO(SYMBOL), MO(MOVE_A),   MO(MOVE_A),MO(SYMBOL), KC_RSFT
    ),

    [SYMBOL] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_PLUS, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR, XXXXXXX,           XXXXXXX, KC_PIPE, KC_RPRN, KC_RCBR, KC_RBRC, KC_ASTR, XXXXXXX,
        XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,           XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
        DE_GRV,  KC_GRV,  KC_UNDS, KC_PERC, KC_AT,   KC_HASH,                             KC_CIRC, KC_DLR,  KC_EXLM, KC_MINS, KC_TILD, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,          XXXXXXX,           XXXXXXX,          _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            XXXXXXX, _______, XXXXXXX,           XXXXXXX, _______, XXXXXXX
    ),

    [MOVE_A] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RGHT, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, KC_LEFT, XXXXXXX, XXXXXXX, KC_HOME, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, KC_DOWN, KC_UP,   XXXXXXX,                             XXXXXXX, KC_END,  XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, _______, _______, _______,          XXXXXXX,           XXXXXXX,          _______, _______, _______, XXXXXXX, _______,
                                            _______, XXXXXXX, _______,           _______, XXXXXXX, _______
    ),

    [QWERTY] = LAYOUT(
        XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,           XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PGUP,
        KC_BSLS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    LGUI(KC_F11), RGUI(KC_F12), KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_PGDN,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_ESC,            KC_LGUI, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_DEL,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_RCTL,
        KC_LCTL, KC_LGUI, XXXXXXX, KC_LALT, KC_SPC,           DF(DVORAK),     DF(DVORAK),          KC_BSPC, KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT,
                                            KC_LSFT, XXXXXXX, MO(MOVE_B),     MO(MOVE_B), XXXXXXX, KC_RSFT
    ),

    [MOVE_B] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RGHT, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, KC_LEFT, XXXXXXX, XXXXXXX, KC_HOME, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, KC_DOWN, KC_UP,   XXXXXXX,                             XXXXXXX, KC_END,  XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, _______, _______, _______,          XXXXXXX,           XXXXXXX,          _______, _______, _______, XXXXXXX, _______,
                                            _______, XXXXXXX, _______,           _______, XXXXXXX, _______
    ),

    // [BLANK] = LAYOUT(
    //     _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
    //                                         _______, _______, _______,           _______, _______, _______
    // ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
switch (get_highest_layer(state|default_layer_state)) {
        case MOVE_A:
        case MOVE_B:
            rgb_matrix_set_color_all (37,206,209); //
            break;
        case SYMBOL:
            rgb_matrix_set_color_all (255,94,14); // orange
            break;
        case DVORAK:
            rgb_matrix_set_color_all (255,20,147); // pink
            break;
        case QWERTY:
            rgb_matrix_set_color_all (245,0,0); // red
            break;
    }
    return state;
}
