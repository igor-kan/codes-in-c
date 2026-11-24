#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(golomb_rice_c11_d59_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    const uint32_t v[3] = {5, 1, 9};
    uint8_t bits[64]; uint32_t rec[3];
    size_t bl = gr_encode_bits(v, 3, 3, bits);
    assert(gr_decode_bits(bits, bl, 3, rec) == 3 && rec[0] == 5 && rec[2] == 9);
    return 0;
}
