#include "interface.h"

crc32c_castagnoli_c11_err_t crc32c_castagnoli_c11_verify_guard(bool cond) {
    if (!cond) {
        return CRC32C_CASTAGNOLI_C11_ERR_INVARIANT;
    }
    return CRC32C_CASTAGNOLI_C11_OK;
}
