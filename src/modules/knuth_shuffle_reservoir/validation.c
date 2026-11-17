#include "interface.h"

knuth_shuffle_reservoir_err_t validate_sample_bounds(size_t n, size_t k) {
    if (k == 0 || k > n) return KNUTH_SHUFFLE_RESERVOIR_ERR_BOUNDS;
    return KNUTH_SHUFFLE_RESERVOIR_OK;
}
