#include "interface.h"
#include <assert.h>

int main(void) {
    uint8_t bufs[4][400];
    const uint8_t* ptrs[4];
    size_t lens[4] = {200, 350, 400, 129};
    for (int t = 0; t < 4; ++t) {
        for (size_t i = 0; i < lens[t]; ++i) bufs[t][i] = (t == 0) ? (uint8_t)i : (uint8_t)(i / 17U);
        ptrs[t] = bufs[t];
        assert(packbits_verify_roundtrip(bufs[t], lens[t]) == RLE_PACKBITS_CODEC_OK);
    }
    assert(packbits_batch_mt(ptrs, lens, 4, 2) == RLE_PACKBITS_CODEC_OK);
    return 0;
}
