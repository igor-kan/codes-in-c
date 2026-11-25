#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(buddy_alloc_order_d60_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    buddy_pool_t bp; buddy_init_d60(&bp);
    int x = buddy_alloc_d60(&bp, 4);
    assert(x == 0 && buddy_alloc_d60(&bp, 0) == -1);
    buddy_free_d60(&bp, x, 4);
    assert(buddy_alloc_d60(&bp, 4) == 0);
    return 0;
}
