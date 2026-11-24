#ifndef UTF16_SURROGATE_C11_D59_ERRORS_H
#define UTF16_SURROGATE_C11_D59_ERRORS_H

typedef enum utf16_surrogate_c11_d59_err {
    UTF16_SURROGATE_C11_D59_OK = 0,
    UTF16_SURROGATE_C11_D59_ERR_NULL = -1,
    UTF16_SURROGATE_C11_D59_ERR_BOUNDS = -2,
    UTF16_SURROGATE_C11_D59_ERR_INVALID = -3,
    UTF16_SURROGATE_C11_D59_ERR_OVERFLOW = -4,
    UTF16_SURROGATE_C11_D59_ERR_INVARIANT = -5
} utf16_surrogate_c11_d59_err_t;



static inline const char* utf16_surrogate_c11_d59_err_str(utf16_surrogate_c11_d59_err_t err) {
    switch (err) {
        case UTF16_SURROGATE_C11_D59_OK: return "ok";
        case UTF16_SURROGATE_C11_D59_ERR_NULL: return "null pointer supplied";
        case UTF16_SURROGATE_C11_D59_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case UTF16_SURROGATE_C11_D59_ERR_INVALID: return "domain precondition violated";
        case UTF16_SURROGATE_C11_D59_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case UTF16_SURROGATE_C11_D59_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* UTF16_SURROGATE_C11_D59_ERRORS_H */
