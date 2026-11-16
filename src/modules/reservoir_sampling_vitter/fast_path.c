#include "interface.h"

void reservoir_observe_batch(reservoir_t* r, const int64_t* values, size_t n) {
    if (!r || !values) return;
    for (size_t i = 0; i < n; ++i) reservoir_observe(r, values[i]);
}
