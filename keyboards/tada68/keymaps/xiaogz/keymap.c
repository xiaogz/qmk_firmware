#include "tada68.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1

#define PASS_UNDER KC_TRNS
#define TAPPING_TOGGLE 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |~ ` | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |ESC |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |Ctrl   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          | FN|Alt|Ctrl| Lef|Dow|Rig|
   * `----------------------------------------------------------------'
   */
[_BL] = KEYMAP_ANSI(
  KC_GRV,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC,KC_ESC, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS,KC_DEL, \
  KC_LCTL, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,KC_PGUP,  \
  KC_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   KC_RSFT,KC_UP,KC_PGDN, \
  KC_LCTL, KC_LGUI,KC_LALT, KC_SPC, TT(_FL), KC_RALT,KC_RCTRL, KC_LEFT,KC_DOWN,KC_RGHT),

  /* Keymap _FL: Function Layer
   * ,----------------------------------------------------------------.
   * |Esc| F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|       |    |
   * |----------------------------------------------------------------|
   * |     |Pup|Up |Pdn|   |   |   |   |   |   |PSc|   |   |     |Ins | Pup/dn = page up/down; PSc = print screen
   * |----------------------------------------------------------------|
   * |Caps  |<- |Dn | ->|   |   |   |   |   |   |   |   |        |Hme |
   * |----------------------------------------------------------------|
   * |         |MUT|VU-|VU+|BLR|BL |BL-|BL+|F14 |F15 |   |McL|MsU|End | * see below for F14 & F15 note
   * |----------------------------------------------------------------|
   * |    |    |    |                      |    |McR |   |MsL|MsD|MsR |
   * `----------------------------------------------------------------'
   * QMK can't control laptop screen brightness so f14 & 15 will
   *  call gnome-configured screen brightness controls; need xdotool package
   *  & additional configuration in keyboard shortcuts
   */
[_FL] = KEYMAP_ANSI(
  KC_ESC, KC_F1 ,KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, PASS_UNDER, TO(_BL) ,  \
  PASS_UNDER,KC_PGUP, KC_UP, KC_PGDN,PASS_UNDER, PASS_UNDER,PASS_UNDER,PASS_UNDER,PASS_UNDER,PASS_UNDER,KC_PSCR,PASS_UNDER,PASS_UNDER, PASS_UNDER,KC_INS, \
  KC_CAPS,KC_LEFT,KC_DOWN,KC_RIGHT,PASS_UNDER,PASS_UNDER,PASS_UNDER,PASS_UNDER,PASS_UNDER,PASS_UNDER,PASS_UNDER,PASS_UNDER,PASS_UNDER,KC_HOME, \
  PASS_UNDER,KC_MUTE,KC_VOLD,KC_VOLU, BL_BRTG, BL_TOGG, BL_DEC, BL_INC,KC_F14,KC_F15,PASS_UNDER,KC_BTN1, KC_MS_U, KC_END, \
  PASS_UNDER,PASS_UNDER,PASS_UNDER,                 PASS_UNDER,               PASS_UNDER,KC_BTN2,PASS_UNDER,KC_MS_L,KC_MS_D, KC_MS_R),
};
