/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for 64-Bit Word Compact Bitset with Popcount.
 * Module: compact_bitset
 */

#include <assert.h>
#include <math.h>

static inline void compact_bitset_verify_invariant(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
