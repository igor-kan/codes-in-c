#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(zkw_bottom_up_segtree_c_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    zkw_tree_t z; zkw_init(&z); zkw_set(&z, 0, 7); zkw_set(&z, 3, 5); assert(zkw_sum(&z, 0, 3) == 12);
    return 0;
}
