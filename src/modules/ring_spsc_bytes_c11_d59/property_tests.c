#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(ring_spsc_bytes_c11_d59_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    byte_ring64_t r; br64_init(&r);
    const uint8_t big[4] = {9,8,7,6};
    for (int i = 0; i < 16; ++i) assert(br64_write(&r, big, 4) == 0);
    assert(br64_write(&r, big, 1) == -1);
    return 0;
}
