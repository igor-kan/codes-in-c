#include "interface.h"

crc32c_castagnoli_c11_err_t crc32c_castagnoli_c11_validate_len(size_t n) {
    if (n == 0) {
        return CRC32C_CASTAGNOLI_C11_ERR_INVALID;
    }
    return CRC32C_CASTAGNOLI_C11_OK;
}
