// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_italian_mac_iso.h"

enum layers { _BASE, _FN, _ARROWS };

// Custom keycode: types the Java line-comment "//"
enum custom_keycodes { JV_CMNT = SAFE_RANGE };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Either Shift key (left OR right) momentarily activates the arrow layer.
    [_BASE] = LAYOUT(
        KC_TAB,        KC_1,  KC_2,  KC_3,  KC_4,  KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_ESC,        KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    S(KC_MINS),
        KC_LSFT,       KC_A,  KC_S,  KC_D,  KC_F,  KC_G,                   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        MO(_ARROWS),   KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,                   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MO(_ARROWS),
                                            KC_LGUI, KC_LGUI, KC_SPC,           KC_SPC, KC_RCTL,  KC_RALT
    ),
    [_FN] = LAYOUT(
        KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_PGUP, KC_PGDN, KC_HOME, KC_END,  KC_DEL,  KC_F12,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_LBRC, KC_RBRC,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
    // Arrow layer: held while either Shift / layer-switch key is pressed.
    // Thumb keys become arrows: Left / Up (left thumbs), Down / Right (right thumbs).
    // Home row becomes brackets: a={ s=} d=[ f=] g=( h=)
    [_ARROWS] = LAYOUT(
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, IT_SLSH, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  IT_LCBR, IT_RCBR, IT_LBRC, IT_RBRC, IT_LPRN,                            IT_RPRN, IT_QUES, IT_EQL,  IT_PLUS, KC_TRNS, KC_TRNS,
        KC_TRNS,  IT_HASH, JV_CMNT, KC_VOLD, KC_VOLU, KC_MPRV,                            KC_MNXT, KC_TRNS, IT_LABK, IT_RABK, KC_TRNS, KC_TRNS,
                                            KC_LEFT, KC_UP,  KC_TRNS,           KC_TRNS, KC_DOWN, KC_RGHT
    )
};

/* Number-row Shift overrides: on Italian-Mac OS plain Shift+<n> gives the
 * Italian symbols, but the keycaps show the US ANSI legends. These overrides
 * make Shift+<n> emit the symbol printed on the keycap instead. */
const key_override_t ko_excl = ko_make_basic(MOD_MASK_SHIFT, KC_1, IT_EXLM); // !
const key_override_t ko_at   = ko_make_basic(MOD_MASK_SHIFT, KC_2, IT_AT);   // @
const key_override_t ko_hash = ko_make_basic(MOD_MASK_SHIFT, KC_3, IT_HASH); // #
const key_override_t ko_dlr  = ko_make_basic(MOD_MASK_SHIFT, KC_4, IT_DLR);  // $
const key_override_t ko_perc = ko_make_basic(MOD_MASK_SHIFT, KC_5, IT_PERC); // %
const key_override_t ko_circ = ko_make_basic(MOD_MASK_SHIFT, KC_6, IT_CIRC); // ^
const key_override_t ko_ampr = ko_make_basic(MOD_MASK_SHIFT, KC_7, IT_AMPR); // &
const key_override_t ko_astr = ko_make_basic(MOD_MASK_SHIFT, KC_8, IT_ASTR); // *
const key_override_t ko_lprn = ko_make_basic(MOD_MASK_SHIFT, KC_9, IT_LPRN); // (
const key_override_t ko_rprn = ko_make_basic(MOD_MASK_SHIFT, KC_0, IT_RPRN); // )

const key_override_t *key_overrides[] = {
    &ko_excl, &ko_at,   &ko_hash, &ko_dlr,  &ko_perc,
    &ko_circ, &ko_ampr, &ko_astr, &ko_lprn, &ko_rprn,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case JV_CMNT:
            if (record->event.pressed) {
                tap_code16(IT_SLSH);
                tap_code16(IT_SLSH);
            }
            return false;
    }
    return true;
}
