#include "interface.h"

fenwick_2d_grid_c11_err_t fenwick_2d_grid_c11_validate_len(size_t n) {
    if (n == 0) {
        return FENWICK_2D_GRID_C11_ERR_INVALID;
    }
    return FENWICK_2D_GRID_C11_OK;
}
