#include "interface.h"

hermite_cubic_spline_c11_err_t hermite_cubic_spline_c11_validate_len(size_t n) {
    if (n == 0) {
        return HERMITE_CUBIC_SPLINE_C11_ERR_INVALID;
    }
    return HERMITE_CUBIC_SPLINE_C11_OK;
}
