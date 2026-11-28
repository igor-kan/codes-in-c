#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(base58_btc_d61_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint8_t data[16];
    for (size_t i = 0; i < 16; ++i) data[i] = (uint8_t)(i * 37 + 11);
    base58_string_t enc;
    size_t nenc = base58_encode(data, 16, &enc);
    assert(nenc == enc.length && nenc > 0);
    uint8_t back[32];
    size_t ndec = base58_decode(enc.text, enc.length, back, 32);
    assert(ndec == 16 && memcmp(data, back, 16) == 0);
    uint8_t lead[4] = {0, 7, 0, 9};
    assert(base58_encode(lead, 4, &enc) > 0);
    assert(base58_decode(enc.text, enc.length, back, 32) == 4 && memcmp(lead, back, 4) == 0);
    return 0;
}
