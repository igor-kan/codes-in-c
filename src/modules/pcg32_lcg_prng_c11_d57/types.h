#ifndef PCG32_LCG_PRNG_C11_D57_TYPES_H
#define PCG32_LCG_PRNG_C11_D57_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t state;
    uint64_t inc;
} pcg32_rng_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} pcg32_lcg_prng_c11_d57_meta_t;

#endif /* PCG32_LCG_PRNG_C11_D57_TYPES_H */
