/* stddef.h - useful types and macros
 *
 * This file is part of Nanoha.
 *
 * Nanoha is Free Software under the non-terms of
 * the Anti-License. Do whatever the fuck you want.
 */

#define NULL ((void *) 0)

#define offsetof(type, member) ((unsigned long) &(((type*) 0)->member))

typedef unsigned long size_t;
typedef unsigned long wchar_t;
typedef signed long ptrdiff_t;
