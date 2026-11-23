#include "interface.h"

fnv1a_64_mix_c11_d58_err_t fnv1a_64_mix_c11_d58_verify_guard(bool cond) {
    if (!cond) {
        return FNV1A_64_MIX_C11_D58_ERR_INVARIANT;
    }
    return FNV1A_64_MIX_C11_D58_OK;
}
