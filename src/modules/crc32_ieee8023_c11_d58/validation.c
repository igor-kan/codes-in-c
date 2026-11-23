#include "interface.h"

crc32_ieee8023_c11_d58_err_t crc32_ieee8023_c11_d58_validate_len(size_t n) {
    if (n == 0) {
        return CRC32_IEEE8023_C11_D58_ERR_INVALID;
    }
    return CRC32_IEEE8023_C11_D58_OK;
}
