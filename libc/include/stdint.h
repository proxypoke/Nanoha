/* stdint.h - integer types
 *
 * This file is part of Nanoha.
 *
 * Nanoha is Free Software under the non-terms of
 * the Anti-License. Do whatever the fuck you want.
 */

/* INT */

#define INTN_MIN(n) (-(2 ** (n - 1)))
#define INTN_MAX(n) ((2 ** (n - 1)) - 1)

#define INT_LEASTN_MIN(n) INTN_MIN(n)
#define INT_LEASTN_MAX(n) INTN_MAX(n)

#define INT_FASTN_MIN(n) INTN_MIN(n)
#define INT_FASTN_MAX(n) INTN_MAX(n)

typedef signed char int8_t;
#define INT8_MIN INTN_MIN(8)
#define INT8_MAX INTN_MAX(8)

typedef short int16_t;
#define INT16_MIN INTN_MIN(16)
#define INT16_MAX INTN_MAX(16)

typedef long int32_t;
#define INT32_MIN INTN_MIN(32)
#define INT32_MAX INTN_MAX(32)

typedef long long int64_t;
#define INT64_MIN INTN_MIN(64)
#define INT64_MAX INTN_MAX(64)

typedef long long intmax_t;
#define INTMAX_MIN INTN_MIN(64)
#define INTMAX_MAX INTN_MAX(64)

typedef long intptr_t;
#define INTPTR_MIN INTN_MIN(64)
#define INTPTR_MAX INTN_MAX(64)

typedef short int_least16_t;
#define INT_LEAST16_MIN INT_LEASTN_MIN(16)
#define INT_LEAST16_MAX INT_LEASTN_MAX(16)

typedef long int_least32_t;
#define INT_LEAST32_MIN INT_LEASTN_MIN(32)
#define INT_LEAST32_MAX INT_LEASTN_MAX(32)

typedef long long int_least64_t;
#define INT_LEAST64_MIN INT_LEASTN_MIN(64)
#define INT_LEAST64_MAX INT_LEASTN_MAX(64)

typedef char int_fast8_t;
#define INT_FAST8_MIN INT_FASTN_MIN(8)
#define INT_FAST8_MAX INT_FASTN_MAX(8)

typedef short int_fast16_t;
#define INT_FAST16_MIN INT_FASTN_MIN(16)
#define INT_FAST16_MAX INT_FASTN_MAX(16)

typedef long int_fast32_t;
#define INT_FAST32_MIN INT_FASTN_MIN(32)
#define INT_FAST32_MAX INT_FASTN_MAX(32)

typedef long long int_fast64_t;
#define INT_FAST64_MIN INT_FASTN_MIN(64)
#define INT_FAST64_MAX INT_FASTN_MAX(64)

/* UINT */

#define UINTN_MAX(n) ((2 ** n) - 1)

#define UINT_LEASTN(n) UINT_MAXN(n)

#define UINT_FASTN(n) UINT_MAXN(n)

typedef unsigned char uint8_t;
#define UINT8_MAX UINTN_MAX(8)

typedef unsigned short uint16_t;
#define UINT16_MAX UINTN_MAX(16)

typedef unsigned long uint32_t;
#define UINTN32_MAX UINTN_MAX(32)

typedef unsigned long long uint64_t;
#define UINT64_MAX UINTN_MAX(64)

typedef unsigned long long uintmax_t;
#define UINTMAX_MAX UINTN_MAX(64)

typedef unsigned long uintptr_t;
#define UINTPTR_MAX UINTN_MAX(64)

typedef unsigned short uint_least16_t;
#define UINT_LEAST16 UINT_LEASTN(16)

typedef unsigned long uint_least32_t;
#define UINT_LEAST32 UINT_LEASTN(32)

typedef unsigned long long uint_least64_t;
#define UINT_LEAST64 UINT_LEASTN(64)

typedef unsigned char uint_fast8_t;
#define UINT_FAST8 UINT_FASTN(8)

typedef unsigned short uint_fast16_t;
#define UINT_FAST16 UINT_FASTN(16)

typedef unsigned long uint_fast32_t;
#define UINT_FAST32 UINT_FASTN(32)

typedef unsigned long long uint_fast64_t;
#define UINT_FAST64 UINT_FASTN(64)

/* Limits for types from other headers.
 * Why POSIX defines these to be in this header will forever be a mystery. */

/* stddef.h */
/* We define these in terms of long. */
#define PTRDIFF_MIN INTN_MIN(32)
#define PTRDIFF_MAX INTN_MAX(32)

#define SIZE_MAX UINT_MAX(32)

#define WCHAR_MIN 0
#define WCHAR_MAX UINT_MAX(32)

/* signal.h */
/* TODO:
 * #define SIG_ATOMIC_MIN
 * #define SIG_ATOMIC_MAX
 */

/* wchar.h */
/* TODO:
 * #define WINT_MIN
 * #define WINT_MAX
 */
