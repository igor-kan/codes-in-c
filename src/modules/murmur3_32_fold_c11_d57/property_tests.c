#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(murmur3_32_fold_c11_d57_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    const uint8_t a[5] = {9, 8, 7, 6, 5};
    const uint8_t b[5] = {9, 8, 7, 6, 4};
    assert(murmur3_32(a, 5, 1u) != murmur3_32(b, 5, 1u));
    return 0;
}
