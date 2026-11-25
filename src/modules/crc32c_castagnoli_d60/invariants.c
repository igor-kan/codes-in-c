#include "interface.h"

crc32c_castagnoli_d60_err_t crc32c_castagnoli_d60_verify_guard(bool cond) {
    if (!cond) {
        return CRC32C_CASTAGNOLI_D60_ERR_INVARIANT;
    }
    return CRC32C_CASTAGNOLI_D60_OK;
}
