#include "interface.h"
#include <assert.h>
#include <stdint.h>
#include <string.h>

int main(void) {
    uint8_t buf[256];
    uint8_t out[256];
    lz77_token_t toks[260];
    uint32_t rng = 0x13579BDFU;
    for (int trial = 0; trial < 20; ++trial) {
        size_t len = (size_t)(trial * 11 + 1) % 200;
        for (size_t i = 0; i < len; ++i) {
            rng = rng * 1664525U + 1013904223U;
            buf[i] = (uint8_t)('A' + ((rng >> 24) % 4U));
        }
        assert(lz77_sliding_codec_verify_roundtrip(buf, len, 128) == LZ77_SLIDING_CODEC_OK);
        size_t cnt = 0, dec_len = 0;
        assert(lz77_sliding_codec_encode_fast(buf, len, toks, 260, &cnt) == LZ77_SLIDING_CODEC_OK);
        assert(lz77_sliding_codec_decode(toks, cnt, out, 256, &dec_len) == LZ77_SLIDING_CODEC_OK);
        assert(dec_len == len && (len == 0 || memcmp(buf, out, len) == 0));
    }
    return 0;
}
