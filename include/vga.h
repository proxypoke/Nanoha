/* vga.h - text mode color constants
 *
 * This file is part of Nanoha.
 *
 * Nanoha is Free Software under the non-terms of
 * the Anti-License. Do whatever the fuck you want.
 */

#include <stddef.h>
#include <stdint.h>

/* Hardware text mode color constants. */
enum vga_color
{
    COLOR_BLACK = 0,
    COLOR_BLUE = 1,
    COLOR_GREEN = 2,
    COLOR_CYAN = 3,
    COLOR_RED = 4,
    COLOR_MAGENTA = 5,
    COLOR_BROWN = 6,
    COLOR_LIGHT_GREY = 7,
    COLOR_DARK_GREY = 8,
    COLOR_LIGHT_BLUE = 9,
    COLOR_LIGHT_GREEN = 10,
    COLOR_LIGHT_CYAN = 11,
    COLOR_LIGHT_RED = 12,
    COLOR_LIGHT_MAGENTA = 13,
    COLOR_LIGHT_BROWN = 14,
    COLOR_WHITE = 15,
};

/* Create a VGA color. */
uint8_t vga_mkcolor(enum vga_color fg, enum vga_color bg);
/* Create a VGA entry. */
uint16_t vga_mkentry(char c, uint8_t color);

/* Blank the terminal and initialize internal state. */
void term_init(void);

/* Set the fore- and background color. */
void term_setcolor(uint8_t color);

/* Put a vgaentry at a specific position on the screen. */
void term_putentryat(char c, uint8_t color, size_t x, size_t y);

/* Write a single char to the current position on the screen. */
void term_putchar(char c);
