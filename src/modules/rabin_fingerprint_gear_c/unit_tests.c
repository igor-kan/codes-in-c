#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(rabin_fingerprint_gear_c_validate_len(1) == RABIN_FINGERPRINT_GEAR_C_OK);
    uint8_t data[120];
    for (size_t i = 0; i < 120; ++i) data[i] = (uint8_t)((i * 37U + 13U) & 0xffU);
    cdc_chunk_t ch[32];
    size_t k = gear_cdc_split(data, 120, 8, 32, 0x7ULL, ch, 32);
    size_t total = 0;
    for (size_t i = 0; i < k; ++i) total += ch[i].length;
    assert(k >= 4 && total == 120);
    assert(rabin_fingerprint_gear_c_verify_guard(true) == RABIN_FINGERPRINT_GEAR_C_OK);
    return 0;
}
