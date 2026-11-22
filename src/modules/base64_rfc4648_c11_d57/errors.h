#ifndef BASE64_RFC4648_C11_D57_ERRORS_H
#define BASE64_RFC4648_C11_D57_ERRORS_H

typedef enum base64_rfc4648_c11_d57_err {
    BASE64_RFC4648_C11_D57_OK = 0,
    BASE64_RFC4648_C11_D57_ERR_NULL = -1,
    BASE64_RFC4648_C11_D57_ERR_BOUNDS = -2,
    BASE64_RFC4648_C11_D57_ERR_INVALID = -3,
    BASE64_RFC4648_C11_D57_ERR_OVERFLOW = -4,
    BASE64_RFC4648_C11_D57_ERR_INVARIANT = -5
} base64_rfc4648_c11_d57_err_t;



static inline const char* base64_rfc4648_c11_d57_err_str(base64_rfc4648_c11_d57_err_t err) {
    switch (err) {
        case BASE64_RFC4648_C11_D57_OK: return "ok";
        case BASE64_RFC4648_C11_D57_ERR_NULL: return "null pointer supplied";
        case BASE64_RFC4648_C11_D57_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case BASE64_RFC4648_C11_D57_ERR_INVALID: return "domain precondition violated";
        case BASE64_RFC4648_C11_D57_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case BASE64_RFC4648_C11_D57_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* BASE64_RFC4648_C11_D57_ERRORS_H */
