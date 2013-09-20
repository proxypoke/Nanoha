/* kprint.c - print kernel messages
 *
 * This file is part of Nanoha.
 *
 * Nanoha is Free Software under the non-terms of
 * the Anti-License. Do whatever the fuck you want.
 */

#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>

#include <string.h>

#include <vga.h>

void kprint(const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    const char* next;
    for (const char* tmp = fmt; *tmp; tmp++) {
        switch(*tmp) {
        default:
            term_putchar(*tmp);
            break;
        case '%':
            next = tmp + 1;
            if (*next == '%') {
                term_putchar('%');
            } else {
                char* str = va_arg(ap, const char*);
                kprint(str);
            }
        }
    }
}
