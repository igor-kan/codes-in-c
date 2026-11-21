#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(crc32c_castagnoli_c11_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint8_t bufA[5] = {10, 20, 30, 40, 50};
    uint8_t bufB[5] = {10, 20, 31, 40, 50};
    assert(crc32c_compute(bufA, 5) != crc32c_compute(bufB, 5));
    return 0;
}
