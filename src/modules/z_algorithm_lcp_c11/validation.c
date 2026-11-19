#include "interface.h"

z_algorithm_lcp_c11_err_t z_algorithm_lcp_c11_validate_len(size_t n) {
    if (n == 0) {
        return Z_ALGORITHM_LCP_C11_ERR_INVALID;
    }
    return Z_ALGORITHM_LCP_C11_OK;
}
