// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

enum layer_names {
    _CM,
    _RS,
    _LW,
    _NAV,
};

enum custom_keycodes {
    EMACS_WS1 = SAFE_RANGE,
    EMACS_WS2,
    EMACS_WS3,
    EMACS_WS4,
    EMACS_WS5,
};

// Shorten long key defs
#define OS_ALT OSM(MOD_LALT)
#define SUP_ESC LGUI_T(KC_ESC)
#define CTL_ENT LCTL_T(KC_ENT)
#define NAV_SPC LT(_NAV,KC_SPC)
#define WS1 LGUI(KC_1)
#define WS2 LGUI(KC_2)
#define WS3 LGUI(KC_3)
#define WS4 LGUI(KC_4)
#define WS5 LGUI(KC_5)
#define TAB_NEXT LCTL(KC_TAB)
#define TAB_PREV LCTL(LSFT(KC_TAB))

const uint16_t PROGMEM st_escape[] = {KC_S, KC_T, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {COMBO(st_escape, KC_ESC)};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_CM] = LAYOUT( /* Colemak */
    KC_Q,      KC_W,      KC_F,      KC_P,      KC_B,                            KC_J,      KC_L,      KC_U,      KC_Y,      KC_SCLN,
    KC_A,      KC_R,      KC_S,      KC_T,      KC_G,                            KC_M,      KC_N,      KC_E,      KC_I,      KC_O,
    KC_Z,      KC_X,      KC_C,      KC_D,      KC_V,     KC_GRV,    KC_BSLS,    KC_K,      KC_H,      KC_COMM,   KC_DOT,    KC_SLSH,
    KC_ESC,    KC_TAB,    OS_ALT,    KC_LSFT,   KC_BSPC,  SUP_ESC,   CTL_ENT,    NAV_SPC,   MO(_RS),   KC_MINS,   KC_QUOT,   KC_EQL),

  [_RS] = LAYOUT( /* [> RAISE <] */
    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                            KC_6,      KC_7,      KC_8,      KC_9,      KC_0,
    KC_HASH,   KC_DLR,    KC_LPRN,   KC_RPRN,   KC_CIRC,                         KC_PSLS,   KC_ASTR,   KC_LBRC,   KC_RBRC,   KC_PMNS,
    KC_EXLM,   KC_AT,     KC_LCBR,   KC_RCBR,   KC_PERC,   KC_TILD,   KC_PIPE,   KC_AMPR,   KC_COLN,   KC_COMM,   KC_DOT,    KC_PLUS,
    TG(2),     KC_TAB,    KC_LALT,   KC_LSFT,   KC_BSPC,   KC_LGUI,   KC_LCTL,   KC_SPC,    KC_TRNS,   KC_LT,     KC_GT,     KC_PEQL),

  [_LW] = LAYOUT( /* [> LOWER <] */
    KC_INS,    KC_HOME,   KC_UP,     KC_END,    KC_PGUP,                         KC_UP,     KC_F7,     KC_F8,     KC_F9,     KC_F10,
    KC_DEL,    KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_PGDN,                         KC_DOWN,   KC_F4,     KC_F5,     KC_F6,     KC_F11,
    KC_NO,     KC_VOLU,   KC_NO,     KC_NO,     RESET,     _______,   _______,   KC_NO,     KC_F1,     KC_F2,     KC_F3,     KC_F12,
    KC_NO,     KC_VOLD,   KC_LGUI,   KC_LSFT,   KC_BSPC,   _______,   _______,   KC_SPC,    TO(_CM),   KC_PSCR,   KC_SLCK,   KC_PAUS ),

  [_NAV] = LAYOUT( /* [> NAV <] */
    WS1,       WS2,       WS3,       WS4,       WS5,                             EMACS_WS1, EMACS_WS2, EMACS_WS3, EMACS_WS4, EMACS_WS5,
    KC_NO,     TAB_PREV,  KC_NO,     TAB_NEXT,  KC_NO,                           KC_NO,     KC_LEFT,   KC_DOWN,   KC_UP,     KC_RGHT,
    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_LSFT,   _______,   _______,   KC_TRNS,   KC_NO,     KC_NO,     KC_NO,     KC_NO )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case EMACS_WS1:
          if (record->event.pressed) {
              SEND_STRING(SS_DOWN(X_LCTL)"cw"SS_UP(X_LCTL)"1");
          }
          break;
      case EMACS_WS2:
          if (record->event.pressed) {
              SEND_STRING(SS_DOWN(X_LCTL)"cw"SS_UP(X_LCTL)"2");
          }
          break;
      case EMACS_WS3:
          if (record->event.pressed) {
              SEND_STRING(SS_DOWN(X_LCTL)"cw"SS_UP(X_LCTL)"3");
          }
          break;
      case EMACS_WS4:
          if (record->event.pressed) {
              SEND_STRING(SS_DOWN(X_LCTL)"cw"SS_UP(X_LCTL)"4");
          }
          break;
      case EMACS_WS5:
          if (record->event.pressed) {
              SEND_STRING(SS_DOWN(X_LCTL)"cw"SS_UP(X_LCTL)"5");
          }
          break;
    }
    return true;
};
