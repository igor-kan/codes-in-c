#ifndef BASE32_RFC4648_C11_D59_ERRORS_H
#define BASE32_RFC4648_C11_D59_ERRORS_H

typedef enum base32_rfc4648_c11_d59_err {
    BASE32_RFC4648_C11_D59_OK = 0,
    BASE32_RFC4648_C11_D59_ERR_NULL = -1,
    BASE32_RFC4648_C11_D59_ERR_BOUNDS = -2,
    BASE32_RFC4648_C11_D59_ERR_INVALID = -3,
    BASE32_RFC4648_C11_D59_ERR_OVERFLOW = -4,
    BASE32_RFC4648_C11_D59_ERR_INVARIANT = -5
} base32_rfc4648_c11_d59_err_t;



static inline const char* base32_rfc4648_c11_d59_err_str(base32_rfc4648_c11_d59_err_t err) {
    switch (err) {
        case BASE32_RFC4648_C11_D59_OK: return "ok";
        case BASE32_RFC4648_C11_D59_ERR_NULL: return "null pointer supplied";
        case BASE32_RFC4648_C11_D59_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case BASE32_RFC4648_C11_D59_ERR_INVALID: return "domain precondition violated";
        case BASE32_RFC4648_C11_D59_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case BASE32_RFC4648_C11_D59_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* BASE32_RFC4648_C11_D59_ERRORS_H */
