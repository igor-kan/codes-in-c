#include "interface.h"

z_algorithm_lcp_c11_err_t z_algorithm_lcp_c11_verify_guard(bool cond) {
    if (!cond) {
        return Z_ALGORITHM_LCP_C11_ERR_INVARIANT;
    }
    return Z_ALGORITHM_LCP_C11_OK;
}
