/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for Cacheline-Aligned Fixed-Size Block Pool with Bitmask.
 * Module: memory_pool_fixed
 */

#include <assert.h>
#include <math.h>

static inline void memory_pool_fixed_verify_contract_day47(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
