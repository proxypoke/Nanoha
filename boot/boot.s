/* boot.s - kernel entry point
 *
 * This file is part of Nanoha.
 *
 * Nanoha is Free Software under the non-terms of
 * the Anti-License. Do whatever the fuck you want.
 */

/* Set up constants for the multiboot header. */
.set MB_ALIGN,   1<<0
.set MB_MEMINFO, 1<<1
.set MB_FLAGS,   MB_ALIGN | MB_MEMINFO
.set MB_MAGIC,   0x1BADB002
.set MB_CHECKSUM, -(MB_MAGIC + MB_FLAGS)

/* Declare the multiboot header. */
.section .multiboot
.align 4
.long MB_MAGIC
.long MB_FLAGS
.long MB_CHECKSUM

/* Create a bootstrap stack. */
.section .bootstrap_stack
stack_bottom:
.skip 16384
stack_top:

/* Provide an entry point and call the kernel. */
.section .text
.global _start
.type _start, @function
_start:
    /* Move the stack pointer to the bootstrap stack. */
    movl $stack_top, %esp

    /* Standby ready, set up */
    call kernel_main
    
    /* kernel_main should never return. However, in case it does, we bring down
     * the CPU and loop forever to prevent weird and potentially harmful stuff
     * from happening.
     */
    cli
    hlt
.Lhang:
    jmp .Lhang
