#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(binomial_heap_meld_c11_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    binom_heap_t h; bh_init(&h);
    for (int i = 15; i >= 1; --i) bh_push(&h, i * 2);
    assert(bh_pop_min(&h) == 2 && h.count == 14);
    return 0;
}
