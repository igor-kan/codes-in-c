#include "interface.h"

utf16_surrogate_c11_d59_err_t utf16_surrogate_c11_d59_verify_guard(bool cond) {
    if (!cond) {
        return UTF16_SURROGATE_C11_D59_ERR_INVARIANT;
    }
    return UTF16_SURROGATE_C11_D59_OK;
}
