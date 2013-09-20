/* kernel_main.c - main kernel routine
 *
 * This file is part of Nanoha.
 *
 * Nanoha is Free Software under the non-terms of
 * the Anti-License. Do whatever the fuck you want.
 */

#include <kernel.h>
#include <vga.h>

void kernel_main(void) {
    term_init();
    kprint("Standby ready, set up!");
}
