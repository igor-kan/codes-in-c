/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for Lock-Free Bounded MPMC Circular Queue.
 * Module: atomic_mpmc_queue
 */

#include <assert.h>
#include <math.h>

static inline void atomic_mpmc_queue_assert_contract(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
