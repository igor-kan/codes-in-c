/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for Harris Lock-Free Ordered Linked List with Marked Pointers.
 * Module: lockfree_ordered_list
 */

#include <assert.h>
#include <math.h>

static inline void lockfree_ordered_list_verify_contract_day47(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
