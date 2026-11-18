#include "interface.h"

brent_pollard_factor_c11_err_t brent_pollard_factor_c11_verify_guard(bool cond) {
    if (!cond) {
        return BRENT_POLLARD_FACTOR_C11_ERR_INVARIANT;
    }
    return BRENT_POLLARD_FACTOR_C11_OK;
}
