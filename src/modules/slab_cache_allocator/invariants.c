/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for Kernel-Style Slab Cache Memory Pool Allocator.
 * Module: slab_cache_allocator
 */

#include <assert.h>
#include <math.h>

static inline void slab_cache_allocator_assert_contract(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
