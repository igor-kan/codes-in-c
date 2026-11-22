#include "interface.h"
#include <math.h>
#include <string.h>

uint32_t pcg32_next(pcg32_rng_t *rng) {
    uint64_t oldstate = rng->state;
    rng->state = oldstate * 6364136223846793005ULL + rng->inc;
    uint32_t xorshifted = (uint32_t)(((oldstate >> 18u) ^ oldstate) >> 27u);
    uint32_t rot = (uint32_t)(oldstate >> 59u);
    return (xorshifted >> rot) | (xorshifted << ((-rot) & 31u));
}

void pcg32_seed(pcg32_rng_t *rng, uint64_t initstate, uint64_t initseq) {
    rng->state = 0ULL;
    rng->inc = (initseq << 1u) | 1ULL;
    (void)pcg32_next(rng);
    rng->state += initstate;
    (void)pcg32_next(rng);
}

uint32_t pcg32_bounded(pcg32_rng_t *rng, uint32_t bound) {
    uint32_t threshold = (-bound) % bound;
    for (;;) {
        uint32_t r = pcg32_next(rng);
        if (r >= threshold) return r % bound;
    }
}
