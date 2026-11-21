#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(cobs_framing_codec_c11_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    const uint8_t zeros[4] = {0, 0, 0, 0};
    uint8_t enc[12];
    uint8_t dec[12];
    size_t elen = cobs_encode(zeros, 4, enc);
    size_t dlen = 0;
    assert(cobs_decode(enc, elen, dec, &dlen) == 0 && dlen == 4 && memcmp(zeros, dec, 4) == 0);
    return 0;
}
