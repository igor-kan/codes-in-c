#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(ring_spsc_lockfree_d60_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    spsc_ring_t q; spsc_init_d60(&q);
    for (int i = 0; i < 200; ++i) {
        assert(spsc_push_d60(&q, (int64_t)i));
        int64_t x = -1;
        assert(spsc_pop_d60(&q, &x) && x == i);
    }
    assert(spsc_size_d60(&q) == 0);
    return 0;
}
