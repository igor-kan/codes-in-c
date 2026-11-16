#ifndef XOSHIRO256_PLUSPLUS_PRNG_TYPES_H
#define XOSHIRO256_PLUSPLUS_PRNG_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t s[4];
} xoshiro256pp_state_t;

#endif /* XOSHIRO256_PLUSPLUS_PRNG_TYPES_H */
