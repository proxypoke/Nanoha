/* mm.h - low level memory management
 *
 * This file is part of Nanoha.
 *
 * Nanoha is Free Software under the non-terms of
 * the Anti-License. Do whatever the fuck you want.
 */

#include <stddef.h>
#include <stdint.h>

/* We use 4MiB pages. */
#define PAGE_SIZE (4 * 1024 * 1024)
/* TODO: For now, use 256MiB as the memory size. Get the actual memory size from
 * the bootloader later. */
#define MEMORY_SIZE 268435456
/* For now, start at 2MiB */
#define MEMORY_START 0x200000

/* We put the Page Table at the 4MiB mark. */
#define PT_PHYSICAL_ADDRESS (4 * 1024 * 1024)
/* The Page Directory is located directly before the Page Table. */
#define PD_PHYSICAL_ADDRESS (PT_PHYSICAL_ADDRESS - 4096)
/* The last entry of the Page Directory shall always point to itself. */
#define PD_VIRTUAL_ADDRESS 0xFFFFF000

/* An entry for the Page Directory. */
struct pde {
    unsigned address        :20;                /* 4kib aligned address */
    unsigned free           :3;                 /* unused */
    unsigned ignored        :1;                 /* G - ignored */
    unsigned size           :1;                 /* S - page size */
    unsigned                :1;                 /* 0 - padding */
    unsigned accessed       :1;                 /* A - accessed */
    unsigned nocache        :1;                 /* D - cache disabled */
    unsigned writethrough   :1;                 /* W - writethrough */
    unsigned user           :1;                 /* U - user/supervisor */
    unsigned readwrite      :1;                 /* R - read/write */
    unsigned present        :1;                 /* P - present */
};

/* An entry for the Page table. */
struct pte {
    unsigned address        :20;                /* 4kib aligned address */
    unsigned free           :3;                 /* unused */
    unsigned global         :1;                 /* G - global */
    unsigned                :1;                 /* 0 - padding */
    unsigned dirty          :1;                 /* D - dirty */
    unsigned accessed       :1;                 /* A - accessed */
    unsigned nocache        :1;                 /* D - cache disabled */
    unsigned writethrough   :1;                 /* W - writethrough */
    unsigned user           :1;                 /* U - user/supervisor */
    unsigned readwrite      :1;                 /* R - read/write */
    unsigned present        :1;                 /* P - present */
};

/* Request allocation of n contiguous pages. Returns a pointer to the start of
 * the group. */
void* mm_alloc_pages(size_t n);

/* Free the given number of pages. */
void mm_free_pages(void* start, size_t n);

/* Initialize the low level memory manager */
void mm_init(void);
