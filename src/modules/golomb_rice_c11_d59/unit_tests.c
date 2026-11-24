#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(golomb_rice_c11_d59_validate_len(1) == GOLOMB_RICE_C11_D59_OK);
    const uint32_t src[4] = {0, 3, 7, 15};
    uint8_t bits[64]; uint32_t rec[4];
    size_t bl = gr_encode_bits(src, 4, 2, bits);
    assert(gr_decode_bits(bits, bl, 2, rec) == 4 && memcmp(src, rec, sizeof(src)) == 0);
    assert(golomb_rice_c11_d59_verify_guard(true) == GOLOMB_RICE_C11_D59_OK);
    return 0;
}
