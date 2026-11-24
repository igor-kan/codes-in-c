#include "interface.h"

golomb_rice_c11_d59_err_t golomb_rice_c11_d59_validate_len(size_t n) {
    if (n == 0) {
        return GOLOMB_RICE_C11_D59_ERR_INVALID;
    }
    return GOLOMB_RICE_C11_D59_OK;
}
