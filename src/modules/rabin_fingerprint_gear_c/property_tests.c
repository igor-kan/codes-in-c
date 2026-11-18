#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(rabin_fingerprint_gear_c_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint8_t data[64];
    memset(data, 42, sizeof(data));
    cdc_chunk_t ch[8];
    size_t k = gear_cdc_split(data, 64, 8, 16, 0xffULL, ch, 8);
    assert(k == 4 && ch[0].length == 16);
    return 0;
}
