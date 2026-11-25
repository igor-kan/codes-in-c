#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(crc32c_castagnoli_d60_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    const uint8_t msg[6] = {10, 20, 30, 40, 50, 60};
    uint32_t whole = crc32c_update_d60(0U, msg, 6);
    uint32_t p1 = crc32c_update_d60(0U, msg, 3);
    uint32_t p2 = crc32c_update_d60(p1, msg + 3, 3);
    assert(whole == p2);
    return 0;
}
