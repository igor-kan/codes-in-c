#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(lzss_flag_codec_c11_d58_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    const uint8_t run[8] = {'z','z','z','z','z','z','z','z'};
    lzss_op_t ops[8]; uint8_t out[8];
    size_t n = lzss_compress(run, 8, ops);
    assert(lzss_decompress(ops, n, out) == 8 && memcmp(run, out, 8) == 0);
    return 0;
}
