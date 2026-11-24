#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(base32_rfc4648_c11_d59_validate_len(1) == BASE32_RFC4648_C11_D59_OK);
    const uint8_t raw[4] = {'f','o','o','b'};
    const uint8_t exp[8] = {'M','Z','X','W','6','Y','Q','='};
    uint8_t enc[8], dec[8]; size_t dl = 0;
    assert(b32_encode(raw, 4, enc) == 8 && memcmp(enc, exp, 8) == 0);
    assert(b32_decode(enc, 8, dec, &dl) == 0 && dl == 4 && memcmp(dec, raw, 4) == 0);
    assert(base32_rfc4648_c11_d59_verify_guard(true) == BASE32_RFC4648_C11_D59_OK);
    return 0;
}
