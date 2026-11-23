#include "interface.h"

crc32_ieee8023_c11_d58_err_t crc32_ieee8023_c11_d58_verify_guard(bool cond) {
    if (!cond) {
        return CRC32_IEEE8023_C11_D58_ERR_INVARIANT;
    }
    return CRC32_IEEE8023_C11_D58_OK;
}
