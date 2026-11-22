#ifndef XXHASH32_AVALANCHE_D57_ERRORS_H
#define XXHASH32_AVALANCHE_D57_ERRORS_H

typedef enum xxhash32_avalanche_d57_err {
    XXHASH32_AVALANCHE_D57_OK = 0,
    XXHASH32_AVALANCHE_D57_ERR_NULL = -1,
    XXHASH32_AVALANCHE_D57_ERR_BOUNDS = -2,
    XXHASH32_AVALANCHE_D57_ERR_INVALID = -3,
    XXHASH32_AVALANCHE_D57_ERR_OVERFLOW = -4,
    XXHASH32_AVALANCHE_D57_ERR_INVARIANT = -5
} xxhash32_avalanche_d57_err_t;



static inline const char* xxhash32_avalanche_d57_err_str(xxhash32_avalanche_d57_err_t err) {
    switch (err) {
        case XXHASH32_AVALANCHE_D57_OK: return "ok";
        case XXHASH32_AVALANCHE_D57_ERR_NULL: return "null pointer supplied";
        case XXHASH32_AVALANCHE_D57_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case XXHASH32_AVALANCHE_D57_ERR_INVALID: return "domain precondition violated";
        case XXHASH32_AVALANCHE_D57_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case XXHASH32_AVALANCHE_D57_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* XXHASH32_AVALANCHE_D57_ERRORS_H */
