#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(crc32c_castagnoli_d60_validate_len(1) == CRC32C_CASTAGNOLI_D60_OK);
    const uint8_t vec[9] = {'1','2','3','4','5','6','7','8','9'};
    assert(crc32c_update_d60(0U, vec, 9) == 0xe3069283U);
    assert(crc32c_castagnoli_d60_verify_guard(true) == CRC32C_CASTAGNOLI_D60_OK);
    return 0;
}
