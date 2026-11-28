#include "interface.h"

segmented_sieve_c11_d61_err_t segmented_sieve_c11_d61_validate_len(size_t n) {
    if (n == 0) {
        return SEGMENTED_SIEVE_C11_D61_ERR_INVALID;
    }
    return SEGMENTED_SIEVE_C11_D61_OK;
}
