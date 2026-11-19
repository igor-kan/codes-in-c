#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(z_algorithm_lcp_c11_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    size_t z[16] = {0}; build_z_array("aabcaab", 7, z);
    assert(z[4] == 3);
    return 0;
}
