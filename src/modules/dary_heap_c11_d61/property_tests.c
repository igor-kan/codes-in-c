#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(dary_heap_c11_d61_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    dary_heap_t h; dary_heap_init(&h);
    for (int i = 0; i < 100; ++i) assert(dary_heap_push(&h, (int64_t)((i * 37 + 11) % 101)));
    int64_t prev = -1;
    int produced = 0;
    int64_t out = 0;
    while (dary_heap_pop(&h, &out)) {
        assert(out >= prev);
        prev = out;
        ++produced;
    }
    assert(produced == 100 && h.size == 0);
    return 0;
}
