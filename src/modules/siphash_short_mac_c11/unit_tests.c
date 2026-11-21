#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(siphash_short_mac_c11_validate_len(1) == SIPHASH_SHORT_MAC_C11_OK);
    const uint8_t m[15] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    uint64_t h1 = siphash24(0x0706050403020100ULL, 0x0f0e0d0c0b0a0908ULL, m, 15);
    assert(h1 == 0xa129ca6149be45e5ULL);
    assert(siphash_short_mac_c11_verify_guard(true) == SIPHASH_SHORT_MAC_C11_OK);
    return 0;
}
