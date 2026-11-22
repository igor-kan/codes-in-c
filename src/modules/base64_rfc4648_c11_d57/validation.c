#include "interface.h"

base64_rfc4648_c11_d57_err_t base64_rfc4648_c11_d57_validate_len(size_t n) {
    if (n == 0) {
        return BASE64_RFC4648_C11_D57_ERR_INVALID;
    }
    return BASE64_RFC4648_C11_D57_OK;
}
