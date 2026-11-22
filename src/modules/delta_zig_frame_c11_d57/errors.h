#ifndef DELTA_ZIG_FRAME_C11_D57_ERRORS_H
#define DELTA_ZIG_FRAME_C11_D57_ERRORS_H

typedef enum delta_zig_frame_c11_d57_err {
    DELTA_ZIG_FRAME_C11_D57_OK = 0,
    DELTA_ZIG_FRAME_C11_D57_ERR_NULL = -1,
    DELTA_ZIG_FRAME_C11_D57_ERR_BOUNDS = -2,
    DELTA_ZIG_FRAME_C11_D57_ERR_INVALID = -3,
    DELTA_ZIG_FRAME_C11_D57_ERR_OVERFLOW = -4,
    DELTA_ZIG_FRAME_C11_D57_ERR_INVARIANT = -5
} delta_zig_frame_c11_d57_err_t;



static inline const char* delta_zig_frame_c11_d57_err_str(delta_zig_frame_c11_d57_err_t err) {
    switch (err) {
        case DELTA_ZIG_FRAME_C11_D57_OK: return "ok";
        case DELTA_ZIG_FRAME_C11_D57_ERR_NULL: return "null pointer supplied";
        case DELTA_ZIG_FRAME_C11_D57_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case DELTA_ZIG_FRAME_C11_D57_ERR_INVALID: return "domain precondition violated";
        case DELTA_ZIG_FRAME_C11_D57_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case DELTA_ZIG_FRAME_C11_D57_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* DELTA_ZIG_FRAME_C11_D57_ERRORS_H */
