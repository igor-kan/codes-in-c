#include "interface.h"
#include <math.h>

uint64_t splitmix64_next(prng64_t* rng) {
    uint64_t z = (rng->state += 0x9e3779b97f4a7c15ULL);
    z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL;
    z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;
    return z ^ (z >> 31);
}

static double unit_open01(prng64_t* rng) {
    uint64_t r = splitmix64_next(rng) >> 11;
    double d = (double)(r + 1ULL) / 9007199254740993.0;
    return d;
}

knuth_shuffle_reservoir_err_t fisher_yates_shuffle(int64_t* arr, size_t n, uint64_t seed) {
    if (n > 0 && !arr) return KNUTH_SHUFFLE_RESERVOIR_ERR_NULL;
    prng64_t rng = {seed ? seed : 1ULL};
    fast_bounded_permute(arr, n, &rng);
    return KNUTH_SHUFFLE_RESERVOIR_OK;
}

knuth_shuffle_reservoir_err_t reservoir_sample_l(const int64_t* stream, size_t n, int64_t* sample, size_t k, uint64_t seed) {
    if (!stream || !sample) return KNUTH_SHUFFLE_RESERVOIR_ERR_NULL;
    knuth_shuffle_reservoir_err_t err = validate_sample_bounds(n, k);
    if (err != KNUTH_SHUFFLE_RESERVOIR_OK) return err;
    for (size_t i = 0; i < k; ++i) sample[i] = stream[i];
    prng64_t rng = {seed ? seed : 1ULL};
    double w = exp(log(unit_open01(&rng)) / (double)k);
    size_t i = k;
    while (i < n) {
        size_t jump = (size_t)floor(log(unit_open01(&rng)) / log(1.0 - w)) + 1;
        i += jump;
        if (i < n) {
            size_t slot = (size_t)(splitmix64_next(&rng) % k);
            sample[slot] = stream[i];
            w *= exp(log(unit_open01(&rng)) / (double)k);
        }
    }
    return KNUTH_SHUFFLE_RESERVOIR_OK;
}
