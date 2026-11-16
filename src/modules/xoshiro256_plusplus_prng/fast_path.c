#include "interface.h"

void xoshiro_fill_batch(xoshiro256pp_state_t* st, uint64_t* dst, size_t count) {
    if (!st || !dst) return;
    size_t i = 0;
    for (; i + 4 <= count; i += 4) {
        dst[i]     = xoshiro_next(st);
        dst[i + 1] = xoshiro_next(st);
        dst[i + 2] = xoshiro_next(st);
        dst[i + 3] = xoshiro_next(st);
    }
    for (; i < count; ++i) dst[i] = xoshiro_next(st);
}
