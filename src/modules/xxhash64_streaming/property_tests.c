#include "interface.h"
#include <assert.h>
#include <stdint.h>

int main(void) {
    uint8_t buf[512];
    for (size_t i = 0; i < sizeof(buf); ++i) buf[i] = (uint8_t)((i * 73 + 17) & 0xFF);
    for (size_t l = 0; l <= 260; l += 13) {
        assert(xxhash64_streaming_check_invariants(buf, l, l * 31337ULL) == XXHASH64_STREAMING_OK);
    }
    // Single-bit flip sensitivity
    uint64_t h0 = xxhash64_streaming_oneshot(buf, 128, 1);
    buf[64] ^= 0x01;
    uint64_t h1 = xxhash64_streaming_oneshot(buf, 128, 1);
    assert(h0 != h1);
    return 0;
}
