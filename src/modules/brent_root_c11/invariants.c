#include "interface.h"
#include <math.h>

brent_root_c11_err_t verify_root_residual(const brent_result_t* res, double tol) {
    if (!res) return BRENT_ROOT_C11_ERR_NULL;
    if (!res->converged || fabs(res->residual) > tol * 10.0) return BRENT_ROOT_C11_ERR_INVARIANT;
    return BRENT_ROOT_C11_OK;
}
