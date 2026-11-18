#include "interface.h"

brent_pollard_factor_c11_err_t brent_pollard_factor_c11_validate_len(size_t n) {
    if (n == 0) {
        return BRENT_POLLARD_FACTOR_C11_ERR_INVALID;
    }
    return BRENT_POLLARD_FACTOR_C11_OK;
}
