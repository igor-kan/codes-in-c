#include "interface.h"

delta_zig_frame_c11_d57_err_t delta_zig_frame_c11_d57_verify_guard(bool cond) {
    if (!cond) {
        return DELTA_ZIG_FRAME_C11_D57_ERR_INVARIANT;
    }
    return DELTA_ZIG_FRAME_C11_D57_OK;
}
