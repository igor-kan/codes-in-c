/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for Circular Work-Stealing Deque with Memory Fencing.
 * Module: circular_work_stealing_deque
 */

#include <assert.h>
#include <math.h>

static inline void circular_work_stealing_deque_verify_contract_day47(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
