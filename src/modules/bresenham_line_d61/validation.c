#include "interface.h"

bresenham_line_d61_err_t bresenham_line_d61_validate_len(size_t n) {
    if (n == 0) {
        return BRESENHAM_LINE_D61_ERR_INVALID;
    }
    return BRESENHAM_LINE_D61_OK;
}
