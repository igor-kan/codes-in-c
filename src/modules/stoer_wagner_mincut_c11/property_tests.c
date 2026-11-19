#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(stoer_wagner_mincut_c11_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    int64_t g[16][16] = {0}; g[0][1]=g[1][0]=5; g[1][2]=g[2][1]=2; assert(sw_mincut_c(3, g) == 2);
    return 0;
}
