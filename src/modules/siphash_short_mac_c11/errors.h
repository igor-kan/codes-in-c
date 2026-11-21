#ifndef SIPHASH_SHORT_MAC_C11_ERRORS_H
#define SIPHASH_SHORT_MAC_C11_ERRORS_H

typedef enum siphash_short_mac_c11_err {
    SIPHASH_SHORT_MAC_C11_OK = 0,
    SIPHASH_SHORT_MAC_C11_ERR_NULL = -1,
    SIPHASH_SHORT_MAC_C11_ERR_BOUNDS = -2,
    SIPHASH_SHORT_MAC_C11_ERR_INVALID = -3,
    SIPHASH_SHORT_MAC_C11_ERR_OVERFLOW = -4,
    SIPHASH_SHORT_MAC_C11_ERR_INVARIANT = -5
} siphash_short_mac_c11_err_t;



static inline const char* siphash_short_mac_c11_err_str(siphash_short_mac_c11_err_t err) {
    switch (err) {
        case SIPHASH_SHORT_MAC_C11_OK: return "ok";
        case SIPHASH_SHORT_MAC_C11_ERR_NULL: return "null pointer supplied";
        case SIPHASH_SHORT_MAC_C11_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case SIPHASH_SHORT_MAC_C11_ERR_INVALID: return "domain precondition violated";
        case SIPHASH_SHORT_MAC_C11_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case SIPHASH_SHORT_MAC_C11_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* SIPHASH_SHORT_MAC_C11_ERRORS_H */
