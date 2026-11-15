#include "interface.h"
#include <assert.h>

int main(void) {
    uint8_t buf[128];
    uint32_t rng = 0xCAFEBABEU;
    for (int t = 1; t <= 15; ++t) {
        size_t len = (size_t)t * 7;
        for (size_t i = 0; i < len; ++i) {
            rng = rng * 1664525U + 1013904223U;
            buf[i] = (uint8_t)('a' + ((rng >> 20) % 5U));
        }
        assert(burrows_wheeler_bwt_verify_bijection(buf, len) == BURROWS_WHEELER_BWT_OK);
    }
    return 0;
}
