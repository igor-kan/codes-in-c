#include "interface.h"

segmented_sieve_c11_d61_err_t segmented_sieve_c11_d61_verify_guard(bool cond) {
    if (!cond) {
        return SEGMENTED_SIEVE_C11_D61_ERR_INVARIANT;
    }
    return SEGMENTED_SIEVE_C11_D61_OK;
}
