/* mm.c - low level memory management
 *
 * This file is part of Nanoha.
 *
 * Nanoha is Free Software under the non-terms of
 * the Anti-License. Do whatever the fuck you want.
 */

#include <mm.h>

static void* first_free;
static void* end_of_memory;

/* Return the size of the available memory. */
static size_t get_memsize() {
    /* TODO: Actually implement this. */
    return MEMORY_SIZE;
}

void* mm_alloc_pages(size_t n) {
    if (first_free + (n * PAGE_SIZE) > end_of_memory) {
        return NULL;
    }
    void* start = first_free;
    first_free += n * PAGE_SIZE;
    return start;
}

void mm_free_pages(void* start, size_t n) {
    /* TODO */
}

void mm_init(void) {
    first_free = (uintptr_t*) MEMORY_START;
    end_of_memory = first_free + get_memsize();
}
