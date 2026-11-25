#include "interface.h"

crc32c_castagnoli_d60_err_t crc32c_castagnoli_d60_validate_len(size_t n) {
    if (n == 0) {
        return CRC32C_CASTAGNOLI_D60_ERR_INVALID;
    }
    return CRC32C_CASTAGNOLI_D60_OK;
}
