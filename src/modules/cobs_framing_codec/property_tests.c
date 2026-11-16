#include "interface.h"
#include <assert.h>
#include <stdint.h>

int main(void) {
    uint8_t buf[600];
    uint8_t e1[620], e2[620];
    const uint8_t* ptrs[6];
    size_t lens[6];
    uint8_t items[6][300];
    uint64_t rng = 0x9988776655443322ULL;
    for (int t = 0; t < 6; ++t) {
        size_t len = (t == 0) ? 255 : (size_t)(40 + t * 50);
        for (size_t i = 0; i < len; ++i) {
            rng = rng * 6364136223846793005ULL + 1ULL;
            items[t][i] = (t == 0) ? (uint8_t)((i % 253) + 1) : (uint8_t)((i % 5 == 0) ? 0 : (rng >> 32));
        }
        ptrs[t] = items[t];
        lens[t] = len;
        assert(cobs_verify_invariants(items[t], len) == COBS_FRAMING_CODEC_OK);
    }
    assert(cobs_batch_roundtrip_mt(ptrs, lens, 6, 3) == COBS_FRAMING_CODEC_OK);
    for (size_t i = 0; i < 600; ++i) buf[i] = (uint8_t)(i & 0xFF);
    size_t l1 = 0, l2 = 0;
    assert(cobs_encode(buf, 300, e1, sizeof(e1), &l1) == COBS_FRAMING_CODEC_OK);
    assert(cobs_encode_fast(buf, 300, e2, &l2) == COBS_FRAMING_CODEC_OK);
    assert(l1 == l2);
    return 0;
}
