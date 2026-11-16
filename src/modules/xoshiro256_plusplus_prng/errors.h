#ifndef XOSHIRO256_PLUSPLUS_PRNG_ERRORS_H
#define XOSHIRO256_PLUSPLUS_PRNG_ERRORS_H

typedef enum xoshiro256_plusplus_prng_err {
    XOSHIRO256_PLUSPLUS_PRNG_OK = 0,
    XOSHIRO256_PLUSPLUS_PRNG_ERR_NULL = -1,
    XOSHIRO256_PLUSPLUS_PRNG_ERR_BOUNDS = -2,
    XOSHIRO256_PLUSPLUS_PRNG_ERR_INVALID = -3,
    XOSHIRO256_PLUSPLUS_PRNG_ERR_OVERFLOW = -4,
    XOSHIRO256_PLUSPLUS_PRNG_ERR_INVARIANT = -5
} xoshiro256_plusplus_prng_err_t;



static inline const char* xoshiro256_plusplus_prng_err_str(xoshiro256_plusplus_prng_err_t err) {
    switch (err) {
        case XOSHIRO256_PLUSPLUS_PRNG_OK: return "ok";
        case XOSHIRO256_PLUSPLUS_PRNG_ERR_NULL: return "null pointer supplied";
        case XOSHIRO256_PLUSPLUS_PRNG_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case XOSHIRO256_PLUSPLUS_PRNG_ERR_INVALID: return "domain precondition violated";
        case XOSHIRO256_PLUSPLUS_PRNG_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case XOSHIRO256_PLUSPLUS_PRNG_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* XOSHIRO256_PLUSPLUS_PRNG_ERRORS_H */
