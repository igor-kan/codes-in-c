#include "interface.h"
#include <assert.h>

int main(void) {
    int64_t buf[5];
    reservoir_t r;
    assert(reservoir_init(&r, buf, 5, 123ULL) == RESERVOIR_SAMPLING_VITTER_OK);
    for (int64_t i = 0; i < 100; ++i) reservoir_observe(&r, i);
    assert(r.filled == 5 && r.seen == 100);
    assert(reservoir_verify_invariants(&r, 0, 99) == RESERVOIR_SAMPLING_VITTER_OK);
    return 0;
}
