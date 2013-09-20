/* kprint.c - print kernel messages
 *
 * This file is part of Nanoha.
 *
 * Nanoha is Free Software under the non-terms of
 * the Anti-License. Do whatever the fuck you want.
 */

#include <stddef.h>
#include <stdint.h>

#include <string.h>

#include <vga.h>

void kprint(const char* str) {
    for (size_t i = 0; i < strlen(str); i++) {
        term_putchar(str[i]);
    }
}
