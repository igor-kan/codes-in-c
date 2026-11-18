#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(patience_lis_reconstruct_c_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    int64_t a[6] = {1, 3, 2, 4, 3, 5};
    lis_result_t r;
    assert(patience_lis(a, 6, &r) == 4);
    return 0;
}
