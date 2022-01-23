#include QMK_KEYBOARD_H

// From root of qmk_firmware
// 
// To only compile:
// make handwired/dactyl_manuform/4x5:frisoft
// 
// To compile and flash:
// qmk flash -kb handwired/dactyl_manuform/4x5 -km frisoft 

// ======================================================================
// Super CMD-TAB

// bool is_cmd_tab_active = false;    // ADD this near the begining of keymap.c
// uint16_t cmd_tab_timer = 0;        // we will be using them soon.

// enum custom_keycodes {             // Make sure have the awesome keycode ready
//   CMD_TAB = SAFE_RANGE,
// };

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {               // This will do most of the grunt work with the keycodes.
//     case CMD_TAB:
//       if (record->event.pressed) {
//         if (!is_cmd_tab_active) {
//           is_cmd_tab_active = true;
//           register_code(KC_LGUI);
//         }
//         cmd_tab_timer = timer_read();
//         register_code(KC_TAB);
//       } else {
//         unregister_code(KC_TAB);
//       }
//       break;
//   }
//   return true;
// }

// void matrix_scan_user(void) {     // The very important timer.
//   if (is_cmd_tab_active) {
//     if (timer_elapsed(cmd_tab_timer) > 1000) {
//       unregister_code(KC_LGUI);
//       is_cmd_tab_active = false;
//     }
//   }
// }

// CMD-TAB end
// ======================================================================



#define _BASE 0
#define _L1 1
#define _L2 2
#define _L3 3
// #define _RAISE2 2
// #define _RAISE3 3
// #define _NUMPAD 4  
// #define _SYM 5  

// Fillers to make layering more clear

#define ____ KC_TRNS
#define XXXX KC_NO

// #define SFT_ESC  SFT_T(KC_ESC)
// #define CTL_BSPC CTL_T(KC_BSPC)
// #define ALT_SPC  ALT_T(KC_SPC)
// #define SFT_ENT  SFT_T(KC_ENT)

// #define SFT_F  SFT_T(KC_F)
// #define SFT_J  SFT_T(KC_J)
// #define CTL_D  CTL_T(KC_D)
// #define CTL_K  SFT_T(KC_K)
// #define ALT_S  ALT_T(KC_S)
// #define ALT_L  ALT_T(KC_L)

// #define SFT_4  SFT_T(KC_4)
// #define SFT_7  SFT_T(KC_7)
// #define CTL_3  CTL_T(KC_3)
// #define CTL_8  SFT_T(KC_8)
// #define ALT_2  ALT_T(KC_2)
// #define ALT_9  ALT_T(KC_9)

// #define SFT_Z     SFT_T(KC_Z)
// #define SFT_QUOT  SFT_T(KC_QUOT)

// #define CTL_A     CTL_T(KC_A)
// #define CTL_SCLN  CTL_T(KC_SCLN)

// #define KC_ML KC_MS_LEFT
// #define KC_MR KC_MS_RIGHT
// #define KC_MU KC_MS_UP
// #define KC_MD KC_MS_DOWN
// #define KC_MB1 KC_MS_BTN1
// #define KC_MB2 KC_MS_BTN2
// #define RAISE1 MO(_NAV)
// #define RAISE2 LM(_RAISE2, MOD_LGUI)
// #define RAISE2 MO(_RAISE2)
// #define RAISE3 MO(_RAISE3)

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case LT(_L1,KC_BSPC):
        case SFT_T(KC_SPC):
            return 180;
        case SFT_T(KC_Z):
        case CTL_T(KC_X):
        case ALT_T(KC_C):
        case GUI_T(KC_V):
        case GUI_T(KC_M):
        case ALT_T(KC_COMM):
        case CTL_T(KC_DOT):
        case CTL_T(KC_LBRC):
        case ALT_T(KC_RBRC):
        case GUI_T(KC_MINS):
        case GUI_T(KC_GRV):
        case ALT_T(KC_BSLS):
        case CTL_T(KC_SLSH):
        case SFT_T(KC_QUOT):
	/* case SFT_T(KC_A): */
	/* case SFT_T(KC_SCLN): */
            // return 180;
            return 250;
        case LT(_L1,KC_BSPC):
            return TAPPING_TERM-30;
        default:
            return TAPPING_TERM;
    }
}

// bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case SFT_T(KC_SPC):
//         // case SFT_T(KC_Z):
//         // case CTL_T(KC_X):
//         // case ALT_T(KC_C):
//         // case GUI_T(KC_V):
//         // case GUI_T(KC_M):
//         // case ALT_T(KC_COMM):
//         // case CTL_T(KC_DOT):
//         // case CTL_T(KC_LBRC):
//         // case ALT_T(KC_RBRC):
//         // case GUI_T(KC_MINS):
//         // case GUI_T(KC_GRV):
//         // case ALT_T(KC_BSLS):
//         // case CTL_T(KC_SLSH):
//         // case SFT_T(KC_QUOT):
//             return true;
//         case LT(_L1,KC_BSPC):
//             return false;
//         default:
//             return true;
//     }
// }

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (qwerty)
 * ,----------------------------------,                             ,----------------------------------,
 * |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |      |   s  |   d  |   f  |      |                             |      |   j  |   k  |   l  |      |
 * |   a  |   +  |   +  |   +  |   g  |                             |   h  |   +  |   +  |   +  |  ;:  |
 * |      |  ALT | CTRL | SHIFT|      |                             |      |SHIFT | CTRL |  ALT |      |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |  ,<  |  .>  |  '"  |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |  [{  |  ]}  |                                                         |  -_  |  =+  |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      | ESC  |  BS  |                             | SPACE|ENTER |
 *                      |  +   |   +  |                             |  +   |  +   |
 *                      | SHIFT| CTRL |                             | ALT  |SHIFT |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    | TAB  | HOME | | END  | DEL  |
 *                                    '------+------' '------+------'
 *                                    | Raise|  ~   | | GUI  | Lower|
 *                                    '------+------' '------+------' */

/*
[_BASE] = LAYOUT( \
  KC_Q,        KC_W,        KC_E,        KC_R,         KC_T,                                       KC_Y, KC_U,         KC_I,           KC_O,          KC_P,      \
  KC_A,        KC_S,        KC_D,        KC_F,         KC_G,                                       KC_H, KC_J,         KC_K,           KC_L,          KC_SCLN, \
  KC_Z,        KC_X,        KC_C,        KC_V,         KC_B,                                       KC_N, KC_M,         KC_COMM,        KC_DOT,        KC_QUOT, \
               KC_LBRC,     KC_RBRC,                                                                                   KC_MINS,        KC_EQL,            \
                                                           SFT_ESC, CTL_BSPC,    ALT_SPC, SFT_ENT,                                             \
                                                           KC_TAB,  RAISE,       LOWER,   KC_DEL,                                              \
                                                           KC_HOME, KC_GRV,      KC_LGUI, KC_END
),
*/
                                                 /* LT(_L1,KC_BSPC), LT(_L1, KC_TAB),             SFT_T(KC_ENT), SFT_T(KC_SPC), \ */
                                                        /* KC_TAB, LT(_L1,KC_BSPC),             SFT_T(KC_SPC), KC_ENT,                                                    \ */
                                                        /* KC_TAB, LT(_L1,KC_BSPC),             KC_ENT, SFT_T(KC_SPC), \ */

[_BASE] = LAYOUT( \
  KC_Q,          KC_W,           KC_E,             KC_R,           KC_T,                            KC_Y,    KC_U,          KC_I,           KC_O,           KC_P,            \
  KC_A,          KC_S,           KC_D,             KC_F,           KC_G,                            KC_H,    KC_J,          KC_K,           KC_L,           KC_SCLN,         \
  SFT_T(KC_Z),   CTL_T(KC_X),    ALT_T(KC_C),      GUI_T(KC_V),    KC_B,                            KC_N,    GUI_T(KC_M),   ALT_T(KC_COMM), CTL_T(KC_DOT),  SFT_T(KC_QUOT),  \
                 KC_LBRC,        KC_RBRC,                                                                                   KC_MINS,        KC_EQL,                        \
                                                 MO(_L1),           KC_LSFT,                           KC_RSFT, SFT_T(KC_SPC), \
                                                 OSM(MOD_LCTL),     KC_ESC,                            KC_ESC, OSM(MOD_LCTL),                                             \
                                                 RESET,      OSM(MOD_LGUI),               OSM(MOD_LGUI), RESET
),
                                                      // OSL(_L2), LT(_L1,KC_BSPC),            SFT_T(KC_SPC), KC_ENT,                                                     
                                            //  LT(_L2, KC_TAB), LT(_L1,KC_BSPC),              SFT_T(KC_SPC), KC_ENT,                                                    

