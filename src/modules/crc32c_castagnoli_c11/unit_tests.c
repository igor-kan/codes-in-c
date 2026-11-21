#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(crc32c_castagnoli_c11_validate_len(1) == CRC32C_CASTAGNOLI_C11_OK);
    const uint8_t vec[9] = {'1','2','3','4','5','6','7','8','9'};
    assert(crc32c_compute(vec, 9) == 0xE3069283u);
    assert(crc32c_castagnoli_c11_verify_guard(true) == CRC32C_CASTAGNOLI_C11_OK);
    return 0;
}
