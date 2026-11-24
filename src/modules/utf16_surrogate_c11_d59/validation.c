#include "interface.h"

utf16_surrogate_c11_d59_err_t utf16_surrogate_c11_d59_validate_len(size_t n) {
    if (n == 0) {
        return UTF16_SURROGATE_C11_D59_ERR_INVALID;
    }
    return UTF16_SURROGATE_C11_D59_OK;
}
