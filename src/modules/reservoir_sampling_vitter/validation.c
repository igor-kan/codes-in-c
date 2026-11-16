#include "interface.h"

reservoir_sampling_vitter_err_t reservoir_validate(const reservoir_t* r) {
    if (!r || !r->items) return RESERVOIR_SAMPLING_VITTER_ERR_NULL;
    if (r->capacity == 0 || r->filled > r->capacity) return RESERVOIR_SAMPLING_VITTER_ERR_BOUNDS;
    return RESERVOIR_SAMPLING_VITTER_OK;
}
