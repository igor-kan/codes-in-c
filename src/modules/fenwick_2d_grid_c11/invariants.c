#include "interface.h"

fenwick_2d_grid_c11_err_t fenwick_2d_grid_c11_verify_guard(bool cond) {
    if (!cond) {
        return FENWICK_2D_GRID_C11_ERR_INVARIANT;
    }
    return FENWICK_2D_GRID_C11_OK;
}
