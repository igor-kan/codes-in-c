#include "interface.h"

base32_rfc4648_c11_d59_err_t base32_rfc4648_c11_d59_validate_len(size_t n) {
    if (n == 0) {
        return BASE32_RFC4648_C11_D59_ERR_INVALID;
    }
    return BASE32_RFC4648_C11_D59_OK;
}
