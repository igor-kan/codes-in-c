#include "interface.h"

murmur3_32_fold_c11_d57_err_t murmur3_32_fold_c11_d57_validate_len(size_t n) {
    if (n == 0) {
        return MURMUR3_32_FOLD_C11_D57_ERR_INVALID;
    }
    return MURMUR3_32_FOLD_C11_D57_OK;
}
