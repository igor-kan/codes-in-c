#include "interface.h"
#include <assert.h>

int main(void) {
    uint32_t x[256], y[256];
    uint32_t xor_x = 0, xor_y = 0;
    for (size_t i = 0; i < 256; ++i) {
        x[i] = (uint32_t)((i * 2654435761U) ^ 0xA5A5A5A5U);
        y[i] = (uint32_t)((256 - i) * 65537U);
        xor_x ^= x[i];
        xor_y ^= y[i];
    }
    msd_parallel_sort_halves(x, 256, y, 256);
    assert(msd_verify_sorted(x, 256) == RADIX_SORT_MSD_C11_OK);
    assert(msd_verify_sorted(y, 256) == RADIX_SORT_MSD_C11_OK);
    uint32_t px = 0, py = 0;
    for (size_t i = 0; i < 256; ++i) { px ^= x[i]; py ^= y[i]; }
    assert(px == xor_x && py == xor_y);
    return 0;
}
