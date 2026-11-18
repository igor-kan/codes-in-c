#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(disjoint_sparse_table_c_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    int64_t a[8] = {10, 20, 30, 40, 50, 60, 70, 80};
    dst_sum_t dst; dst_build(&dst, a, 8);
    assert(dst_query(&dst, 2, 6) == 250);
    return 0;
}
