/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

#define MOUSEKEY_DELAY 0
/* #define MOUSEKEY_TIME_TO_MAX 10 (You cannot redefine this setting!?) */
#define MOUSEKEY_MOVE_DELTA 20

/* Use I2C or Serial, not both */
#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */

#define MASTER_LEFT
//#define MASTER_RIGHT
//#define EE_HANDS

#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2000

// #define COMBO_COUNT 1
// #define COMBO_TERM 70

// #define AUTO_SHIFT_TIMEOUT 150

#define TAPPING_TERM 300
/* #define TAPPING_TERM_PER_KEY */

#define SPC_SFT_TAPPING_TERM 50

/* #define PERMISSIVE_HOLD */
/* #define HOLD_ON_OTHER_KEY_PRESS */

// #define IGNORE_MOD_TAP_INTERRUPT_PER_KEY

// Prefer sequence of taps instead of HOLD version
#define IGNORE_MOD_TAP_INTERRUPT

/* #define TAPPING_FORCE_HOLD */

/* #define RETRO_TAPPING_PER_KEY */
/* #define RETRO_TAPPING */

// #define ONESHOT_TAP_TOGGLE 0  /* Tapping this number of times holds the key
// until tapped once again. */
#define ONESHOT_TIMEOUT                                                        \
  1000 /* Time (in ms) before the one shot key is released */

// #define AUTO_SHIFT_TIMEOUT 135
// #define NO_AUTO_SHIFT_ALPHA
