/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for Power-of-Two Buddy Memory Pool Allocator.
 * Module: buddy_memory_allocator
 */

#include <assert.h>
#include <math.h>

static inline void buddy_memory_allocator_verify_invariant(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
