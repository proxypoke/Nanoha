/* string.c - string handling functions
 *
 * This file is part of Nanoha.
 *
 * Nanoha is Free Software under the non-terms of
 * the Anti-License. Do whatever the fuck you want.
 */

#include <string.h>

size_t strlen(const char* str) {
    size_t ret = -1;
    while (str[ret++] != 0);
    return ret;
}

void* memcpy(void* dest, const void* src, size_t n) {
    uint8_t* to = (uint8_t*) dest;
    uint8_t* from = (uint8_t*) src;
    while (n > 0) {
        *to = *from;
        n--;
        to++;
        from++;
    }
    return dest;
}
