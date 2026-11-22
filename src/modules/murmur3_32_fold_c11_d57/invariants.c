#include "interface.h"

murmur3_32_fold_c11_d57_err_t murmur3_32_fold_c11_d57_verify_guard(bool cond) {
    if (!cond) {
        return MURMUR3_32_FOLD_C11_D57_ERR_INVARIANT;
    }
    return MURMUR3_32_FOLD_C11_D57_OK;
}