[_L1] = LAYOUT( \
  KC_1,          KC_2,           KC_3,             KC_4,           KC_5,                            KC_6,    KC_7,          KC_8,           KC_9,           KC_0, \
  KC_TAB,        LCTL(KC_W),        KC_ESC,        KC_BSPC,      KC_DEL,                          KC_LEFT, KC_DOWN,       KC_UP,          KC_RIGHT,        KC_ENT, \
  OSM(MOD_LSFT), CTL_T(KC_LBRC), ALT_T(KC_RBRC),   KC_MINS,      KC_EQL,                            ____,    GUI_T(KC_GRV), ALT_T(KC_BSLS), CTL_T(KC_SLSH), ____, \
                 ____,    ____,                                                                                             ____,           ____,                 \
                                                             ____, ____,                            ____, ____,                                                            \
                                                             ____, ____,                            ____, ____,                                                            \
                                                             ____, ____,                            ____, RESET                                                             \
),

/*
[_L2] = LAYOUT( \
  S(KC_1),   S(KC_2),    S(KC_3),    S(KC_4),    S(KC_5),                         S(KC_6),    S(KC_7),    S(KC_8),    S(KC_9),     S(KC_0),      \
  ____,      ____,       S(KC_ESC),  S(KC_BSPC), S(KC_DEL),                       S(KC_LEFT), S(KC_DOWN), S(KC_UP),   S(KC_RIGHT), KC_ENT,   \
  ____,      S(KC_LBRC), S(KC_RBRC), S(KC_MINS), S(KC_EQL),                       ____,       S(KC_GRV),  S(KC_BSLS), S(KC_SLSH),  S(KC_DEL),    \
             ____,       ____,                                                                            ____,       ____,                      \
                                                   ____, ____,           ____, ____,                                                   \
                                                   ____, ____,           ____,      ____,                                                        \
                                                   ____, ____,           ____,      OSL(_L3)                                                     \
),
*/
  // ____,      ____,       S(KC_ESC),  S(KC_BSPC), S(KC_DEL),                       S(KC_LEFT), S(KC_DOWN), S(KC_UP),   S(KC_RIGHT), OSM(MOD_LALT),   
  //                                                 ____, ____,           S(KC_SPC), S(KC_ENT),                                                   

[_L3] = LAYOUT( \
  KC_F1,  KC_F2,  KC_F3, KC_F4, KC_F5,                             KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, \
  KC_F11, KC_F12, ____,  ____,  ____,                              ____,  ____,  ____,  ____,  ____,   \
  ____,   ____,   ____,  ____,  ____,                              ____,  ____,  ____,  ____,  ____,   \
          ____,   ____,                                            ____,  ____,                        \
                                       ____, ____,  ____, ____,                                        \
                                       ____, ____,  ____, ____,                                        \
                                       ____, ____,  ____, ____                                         \
),

/*
[_NAV] = LAYOUT( \
  RESET,   ____,    ____,    ____,    ____,                          LALT(KC_LEFT), KC_PGDOWN, KC_PGUP, LALT(KC_RIGHT), ____, \
  ____,    ____,    ____,    ____,    ____,                          KC_LEFT,       KC_DOWN,   KC_UP,   KC_RIGHT,       ____, \
  ____,    ____,    ____,    ____,    ____,                          KC_GRV,        KC_BSLS,   KC_SLSH, KC_QUES,        KC_PIPE, \
           ____,    ____,                                                                       ____,       ____,             \
                                            ____, ____,  ____, ____,                                                          \
                                            ____, ____,  ____, ____,                                                          \
                                            ____, ____,  ____, ____                                                           \
),
*/

