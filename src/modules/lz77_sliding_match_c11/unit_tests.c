#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(lz77_sliding_match_c11_validate_len(1) == LZ77_SLIDING_MATCH_C11_OK);
    const uint8_t src[12] = {'a','b','c','a','b','c','a','b','c','x','y','z'};
    lz77_token_t toks[12];
    uint8_t rec[16];
    size_t nt = lz77_compress(src, 12, 8, toks, 12);
    size_t rlen = lz77_decompress(toks, nt, rec);
    assert(nt < 12 && rlen == 12 && memcmp(src, rec, 12) == 0);
    assert(lz77_sliding_match_c11_verify_guard(true) == LZ77_SLIDING_MATCH_C11_OK);
    return 0;
}
