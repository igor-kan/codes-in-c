#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(spsc_lockfree_ring_c11_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    spsc_ring16_t q;
    spsc16_init(&q);
    for (uint64_t r = 0; r < 50; ++r) {
        assert(spsc16_push(&q, r) == 0);
        uint64_t v = 999;
        assert(spsc16_pop(&q, &v) == 0 && v == r);
    }
    assert(spsc16_len(&q) == 0);
    return 0;
}
