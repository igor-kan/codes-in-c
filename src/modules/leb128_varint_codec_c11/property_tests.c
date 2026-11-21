#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(leb128_varint_codec_c11_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    int64_t samples[4] = {-100000, -1, 0, 99999};
    uint8_t buf[10];
    for (int i = 0; i < 4; ++i) {
        size_t n = uleb128_encode(zigzag_encode64(samples[i]), buf);
        uint64_t u = 0;
        size_t used = 0;
        assert(uleb128_decode(buf, n, &u, &used) == 0);
        assert(zigzag_decode64(u) == samples[i]);
    }
    return 0;
}
