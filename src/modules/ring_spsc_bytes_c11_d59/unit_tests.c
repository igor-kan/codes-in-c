#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(ring_spsc_bytes_c11_d59_validate_len(1) == RING_SPSC_BYTES_C11_D59_OK);
    byte_ring64_t r; br64_init(&r);
    const uint8_t w1[40] = {1,2,3,4};
    uint8_t out[40];
    assert(br64_write(&r, w1, 40) == 0 && br64_read(&r, out, 30) == 30);
    assert(br64_write(&r, w1, 40) == 0 && br64_read(&r, out, 10) == 10);
    assert(ring_spsc_bytes_c11_d59_verify_guard(true) == RING_SPSC_BYTES_C11_D59_OK);
    return 0;
}
