/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for Hazard Pointer Domain Manager for Lock-Free Memory.
 * Module: hazard_pointer_domain
 */

#include <assert.h>
#include <math.h>

static inline void hazard_pointer_domain_verify_contract(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
