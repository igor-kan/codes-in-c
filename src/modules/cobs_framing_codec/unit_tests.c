#include "interface.h"
#include <assert.h>
#include <string.h>

int main(void) {
    uint8_t p1[] = {0x11, 0x22, 0x00, 0x33};
    uint8_t enc[32], dec[32];
    size_t el = 0, dl = 0;
    assert(cobs_encode(p1, 4, enc, sizeof(enc), &el) == COBS_FRAMING_CODEC_OK);
    assert(el == 5 && enc[0] == 3 && enc[1] == 0x11 && enc[2] == 0x22 && enc[3] == 2 && enc[4] == 0x33);
    assert(cobs_decode(enc, el, dec, sizeof(dec), &dl) == COBS_FRAMING_CODEC_OK);
    assert(dl == 4 && memcmp(p1, dec, 4) == 0);
    assert(cobs_verify_invariants(p1, 4) == COBS_FRAMING_CODEC_OK);

    uint8_t bad[] = {0x05, 0x11};
    assert(cobs_decode(bad, 2, dec, sizeof(dec), &dl) == COBS_FRAMING_CODEC_ERR_INVALID);
    return 0;
}
