#include QMK_KEYBOARD_H
// #include <print.h>

// Tap Dance declarations
enum {
    TD_2_0,
    TD_6_ENT,
    TD_9_BSPC,
    TD_3_DOT
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_2_0] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_0),
    [TD_6_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_ENT),
    [TD_3_DOT] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_PDOT),
    [TD_9_BSPC] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_BSPC),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Keymap 0: Numpad Layer
    [0] = LAYOUT(
                        KC_7, KC_8,       TD(TD_9_BSPC),
                        KC_4, KC_5,       TD(TD_6_ENT),
        KC_AUDIO_MUTE,  KC_1, TD(TD_2_0), TD(TD_3_DOT)
    ),

    // Keymap 0: Arrow Layer
    [1] = LAYOUT(
                        KC_HOME, KC_END,  KC_BSPC,
                        KC_DEL,   KC_UP,   KC_ENTER,
        KC_TRANSPARENT, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    // Keymap 2: RGB control Layer
    [2] = LAYOUT(
                        RGB_TOG, RGB_MODE_FORWARD, RGB_MODE_REVERSE,
                        KC_TRANSPARENT, KC_NO, KC_NO,
        KC_TRANSPARENT, KC_NO, KC_NO, KC_NO
    ),
};

uint8_t selected_layer = 0;
bool encoder_update_user(uint8_t index, bool clockwise) {
  switch (index) {
    case 0:
      if (!clockwise && selected_layer  < 2) {
        selected_layer ++;
      } else if (clockwise && selected_layer  > 0){
        selected_layer --;
      }
      layer_clear();
      layer_on(selected_layer);
      oled_on();
  }
  return true;
};

#ifdef OLED_ENABLE
void oled_task_user(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("NUMBERS\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("ARROWS\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("RGB\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
}
#endif

// debugging
// void keyboard_post_init_user(void) {
//     // Customise these values to desired behaviour
//     debug_enable = true;
//     debug_matrix = true;
//     // debug_keyboard=true;
//     // debug_mouse=true;
// }

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     // If console is enabled, it will print the matrix position and status of each key pressed
// #ifdef CONSOLE_ENABLE
//     uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
// #endif
//     return true;
// }