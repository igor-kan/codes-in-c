#include "interface.h"
#include <math.h>
#include <string.h>

static uint64_t splitmix64_next(uint64_t *state) {
    uint64_t z = (*state += 0x9E3779B97F4A7C15ULL);
    z = (z ^ (z >> 30)) * 0xBF58476D1CE4E5B9ULL;
    z = (z ^ (z >> 27)) * 0x94D049BB133111EBULL;
    return z ^ (z >> 31);
}

size_t reservoir_sample_u64(size_t n_stream, size_t k, uint64_t seed, size_t *out) {
    if (k == 0 || n_stream == 0) return 0;
    size_t fill = n_stream < k ? n_stream : k;
    for (size_t i = 0; i < fill; ++i) out[i] = i;
    uint64_t st = seed;
    for (size_t i = fill; i < n_stream; ++i) {
        uint64_t j = splitmix64_next(&st) % (uint64_t)(i + 1);
        if (j < (uint64_t)k) out[j] = i;
    }
    return fill;
}
