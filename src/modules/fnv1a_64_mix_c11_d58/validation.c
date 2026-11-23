#include "interface.h"

fnv1a_64_mix_c11_d58_err_t fnv1a_64_mix_c11_d58_validate_len(size_t n) {
    if (n == 0) {
        return FNV1A_64_MIX_C11_D58_ERR_INVALID;
    }
    return FNV1A_64_MIX_C11_D58_OK;
}
