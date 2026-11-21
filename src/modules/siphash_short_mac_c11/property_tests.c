#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(siphash_short_mac_c11_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    const uint8_t m1[4] = {1, 2, 3, 4};
    const uint8_t m2[4] = {1, 2, 3, 5};
    assert(siphash24(1, 2, m1, 4) != siphash24(1, 2, m2, 4));
    assert(siphash24(1, 2, m1, 4) != siphash24(1, 3, m1, 4));
    return 0;
}
