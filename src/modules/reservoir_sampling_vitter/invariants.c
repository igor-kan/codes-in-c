#include "interface.h"

reservoir_sampling_vitter_err_t reservoir_verify_invariants(const reservoir_t* r, int64_t min_val, int64_t max_val) {
    if (reservoir_validate(r) != RESERVOIR_SAMPLING_VITTER_OK) return RESERVOIR_SAMPLING_VITTER_ERR_INVARIANT;
    for (size_t i = 0; i < r->filled; ++i) {
        if (r->items[i] < min_val || r->items[i] > max_val) return RESERVOIR_SAMPLING_VITTER_ERR_INVARIANT;
    }
    return RESERVOIR_SAMPLING_VITTER_OK;
}
