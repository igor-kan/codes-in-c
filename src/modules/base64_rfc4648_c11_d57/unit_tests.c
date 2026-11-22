#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(base64_rfc4648_c11_d57_validate_len(1) == BASE64_RFC4648_C11_D57_OK);
    const uint8_t raw[6] = {'f','o','o','b','a','r'};
    uint8_t enc[12], dec[12];
    size_t el = b64_encode(raw, 6, enc);
    const uint8_t exp[8] = {'Z','m','9','v','Y','m','F','y'};
    assert(el == 8 && memcmp(enc, exp, 8) == 0);
    size_t dl = 0;
    assert(b64_decode(enc, el, dec, &dl) == 0 && dl == 6 && memcmp(dec, raw, 6) == 0);
    assert(base64_rfc4648_c11_d57_verify_guard(true) == BASE64_RFC4648_C11_D57_OK);
    return 0;
}
