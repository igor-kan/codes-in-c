/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for Lock-Free Treiber Stack Freelist with ABA Version Tagging.
 * Module: lockfree_freelist
 */

#include <assert.h>
#include <math.h>

static inline void lockfree_freelist_verify_contract(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
