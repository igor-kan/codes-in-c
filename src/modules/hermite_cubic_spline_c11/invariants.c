#include "interface.h"

hermite_cubic_spline_c11_err_t hermite_cubic_spline_c11_verify_guard(bool cond) {
    if (!cond) {
        return HERMITE_CUBIC_SPLINE_C11_ERR_INVARIANT;
    }
    return HERMITE_CUBIC_SPLINE_C11_OK;
}