/*
[_NUMPAD] = LAYOUT( \
  ____,    ____,    ____,    ____,    ____,                          ____,   KC_7,   KC_8,   KC_9,   ____, \
  ____,    ____,    ____,    ____,    ____,                          ____,   KC_4,   KC_5,   KC_6,   ____, \
  ____,    ____,    ____,    ____,    ____,                          ____,   KC_1,   KC_2,   KC_3,   ____, \
           ____,    ____,                                                            KC_0,   KC_DOT,             \
                                            ____, ____,  ____, ____,                                                          \
                                            ____, ____,  ____, ____,                                                          \
                                            ____, ____,  ____, ____                                                           \
),
*/

/*
[_SYM] = LAYOUT( \
  ____,    ____,    ____,    ____,    ____,                          ____,   KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN, \
  ____,    ____,    ____,    ____,    ____,                          ____,   KC_DLR,   KC_PERC, KC_CIRC, ____, \
  ____,    ____,    ____,    ____,    ____,                          ____,   KC_EXLM,  KC_AT,   KC_HASH, ____, \
           ____,    ____,                                                              KC_RPRN, ____,             \
                                            ____, ____,  ____, ____,                                                          \
                                            ____, ____,  ____, ____,                                                          \
                                            ____, ____,  ____, ____                                                           \
),
*/

/*
[_RAISE2] = LAYOUT( \
  KC_EXLM,      KC_AT,         KC_HASH,      KC_DLR,       KC_PERC,                          KC_CIRC, KC_AMPR,      KC_ASTR,      KC_LPRN,       KC_RPRN,       \
  KC_1,         KC_2,          KC_3,         KC_4,         KC_5,                             KC_6,    KC_7,         KC_8,         KC_9,          KC_0,          \
  XXXX,         XXXX,          XXXX,         XXXX,         KC_TILDE,                         KC_GRV,  KC_BSLS,      KC_SLSH,      KC_QUES,       KC_PIPE,       \
                KC_F11,        KC_F12,                                                                              ____,         ____,                         \
                                                                    ____, ____,  ____, ____,                                                                    \
                                                                    ____, ____,  ____, ____,                                                                    \
                                                                    ____, ____,  ____, ____                                                                     \
),
*/

/*
[_RAISE3] = LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                            KC_F6,   KC_F7,   KC_F8,    KC_F9,  KC_F10, \
  ____,    ____,    ____,    ____,    ____,                             ____,    ____,    ____,     KC_F11, KC_F12, \
  ____,    ____,    ____,    ____,    ____,                             ____,    ____,    ____,     ____,   ____,   \
           ____,    ____,                                                                 ____,     ____,           \
                                              ____, ____,  ____, ____,                                              \
                                              ____, ____,  ____, ____,                                              \
                                              ____, ____,  ____, ____                                               \
)
*/

/* Raise (OLD)
 * ,----------------------------------,                             ,----------------------------------,
 * |RESET |      |  mup |      |      |                             | VOL+ |      |  up  |      | PgUp |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |      | mleft| mdown|mright|      |                             | MUTE | left | down |right | PgDn |
 */

/* Raise
 * ,----------------------------------,                             ,----------------------------------,
 * |RESET |      |      |      |      |                             | VOL+ |      |  up  |      | PgUp |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |      | ALT  | CRTL |SHIFT |      |                             | MUTE | left | down |right | PgDn |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |      |      |      |      |      |                             | VOL- |  /   |  \   |  ?   |  |   |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |      |      |                                                         | mbtn |mbtn2 |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 */

/*
[_RAISE] = LAYOUT( \
  ____, ____,  KC_MU, ____,  ____,                          KC_VOLU, ____,    KC_UP,   ____,     KC_PGUP,   \
  ____, KC_ML, KC_MD, KC_MR, ____,                          KC_MUTE, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDOWN, \
  ____, ____,  ____,  ____,  ____,                          KC_VOLD, KC_SLSH, KC_BSLS, KC_QUES,  KC_PIPE,   \
           ____,    ____,                                                     KC_MB1,  KC_MB2,              \
                                            ____, ____,  ____, ____,                                                 \
                                            ____, ____,  ____, ____,                                                 \
                                            ____, ____,  ____, ____                                                  \
),
*/



