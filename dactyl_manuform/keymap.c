#include QMK_KEYBOARD_H

// From root of qmk_firmware
//
// To only compile:
// make handwired/dactyl_manuform/4x5:frisoft
//
// To compile and flash:
// qmk flash -kb handwired/dactyl_manuform/4x5 -km frisoft

#define _BASE 0
#define _L1 1
#define _L2 2

// Fillers to make layering more clear
#define ____ KC_TRNS
#define XXXX KC_NO


// SPC_SFT implement SFT_T(KC_SPC) with RETRO_TAPPING
// This custom implementation is needed as the RETRO_TAPPING does not work well:
// It is deactiated by a key pressed immediately before the SFT_T(KC_SPC) key.

enum custom_keycodes {
  SPC_SFT
};

bool spc_sft_active = false;
bool spc_sft_sent = false;
bool spc_sft_retrotapping = false;
uint16_t spc_sft_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch(keycode) {
		case SPC_SFT:
			if (record->event.pressed) {
        if(!spc_sft_active) {
          spc_sft_active = true;
          spc_sft_sent = false;
          spc_sft_retrotapping = false;
        }
        spc_sft_timer = timer_read();
			} else {
        unregister_code(KC_LSFT);
        if(timer_elapsed(spc_sft_timer) <= SPC_SFT_TAPPING_TERM || spc_sft_retrotapping ) {
          tap_code(KC_SPC);
        }
        spc_sft_active = false;
        spc_sft_retrotapping = false;
      }
			return false;
			break;
    default:
      if(spc_sft_retrotapping) {
        spc_sft_retrotapping = false;
      }
			return true;
			break;
  }
  return true;
}

void matrix_scan_user(void) {
  if (spc_sft_active) {
    if (!spc_sft_sent && timer_elapsed(spc_sft_timer) > SPC_SFT_TAPPING_TERM) {
      register_code(KC_LSFT);
      spc_sft_sent = true;
      // It is important that the retrotapping is enabled as late as possible or it well be disabled by a
      // key pressed just before the SPC_SFT
      spc_sft_retrotapping = true;
    }
  }
}


// TODO: find why to I need this one?
void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}


// My Kyemap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT( \
  KC_Q,          KC_W,           KC_E,             KC_R,           KC_T,                            KC_Y,    KC_U,          KC_I,           KC_O,           KC_P,            \
  KC_A,          KC_S,           KC_D,             KC_F,           KC_G,                            KC_H,    KC_J,          KC_K,           KC_L,           KC_SCLN,         \
  SFT_T(KC_Z),   CTL_T(KC_X),    ALT_T(KC_C),      GUI_T(KC_V),    KC_B,                            KC_N,    GUI_T(KC_M),   ALT_T(KC_COMM), CTL_T(KC_DOT),  SFT_T(KC_QUOT),  \
                 XXXX,           XXXX,                                                                                      XXXX,           XXXX,                            \
                                                 MO(_L1),          MO(_L2),                      KC_LSFT, SPC_SFT, \
                                                 MO(_L2),     KC_ESC,                            KC_ESC, OSM(MOD_LCTL),                                             \
                                                 RESET,      OSM(MOD_LGUI),               OSM(MOD_LGUI), RESET
),

[_L1] = LAYOUT( \
  KC_1,          KC_2,           KC_3,             KC_4,           KC_5,                            KC_6,    KC_7,          KC_8,           KC_9,           KC_0, \
  KC_TAB,        LCTL(KC_W),        KC_ESC,        KC_BSPC,      KC_DEL,                          KC_LEFT, KC_DOWN,       KC_UP,          KC_RIGHT,        KC_ENT, \
  OSM(MOD_LSFT), CTL_T(KC_LBRC), ALT_T(KC_RBRC),   KC_MINS,      KC_EQL,                            ____,    GUI_T(KC_GRV), ALT_T(KC_BSLS), CTL_T(KC_SLSH), ____, \
                 ____,    ____,                                                                                             ____,           ____,                 \
                                                             ____, ____,                            ____, ____,                                                            \
                                                             ____, ____,                            ____, ____,                                                            \
                                                             ____, ____,                            ____, RESET                                                             \
),

[_L2] = LAYOUT( \
  KC_F1,  KC_F2,  KC_F3, KC_F4, KC_F5,                             KC_F6,       KC_F7,         KC_F8,       KC_F9,         KC_F10, \
  KC_F11, KC_F12, ____,  ____,  ____,                              KC_MS_LEFT,  KC_MS_DOWN,    KC_MS_UP,    KC_MS_RIGHT,   KC_MS_BTN1,  \
  ____,   ____,   ____,  ____,  ____,                              ____,        KC_MS_WH_DOWN, KC_MS_WH_UP, ____,          ____,   \
          ____,   ____,                                            ____,        ____,                        \
                                       ____, ____,  ____, ____,                                        \
                                       ____, ____,  ____, ____,                                        \
                                       ____, ____,  ____, ____                                         \
)
};

