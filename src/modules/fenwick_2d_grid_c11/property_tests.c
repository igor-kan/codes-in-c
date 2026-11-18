#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(fenwick_2d_grid_c11_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    fenwick2d_t fw; fw2d_init(&fw, 6, 6);
    for (int i = 0; i < 6; ++i) fw2d_add(&fw, i, i, 3);
    assert(fw2d_rect_sum(&fw, 2, 2, 4, 4) == 9);
    return 0;
}
