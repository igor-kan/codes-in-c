#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(cobs_framing_codec_c11_validate_len(1) == COBS_FRAMING_CODEC_C11_OK);
    const uint8_t raw[6] = {0x11, 0x00, 0x22, 0x33, 0x00, 0x44};
    uint8_t enc[16];
    uint8_t dec[16];
    size_t elen = cobs_encode(raw, 6, enc);
    for (size_t i = 0; i < elen; ++i) assert(enc[i] != 0);
    size_t dlen = 0;
    assert(cobs_decode(enc, elen, dec, &dlen) == 0 && dlen == 6);
    assert(memcmp(raw, dec, 6) == 0);
    assert(cobs_framing_codec_c11_verify_guard(true) == COBS_FRAMING_CODEC_C11_OK);
    return 0;
}
