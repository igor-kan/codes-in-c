/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for Thread-Cached Run Allocator with Slab Bitmap Binning.
 * Module: jemalloc_run_cache
 */

#include <assert.h>
#include <math.h>

static inline void jemalloc_run_cache_verify_contract_day47(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
