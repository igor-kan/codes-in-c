/**
 * @file invariants.c
 * @brief Formal mathematical invariant assertions and contracts for FNV-1a 64-Bit Fast Non-Cryptographic Hash Engine.
 * Module: hash_fnv1a_64
 */

#include <assert.h>
#include <math.h>

static inline void hash_fnv1a_64_assert_invariants(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0 || fabs(out_val) < 1e-12);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
