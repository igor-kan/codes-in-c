#ifndef MURMUR3_32_FOLD_C11_D57_ERRORS_H
#define MURMUR3_32_FOLD_C11_D57_ERRORS_H

typedef enum murmur3_32_fold_c11_d57_err {
    MURMUR3_32_FOLD_C11_D57_OK = 0,
    MURMUR3_32_FOLD_C11_D57_ERR_NULL = -1,
    MURMUR3_32_FOLD_C11_D57_ERR_BOUNDS = -2,
    MURMUR3_32_FOLD_C11_D57_ERR_INVALID = -3,
    MURMUR3_32_FOLD_C11_D57_ERR_OVERFLOW = -4,
    MURMUR3_32_FOLD_C11_D57_ERR_INVARIANT = -5
} murmur3_32_fold_c11_d57_err_t;



static inline const char* murmur3_32_fold_c11_d57_err_str(murmur3_32_fold_c11_d57_err_t err) {
    switch (err) {
        case MURMUR3_32_FOLD_C11_D57_OK: return "ok";
        case MURMUR3_32_FOLD_C11_D57_ERR_NULL: return "null pointer supplied";
        case MURMUR3_32_FOLD_C11_D57_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case MURMUR3_32_FOLD_C11_D57_ERR_INVALID: return "domain precondition violated";
        case MURMUR3_32_FOLD_C11_D57_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case MURMUR3_32_FOLD_C11_D57_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* MURMUR3_32_FOLD_C11_D57_ERRORS_H */
