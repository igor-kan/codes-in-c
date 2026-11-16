#include "interface.h"

static uint64_t splitmix64_next(uint64_t* s) {
    uint64_t z = (*s += 0x9e3779b97f4a7c15ULL);
    z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL;
    z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;
    return z ^ (z >> 31);
}

reservoir_sampling_vitter_err_t reservoir_init(reservoir_t* r, int64_t* backing, size_t k, uint64_t seed) {
    if (!r || !backing) return RESERVOIR_SAMPLING_VITTER_ERR_NULL;
    if (k == 0) return RESERVOIR_SAMPLING_VITTER_ERR_BOUNDS;
    r->items = backing;
    r->capacity = k;
    r->filled = 0;
    r->seen = 0;
    r->rng_state = seed ? seed : 0xCAFE12345678ULL;
    return RESERVOIR_SAMPLING_VITTER_OK;
}

void reservoir_observe(reservoir_t* r, int64_t value) {
    if (!r || !r->items || r->capacity == 0) return;
    r->seen++;
    if (r->filled < r->capacity) {
        r->items[r->filled++] = value;
    } else {
        uint64_t j = splitmix64_next(&r->rng_state) % r->seen;
        if (j < (uint64_t)r->capacity) r->items[j] = value;
    }
}
