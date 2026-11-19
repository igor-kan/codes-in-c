#include "interface.h"

uint64_t fenwick_order_stat_c11_fast_fold_u64(const uint64_t* xs, size_t n) {
    uint64_t acc = 1469598103934665603ULL;
    for (size_t i = 0; i < n; ++i) {
        acc = (acc ^ xs[i]) * 1099511628211ULL;
    }
    return acc;
}
