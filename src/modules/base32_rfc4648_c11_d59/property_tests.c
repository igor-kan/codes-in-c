#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(base32_rfc4648_c11_d59_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    const uint8_t s[5] = {'h','e','l','l','o'};
    uint8_t enc[8], dec[8]; size_t dl = 0;
    assert(b32_encode(s, 5, enc) == 8 && b32_decode(enc, 8, dec, &dl) == 0 && memcmp(s, dec, 5) == 0);
    return 0;
}
