#ifndef PCG32_LCG_PRNG_C11_D57_ERRORS_H
#define PCG32_LCG_PRNG_C11_D57_ERRORS_H

typedef enum pcg32_lcg_prng_c11_d57_err {
    PCG32_LCG_PRNG_C11_D57_OK = 0,
    PCG32_LCG_PRNG_C11_D57_ERR_NULL = -1,
    PCG32_LCG_PRNG_C11_D57_ERR_BOUNDS = -2,
    PCG32_LCG_PRNG_C11_D57_ERR_INVALID = -3,
    PCG32_LCG_PRNG_C11_D57_ERR_OVERFLOW = -4,
    PCG32_LCG_PRNG_C11_D57_ERR_INVARIANT = -5
} pcg32_lcg_prng_c11_d57_err_t;



static inline const char* pcg32_lcg_prng_c11_d57_err_str(pcg32_lcg_prng_c11_d57_err_t err) {
    switch (err) {
        case PCG32_LCG_PRNG_C11_D57_OK: return "ok";
        case PCG32_LCG_PRNG_C11_D57_ERR_NULL: return "null pointer supplied";
        case PCG32_LCG_PRNG_C11_D57_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case PCG32_LCG_PRNG_C11_D57_ERR_INVALID: return "domain precondition violated";
        case PCG32_LCG_PRNG_C11_D57_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case PCG32_LCG_PRNG_C11_D57_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* PCG32_LCG_PRNG_C11_D57_ERRORS_H */
