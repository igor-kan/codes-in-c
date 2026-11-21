#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(lz77_sliding_match_c11_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    const uint8_t src[6] = {'a','a','a','a','a','b'};
    lz77_token_t toks[6];
    uint8_t rec[8];
    size_t nt = lz77_compress(src, 6, 4, toks, 6);
    assert(lz77_decompress(toks, nt, rec) == 6 && memcmp(src, rec, 6) == 0);
    return 0;
}
