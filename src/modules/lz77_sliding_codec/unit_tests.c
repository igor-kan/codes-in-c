#include "interface.h"
#include <assert.h>
#include <string.h>

int main(void) {
    const char* s = "abracadabraabracadabraabracadabra";
    size_t n = strlen(s);
    lz77_token_t toks[64];
    uint8_t out[64];
    size_t cnt = 0, out_len = 0;
    assert(lz77_sliding_codec_encode((const uint8_t*)s, n, toks, 64, &cnt, 256) == LZ77_SLIDING_CODEC_OK);
    assert(cnt < n); // Must compress repetitive text
    assert(lz77_sliding_codec_decode(toks, cnt, out, 64, &out_len) == LZ77_SLIDING_CODEC_OK);
    assert(out_len == n && memcmp(s, out, n) == 0);

    // Self-overlapping RLE case: "aaaaaaaaaa"
    const uint8_t rle[10] = {'a','a','a','a','a','a','a','a','a','a'};
    assert(lz77_sliding_codec_verify_roundtrip(rle, 10, 64) == LZ77_SLIDING_CODEC_OK);
    return 0;
}
