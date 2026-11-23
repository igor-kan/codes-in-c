#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(varint_prefix_enc_c11_d58_validate_len(1) == VARINT_PREFIX_ENC_C11_D58_OK);
    uint8_t buf[16];
    uint64_t cases[4] = {0ULL, 239ULL, 1000ULL, 0x123456789ABCDEF0ULL};
    for (int i = 0; i < 4; ++i) {
        size_t n = pvar_encode(cases[i], buf);
        uint64_t got = 0; size_t u = 0;
        assert(pvar_decode(buf, n, &got, &u) == 0 && u == n && got == cases[i]);
    }
    assert(varint_prefix_enc_c11_d58_verify_guard(true) == VARINT_PREFIX_ENC_C11_D58_OK);
    return 0;
}
