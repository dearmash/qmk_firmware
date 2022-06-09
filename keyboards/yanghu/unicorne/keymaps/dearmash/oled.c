/* Copyright 2021 Yang Hu
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
#ifdef OLED_ENABLE
#    include QMK_KEYBOARD_H
#    include "layers.h"

// Some characters position:
// alt: 84 85 86/a..../c...
// shift:87 88 89/a.../c...
// ctrl: b6 b6/d.../
// capslock: 9c-9f/b.../d...
// numlock: 98-9b/b.../d...
// navigation logo: 92-95/b2.../d2...
// symbol logo: 8a-8d/aa..../ca....
// qmk logos; 8e-91/ae..../ce....
void oled_render_layer(void) {
    /* static const char PROGMEM cmd_logo[] = { */
    /*   0x80, 0x81, 0x82, 0x83, 10, */
    /*   0xa0, 0xa1, 0xa2, 0xa3, 10, */
    /*   0xc0, 0xc1, 0xc2, 0xc3, 10, */
    /*   0}; */
    // clang-format off
    static const char PROGMEM qmk_logo[] = {
      0x8e, 0x8f, 0x90, 0x91, 10,
      0xae, 0xaf, 0xb0, 0xb1, 10,
      0xce, 0xcf, 0xd0, 0xd1, 10, 0};
    // clang-format on
    if (IS_LAYER_ON(_BASE)) {
        oled_write_P(qmk_logo, false);
    } else {
        oled_write_ln("?????", false);
        oled_write_ln(" ", false);
        oled_write_ln(" ", false);
        oled_write_ln(" ", false);
    }
}

#endif
