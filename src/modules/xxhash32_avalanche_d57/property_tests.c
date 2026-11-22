#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(xxhash32_avalanche_d57_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    const uint8_t b1[4] = {1,2,3,4};
    const uint8_t b2[4] = {1,2,3,5};
    assert(xxhash32_compute(b1, 4, 7u) != xxhash32_compute(b2, 4, 7u));
    return 0;
}
