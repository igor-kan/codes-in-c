#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(crc32_ieee8023_c11_d58_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    const uint8_t a[4] = {1,2,3,4}, b[4] = {1,2,3,5};
    assert(crc32_ieee_compute(a, 4) != crc32_ieee_compute(b, 4));
    return 0;
}
