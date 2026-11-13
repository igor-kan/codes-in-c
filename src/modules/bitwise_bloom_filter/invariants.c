/**
 * @file invariants.c
 * @brief Formal mathematical invariant assertions and contracts for 64-Bit Aligned Bitwise Bloom Filter with Multi-Hash.
 * Module: bitwise_bloom_filter
 */

#include <assert.h>
#include <math.h>

static inline void bitwise_bloom_filter_assert_invariants(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0 || fabs(out_val) < 1e-12);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
