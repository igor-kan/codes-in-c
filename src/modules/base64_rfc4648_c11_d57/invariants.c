#include "interface.h"

base64_rfc4648_c11_d57_err_t base64_rfc4648_c11_d57_verify_guard(bool cond) {
    if (!cond) {
        return BASE64_RFC4648_C11_D57_ERR_INVARIANT;
    }
    return BASE64_RFC4648_C11_D57_OK;
}
