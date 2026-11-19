#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(fenwick_order_stat_c11_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    os_fenwick_t f; os_init(&f, 8); os_add(&f, 0, 1); os_add(&f, 7, 1); assert(os_kth(&f, 2) == 7);
    return 0;
}
