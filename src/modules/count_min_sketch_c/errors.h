#ifndef COUNT_MIN_SKETCH_C_ERRORS_H
#define COUNT_MIN_SKETCH_C_ERRORS_H

typedef enum count_min_sketch_c_err {
    COUNT_MIN_SKETCH_C_OK = 0,
    COUNT_MIN_SKETCH_C_ERR_NULL = -1,
    COUNT_MIN_SKETCH_C_ERR_BOUNDS = -2,
    COUNT_MIN_SKETCH_C_ERR_INVALID = -3,
    COUNT_MIN_SKETCH_C_ERR_OVERFLOW = -4,
    COUNT_MIN_SKETCH_C_ERR_INVARIANT = -5
} count_min_sketch_c_err_t;



static inline const char* count_min_sketch_c_err_str(count_min_sketch_c_err_t err) {
    switch (err) {
        case COUNT_MIN_SKETCH_C_OK: return "ok";
        case COUNT_MIN_SKETCH_C_ERR_NULL: return "null pointer supplied";
        case COUNT_MIN_SKETCH_C_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case COUNT_MIN_SKETCH_C_ERR_INVALID: return "domain precondition violated";
        case COUNT_MIN_SKETCH_C_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case COUNT_MIN_SKETCH_C_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* COUNT_MIN_SKETCH_C_ERRORS_H */