/* Raise2
 * ,-------------------------------------,                             ,-------------------------------------,
 * |  F1  |  F2   |  F3   |  F4   |  F5  |                             |  F6  |  F7   |  F8   |  F9   |  F10 |
 * |------+-------+-------+-------+------|                             |--------------+-------+-------+------|
 * |      |   2   |   3   |   4   |      |                             |      |   7   |   8   |   9   |      |
 * |  1   |   +   |   +   |   +   |  5   |                             |  6   |   +   |   +   |   +   |  0   |
 * |      |  ALT  | CTRL  | SHIFT |      |                             |      | SHIFT | CTRL  |  ALT  |      |
 * |------+-------+-------+-------+------|                             |------|-------+-------+-------+------|
 * |  !   |   @   |   #   |   $   |  %   |                             |  ^   |   &   |   *   |    (  |  )   |
 * |------+-------+-------+--------------,                             ,--------------+-------+-------+------,
 *        |  F11  |  F12  |                                                           |   -   |   =   |
 *        '-------+-------'--------------'                             '--------------'-------+-------'
 *                        |       |      |                             |      |       |
 *                        |    KC_LGUI   |      |                             |      |       |
 *                        |       |      |                             |      |       |
 *                        '-------+------'                             '------+-------'
 *                                       '------+------' '------+------'
 *                                       |      |      | |      |      |
 *                                       '------+------' '------+------'
 *                                       |      |      | |      |      |
 *                                       '------+------' '------+------'
 */ 


/*
[_LOWER] = LAYOUT( \
  KC_F1,          KC_F2,         KC_F3,          KC_F4,          KC_F5,                            KC_F6,   KC_F7,            KC_F8,          KC_F9,          KC_F10,         \
  KC_1,           KC_2,          KC_3,           KC_4,           KC_5,                             KC_6,    KC_7,             KC_8,           KC_9,           KC_0,           \
  SFT_T(KC_EXLM), CTL_T(KC_AT),  ALT_T(KC_HASH), LGUI_T(KC_DLR), KC_PERC,                          KC_CIRC, LGUI_T(KC_AMPR),  ALT_T(KC_ASTR), CTL_T(KC_LPRN), SFT_T(KC_RPRN), \
                  KC_F11,        KC_F12,                                                                                      ____,           ____,                           \
                                                                          ____, ____,  ____, ____,                                                                            \
                                                                          ____, ____,  ____, ____,                                                                            \
                                                                          ____, ____,  ____, ____                                                                             \
)
*/


};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}


/* combos */
// enum combos {
//   SPCSC_COL
    // YU_BSPC
  // TI_TICK,
  // SL_SLASH,
  // HA_HASH,
  // PI_PIPE
// };

// const uint16_t PROGMEM spcsc_col[] = {KC_L, KC_SCLN, COMBO_END};
//const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END};
// const uint16_t PROGMEM ti_combo[] = {KC_T, KC_I, COMBO_END};
// const uint16_t PROGMEM sl_combo[] = {KC_S, KC_L, COMBO_END};
// const uint16_t PROGMEM ha_combo[] = {KC_H, KC_A, COMBO_END};
// const uint16_t PROGMEM pi_combo[] = {KC_P, KC_I, COMBO_END};

// combo_t key_combos[COMBO_COUNT] = {
  // [SPCSC_COL] = COMBO_ACTION(spcsc_col)
  // [SPCSC_COL] = COMBO(spcsc_col, KC_J)
  //[YU_BSPC] = COMBO(yu_combo, KC_BSPC),
  // [TI_TICK] = COMBO(ti_combo, KC_GRV),
  // [SL_SLASH] = COMBO(sl_combo, KC_SLSH),
  // [HA_HASH] = COMBO(ha_combo, KC_HASH),
  // [PI_PIPE] = COMBO(pi_combo, KC_PIPE)
// };

// void process_combo_event(uint8_t combo_index, bool pressed) {
//   switch(combo_index) {
//     case SPCSC_COL:
//       if (pressed) {
//         tap_code16(LSFT(KC_SCLN));
//       }
//       break;
//   }
// }
