/* string.h - string handling functions
 *
 * This file is part of Nanoha.
 *
 * Nanoha is Free Software under the non-terms of
 * the Anti-License. Do whatever the fuck you want.
 */

#include <stddef.h>
#include <stdint.h>

/* Get the length of a string. */
size_t strlen(const char* str);

/* Copy n bytes from src to destination. src and dest must not overlap. */
void* memcpy(void* dest, const void* src, size_t n);
