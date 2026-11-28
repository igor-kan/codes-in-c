#ifndef SEGMENTED_SIEVE_C11_D61_TYPES_H
#define SEGMENTED_SIEVE_C11_D61_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define SIEVE_MAX_PRIMES 256
typedef struct {
    uint64_t primes[SIEVE_MAX_PRIMES];
    size_t count;
} sieve_result_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} segmented_sieve_c11_d61_meta_t;

#endif /* SEGMENTED_SIEVE_C11_D61_TYPES_H */
