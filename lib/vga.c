/* vga.c - simple vga driver
 *
 * This file is part of Nanoha.
 *
 * Nanoha is Free Software under the non-terms of
 * the Anti-License. Do whatever the fuck you want.
 */

#include <vga.h>

uint8_t vga_mkcolor(enum vga_color fg, enum vga_color bg) {
    return fg | (bg << 4);
}

uint16_t vga_mkentry(char c, uint8_t color) {
    uint16_t c16 = c;
    uint16_t color16 = color;
    return c16 | (color16 << 8);
}

static const size_t VGA_HEIGHT = 80;
static const size_t VGA_WIDTH = 24;

static size_t term_row;
static size_t term_col;
static uint8_t term_color;
static uint16_t* term_buf;

void term_init(void) {
    term_row = 0;
    term_col = 0;
    term_color = vga_mkcolor(COLOR_LIGHT_GREY, COLOR_BLACK);
    term_buf = (uint16_t*) 0xB8000;
    for (size_t i = 0; i < (VGA_HEIGHT * VGA_WIDTH); i++) {
        term_buf[i] = vga_mkentry(' ', term_color);
    }
}

void term_setcolor(uint8_t color) {
    term_color = color;
}

void term_putentryat(char c, uint8_t color, size_t x, size_t y) {
    const size_t index = y * VGA_WIDTH + x;
    term_buf[index] = vga_mkentry(c, color);
}

void term_putchar(char c) {
    term_putentryat(c, term_color, term_col, term_row);
    /*
    switch (c) {
        case '\n':
            term_col = 0;
            term_row++;
            break;
        default:
            term_putentryat(c, term_color, term_col, term_row);
    }
    */
    if (++term_col == VGA_WIDTH) {
        term_col = 0;
        if (++term_row == VGA_HEIGHT) {
            term_row = 0;
        }
    }
}
