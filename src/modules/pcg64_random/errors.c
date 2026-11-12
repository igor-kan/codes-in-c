/**
 * @file errors.c
 * @brief Domain diagnostic error codes and messages for PCG-XSH-RR 64-Bit Statistical Random Number Generator.
 * Module: pcg64_random
 */

typedef enum pcg64_random_error {
    PCG64_RANDOM_SUCCESS = 0,
    PCG64_RANDOM_ERR_INVALID_INPUT = -1,
    PCG64_RANDOM_ERR_BUFFER_OVERFLOW = -2,
    PCG64_RANDOM_ERR_CONVERGENCE_FAIL = -3
} pcg64_random_error_t;

const char* pcg64_random_str_error(pcg64_random_error_t code) {
    switch (code) {
        case PCG64_RANDOM_SUCCESS: return "Operation completed successfully";
        case PCG64_RANDOM_ERR_INVALID_INPUT: return "Input argument violates domain preconditions";
        case PCG64_RANDOM_ERR_BUFFER_OVERFLOW: return "Output buffer capacity exceeded";
        case PCG64_RANDOM_ERR_CONVERGENCE_FAIL: return "Numerical algorithm failed to converge within limit";
        default: return "Unrecognized error code";
    }
}
