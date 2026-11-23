#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(crc32_ieee8023_c11_d58_validate_len(1) == CRC32_IEEE8023_C11_D58_OK);
    const uint8_t vec[9] = {'1','2','3','4','5','6','7','8','9'};
    assert(crc32_ieee_compute(vec, 9) == 0xCBF43926u);
    assert(crc32_ieee8023_c11_d58_verify_guard(true) == CRC32_IEEE8023_C11_D58_OK);
    return 0;
}
