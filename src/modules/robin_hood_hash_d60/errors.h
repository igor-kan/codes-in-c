#ifndef ROBIN_HOOD_HASH_D60_ERRORS_H
#define ROBIN_HOOD_HASH_D60_ERRORS_H

typedef enum robin_hood_hash_d60_err {
    ROBIN_HOOD_HASH_D60_OK = 0,
    ROBIN_HOOD_HASH_D60_ERR_NULL = -1,
    ROBIN_HOOD_HASH_D60_ERR_BOUNDS = -2,
    ROBIN_HOOD_HASH_D60_ERR_INVALID = -3,
    ROBIN_HOOD_HASH_D60_ERR_OVERFLOW = -4,
    ROBIN_HOOD_HASH_D60_ERR_INVARIANT = -5
} robin_hood_hash_d60_err_t;



static inline const char* robin_hood_hash_d60_err_str(robin_hood_hash_d60_err_t err) {
    switch (err) {
        case ROBIN_HOOD_HASH_D60_OK: return "ok";
        case ROBIN_HOOD_HASH_D60_ERR_NULL: return "null pointer supplied";
        case ROBIN_HOOD_HASH_D60_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case ROBIN_HOOD_HASH_D60_ERR_INVALID: return "domain precondition violated";
        case ROBIN_HOOD_HASH_D60_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case ROBIN_HOOD_HASH_D60_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* ROBIN_HOOD_HASH_D60_ERRORS_H */
