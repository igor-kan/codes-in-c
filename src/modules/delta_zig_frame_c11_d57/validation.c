#include "interface.h"

delta_zig_frame_c11_d57_err_t delta_zig_frame_c11_d57_validate_len(size_t n) {
    if (n == 0) {
        return DELTA_ZIG_FRAME_C11_D57_ERR_INVALID;
    }
    return DELTA_ZIG_FRAME_C11_D57_OK;
}
