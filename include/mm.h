/* mm.h - low level memory management
 *
 * This file is part of Nanoha.
 *
 * Nanoha is Free Software under the non-terms of
 * the Anti-License. Do whatever the fuck you want.
 */

#include <stddef.h>
#include <stdint.h>

#define PAGE_SIZE 4096
/* TODO: For now, use 256MiB as the memory size. Get the actual memory size from
 * the bootloader later. */
#define MEMORY_SIZE 268435456
/* For now, start at 2MiB */
#define MEMORY_START 0x200000

/* Request allocation of n contiguous pages. Returns a pointer to the start of
 * the group. */
void* alloc_pages(size_t n);

/* Free the given number of pages. */
void free_pages(void* start, size_t n);

/* Initialize the low level memory manager */
void mm_init(void);
