#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(lz77_window_match_d60_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint8_t src[24], dst[24];
    for (size_t i = 0; i < 24; ++i) src[i] = (uint8_t)('A' + (i % 4));
    lz77_tok_t toks[32];
    size_t nt = lz77_encode_d60(src, 24, toks, 32);
    size_t nd = lz77_decode_d60(toks, nt, dst, 24);
    assert(nt < 24 && nd == 24 && memcmp(src, dst, 24) == 0);
    return 0;
}
