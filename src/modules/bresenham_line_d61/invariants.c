#include "interface.h"

bresenham_line_d61_err_t bresenham_line_d61_verify_guard(bool cond) {
    if (!cond) {
        return BRESENHAM_LINE_D61_ERR_INVARIANT;
    }
    return BRESENHAM_LINE_D61_OK;
}
