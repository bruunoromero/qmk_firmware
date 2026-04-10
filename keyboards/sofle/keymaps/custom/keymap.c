// Copyright 2024 bromero
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Translated from Vial .vil configuration for Sofle rev1
#include QMK_KEYBOARD_H

// ---------------------------------------------------------------------------
// Custom keycodes for macros
// ---------------------------------------------------------------------------
enum custom_keycodes {
    RETOOL_HDR = QK_USER,  // "x-retool-acting-account-id"
    RETOOL_ID,             // "{{actingAccountSelector1.actingAccountId}}"
    RETOOL_NID,            // "{{!actingAccountSelector1.actingAccountId}}"
};

// ---------------------------------------------------------------------------
// Tap Dance declarations
// ---------------------------------------------------------------------------
enum tap_dances {
    TD_CAPS_LSFT,  // Tap = CapsLock, Hold = LShift
    TD_RBRC_MO3,   // Tap = ], Hold = MO(3)
};

// Forward declare tap dance MO(3) functions
void td_mo3_finished(tap_dance_state_t *state, void *user_data);
void td_mo3_reset(tap_dance_state_t *state, void *user_data);

tap_dance_action_t tap_dance_actions[] = {
    [TD_CAPS_LSFT] = ACTION_TAP_DANCE_DOUBLE(KC_CAPS, KC_LSFT),
    [TD_RBRC_MO3]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_mo3_finished, td_mo3_reset),
};

// ---------------------------------------------------------------------------
// Layer names
// ---------------------------------------------------------------------------
enum sofle_layers {
    _BASE,     // Layer 0: Custom QWERTY
    _SYMBOLS,  // Layer 1: Numbers & Symbols
    _NAV,      // Layer 2: Navigation & Mouse
    _EXTEND,   // Layer 3: Extended functions
    _GAMING,   // Layer 4: Gaming (clean QWERTY)
};

// ---------------------------------------------------------------------------
// Keymap
// ---------------------------------------------------------------------------
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * Layer 0: Base (Custom QWERTY)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   -  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |   =  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |HypTab|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------| Play  |    | Mute  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCtl | LAlt | LGui |MO(1) | /Space  /       \BkSpc \  |MO(2) | Hyper|   ]  | Hyper|
 *            |      |      |      |      |/       /         \      \ |      | (OSM)|      | (OSM)|
 *            `----------------------------------'           '------''---------------------------'
 */
[_BASE] = LAYOUT(
  KC_GRV,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_ESC,        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
  ALL_T(KC_TAB), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MPLY,  KC_MUTE,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                           KC_LCTL, KC_LALT, KC_LGUI, MO(1),   KC_SPC,   KC_BSPC, MO(2),   OSM(MOD_HYPR), OSM(MOD_HYPR), KC_RBRC
),

/*
 * Layer 1: Numbers & Symbols
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  __  | RGB  |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  __  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  __  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |  __  |   =  |   -  |   +  |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  |RShft |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |  __  |  __  |      | xxxx | /Enter  /       \BkSpc \  | MC_0 | MC_1 | MC_2 |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_SYMBOLS] = LAYOUT(
  _______,  RM_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
  _______,  S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),                       S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), S(KC_BSLS),
  _______,  KC_EQL,  KC_MINS, S(KC_EQL), S(KC_LBRC), S(KC_RBRC), XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_SCLN, S(KC_SCLN), KC_BSLS, KC_RSFT,
                      _______, _______, XXXXXXX, XXXXXXX, KC_ENT,          KC_BSPC, RETOOL_HDR, RETOOL_ID, RETOOL_NID, XXXXXXX
),

/*
 * Layer 2: Navigation & Mouse
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  __  |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  __  |  __  |  __  |  __  | Btn3 | Btn1 |                    | MsLt | MsDn | MsUp | MsRt |      |  __  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Caps |  __  |  __  |  __  |  __  | Caps |-------.    ,-------| Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |  __  |      |      |      |      |      |-------|    |-------|      |  __  |      |      |      |  __  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |  __  |  __  |      | xxxx | /Enter  /       \      \  | xxxx |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NAV] = LAYOUT(
  _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______,  _______, _______, _______, MS_BTN3, MS_BTN1,                        MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, XXXXXXX, _______,
  KC_CAPS,  _______, _______, _______, _______, KC_CAPS,                        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
  _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                      _______, _______, XXXXXXX, XXXXXXX, KC_ENT,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/*
 * Layer 3: Extended Functions
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  __  |   !  |  __  |  __  |  __  |  __  |                    |  __  |   &  |  __  |  __  |   -  |   =  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  __  |   `  |   \  | App  |      |      |                    |  __  |  __  |  __  |   [  |   ]  |A+Bsp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  __  | LAlt | LCtl |LShft | Paste|      |-------.    ,-------| Left | Down |  Up  | Right|   \  |   \  |
 * |------+------+------+------+------+------|  __   |    |       |------+------+------+------+------+------|
 * |  __  | Undo | Cut  | Copy | Paste|      |-------|    |-------|      |  __  |      |  __  |      |  __  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |  __  |  __  |  __  |Sf/Ent| /  __   /       \  __  \  |  __  |  __  |  __  |  __  |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_EXTEND] = LAYOUT(
  _______,  S(KC_1), _______, _______, _______, _______,                        _______, S(KC_7), _______, _______, KC_MINS, KC_EQL,
  _______,  KC_GRV,  KC_BSLS, KC_APP,  XXXXXXX, XXXXXXX,                       _______, _______, _______, KC_LBRC, KC_RBRC, LALT(KC_BSPC),
  _______,  KC_LALT, KC_LCTL, KC_LSFT, KC_PSTE, XXXXXXX,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSLS, KC_BSLS,
  _______,  KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, XXXXXXX, _______,    XXXXXXX,  XXXXXXX, _______, XXXXXXX, _______, XXXXXXX, _______,
                      _______, _______, _______, LSFT_T(KC_ENT), _______, _______, _______, _______, _______, _______
),

