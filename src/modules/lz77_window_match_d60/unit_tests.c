#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(lz77_window_match_d60_validate_len(1) == LZ77_WINDOW_MATCH_D60_OK);
    const uint8_t raw[12] = {'a','b','a','b','a','b','c','a','b','a','b','d'};
    lz77_tok_t toks[16];
    uint8_t dec[16];
    size_t nt = lz77_encode_d60(raw, 12, toks, 16);
    size_t nd = lz77_decode_d60(toks, nt, dec, 16);
    assert(nd == 12 && memcmp(raw, dec, 12) == 0);
    assert(lz77_window_match_d60_verify_guard(true) == LZ77_WINDOW_MATCH_D60_OK);
    return 0;
}
