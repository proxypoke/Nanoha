/* mm.c - low level memory management
 *
 * This file is part of Nanoha.
 *
 * Nanoha is Free Software under the non-terms of
 * the Anti-License. Do whatever the fuck you want.
 */

#include <mm.h>
#include <stdbool.h>

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

void mm_free_pages(void* start __attribute__((unused)),
                   size_t n __attribute__((unused))) {
    /* TODO */
}

static inline void _enable_paging(void) {
    __asm__ volatile(
             "movl %cr0, %eax\n"
             "orl  $0x80000000, %eax\n"
             "movl %eax, %cr0\n"
    );
}

/* For every page table, make an entry in the Page Directory.
 * TODO: less magic numbers */
static void _init_page_directory(void) {
    struct pde* pd_ptr = (struct pde*) PD_PHYSICAL_ADDRESS;
    uint32_t pt_ptr    = PT_PHYSICAL_ADDRESS;

    while (pd_ptr < (struct pde*) PT_PHYSICAL_ADDRESS) {
        struct pde new_entry;
        new_entry.address   = pt_ptr >> 12;
        new_entry.readwrite = true;
        new_entry.present   = true;
        *pd_ptr = new_entry;

        pd_ptr++;
        pt_ptr += 4096 * 1024;
    }
}

/* Map a page block into virtual memory. */
static void _map_page(uint32_t vaddr, uint32_t paddr) {
    uint32_t pd_offset = vaddr >> 22;
    uint32_t pt_offset = (vaddr << 10) >> 22;
    struct pte* pt_ptr = (struct pte*) PT_PHYSICAL_ADDRESS;

    struct pte new_entry;
    new_entry.address   = paddr >> 12;
    new_entry.readwrite = true;
    new_entry.present   = true;

    /* TODO: There should be some error handling here. */
    *(pt_ptr + pt_offset + (pd_offset << 10)) = new_entry;
}

void mm_init(void) {
    first_free = (uintptr_t*) MEMORY_START;
    end_of_memory = first_free + get_memsize();

    _init_page_directory();
    /*_enable_paging();*/
}