/*
 * Layer 4: Gaming (clean QWERTY)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   `  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------| Mute  |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |MO(2) | /Enter  /       \Space \  |MO(3) | RCtl | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_GAMING] = LAYOUT(
  KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,    XXXXXXX,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                      KC_LGUI, KC_LALT, KC_LCTL, MO(2),   KC_ENT,    KC_SPC,   MO(3),   KC_RCTL, KC_RALT, KC_RGUI
),

};

// ---------------------------------------------------------------------------
// Encoder map (per-layer)
// ---------------------------------------------------------------------------
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE]    = { ENCODER_CCW_CW(KC_MRWD, KC_MFFD), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_SYMBOLS] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [_NAV]     = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [_EXTEND]  = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_GAMING]  = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
};
#endif

// ---------------------------------------------------------------------------
// Macros
// ---------------------------------------------------------------------------
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RETOOL_HDR:
            if (record->event.pressed) {
                SEND_STRING("x-retool-acting-account-id");
            }
            return false;
        case RETOOL_ID:
            if (record->event.pressed) {
                SEND_STRING("{{actingAccountSelector1.actingAccountId}}");
            }
            return false;
        case RETOOL_NID:
            if (record->event.pressed) {
                SEND_STRING("{{!actingAccountSelector1.actingAccountId}}");
            }
            return false;
    }
    return true;
}

// ---------------------------------------------------------------------------
// Tap Dance: TD_RBRC_MO3 (Tap = ], Hold = MO(3))
// ---------------------------------------------------------------------------
void td_mo3_finished(tap_dance_state_t *state, void *user_data) {
    if (state->pressed) {
        // Held: activate layer 3
        layer_on(_EXTEND);
    } else {
        // Tapped: send ]
        tap_code(KC_RBRC);
    }
}

void td_mo3_reset(tap_dance_state_t *state, void *user_data) {
    if (state->pressed) {
        layer_off(_EXTEND);
    }
}

// ---------------------------------------------------------------------------
// OLED
// ---------------------------------------------------------------------------
#ifdef OLED_ENABLE
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_write_P(PSTR("\n\n"), false);
        // Show current layer
        switch (get_highest_layer(layer_state)) {
            case _BASE:
                oled_write_ln_P(PSTR("Base"), false);
                break;
            case _SYMBOLS:
                oled_write_ln_P(PSTR("Sym"), false);
                break;
            case _NAV:
                oled_write_ln_P(PSTR("Nav"), false);
                break;
            case _EXTEND:
                oled_write_ln_P(PSTR("Ext"), false);
                break;
            case _GAMING:
                oled_write_ln_P(PSTR("Game"), false);
                break;
            default:
                oled_write_ln_P(PSTR("???"), false);
        }
        oled_write_P(PSTR("\n\n"), false);
        oled_write_ln_P(PSTR("LAYER"), false);
        oled_write_P(PSTR("\n\n"), false);
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
    }
    return true;
}
#endif
