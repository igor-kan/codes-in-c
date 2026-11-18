#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(consistent_hash_ring_c11_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    hash_ring_t ring; hring_init(&ring);
    hring_add_node(&ring, 1, 8);
    assert(hring_locate(&ring, 999ULL) == 1);
    return 0;
}
