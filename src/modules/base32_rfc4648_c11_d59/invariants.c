#include "interface.h"

base32_rfc4648_c11_d59_err_t base32_rfc4648_c11_d59_verify_guard(bool cond) {
    if (!cond) {
        return BASE32_RFC4648_C11_D59_ERR_INVARIANT;
    }
    return BASE32_RFC4648_C11_D59_OK;
}
