#include "interface.h"
#include <assert.h>
#include <string.h>

int main(void) {
    const uint8_t sample[] = {0xAA,0xAA,0xAA,0x80,0x00,0x2A,0xAA,0xAA,0xAA,0xAA,0x80,0x00,0x2A,0x22,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA};
    uint8_t enc[64], dec[64];
    size_t el = 0, dl = 0;
    assert(packbits_encode(sample, sizeof(sample), enc, sizeof(enc), &el) == RLE_PACKBITS_CODEC_OK);
    assert(el < sizeof(sample));
    assert(packbits_decode(enc, el, dec, sizeof(dec), &dl) == RLE_PACKBITS_CODEC_OK);
    assert(dl == sizeof(sample) && memcmp(sample, dec, sizeof(sample)) == 0);
    assert(packbits_verify_roundtrip(sample, sizeof(sample)) == RLE_PACKBITS_CODEC_OK);
    return 0;
}
