#ifndef RABIN_FINGERPRINT_GEAR_C_ERRORS_H
#define RABIN_FINGERPRINT_GEAR_C_ERRORS_H

typedef enum rabin_fingerprint_gear_c_err {
    RABIN_FINGERPRINT_GEAR_C_OK = 0,
    RABIN_FINGERPRINT_GEAR_C_ERR_NULL = -1,
    RABIN_FINGERPRINT_GEAR_C_ERR_BOUNDS = -2,
    RABIN_FINGERPRINT_GEAR_C_ERR_INVALID = -3,
    RABIN_FINGERPRINT_GEAR_C_ERR_OVERFLOW = -4,
    RABIN_FINGERPRINT_GEAR_C_ERR_INVARIANT = -5
} rabin_fingerprint_gear_c_err_t;



static inline const char* rabin_fingerprint_gear_c_err_str(rabin_fingerprint_gear_c_err_t err) {
    switch (err) {
        case RABIN_FINGERPRINT_GEAR_C_OK: return "ok";
        case RABIN_FINGERPRINT_GEAR_C_ERR_NULL: return "null pointer supplied";
        case RABIN_FINGERPRINT_GEAR_C_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case RABIN_FINGERPRINT_GEAR_C_ERR_INVALID: return "domain precondition violated";
        case RABIN_FINGERPRINT_GEAR_C_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case RABIN_FINGERPRINT_GEAR_C_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* RABIN_FINGERPRINT_GEAR_C_ERRORS_H */
