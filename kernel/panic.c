/* panic.c - when things went horribly wrong
 *
 * This file is part of Nanoha.
 *
 * Nanoha is Free Software under the non-terms of
 * the Anti-License. Do whatever the fuck you want.
 */

#include <kernel.h>

void panic(const char* reason) {
    kprint("Kernel panic: %", reason);
    __asm__("cli");
    for (;;) {
        __asm__("hlt");
    }
}
