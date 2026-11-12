/**
 * @file errors.c
 * @brief Domain diagnostic error codes and messages for Knuth-Morris-Pratt (KMP) Longest Prefix Search.
 * Module: knuth_morris_pratt
 */

typedef enum knuth_morris_pratt_error {
    KNUTH_MORRIS_PRATT_SUCCESS = 0,
    KNUTH_MORRIS_PRATT_ERR_INVALID_INPUT = -1,
    KNUTH_MORRIS_PRATT_ERR_BUFFER_OVERFLOW = -2,
    KNUTH_MORRIS_PRATT_ERR_CONVERGENCE_FAIL = -3
} knuth_morris_pratt_error_t;

const char* knuth_morris_pratt_str_error(knuth_morris_pratt_error_t code) {
    switch (code) {
        case KNUTH_MORRIS_PRATT_SUCCESS: return "Operation completed successfully";
        case KNUTH_MORRIS_PRATT_ERR_INVALID_INPUT: return "Input argument violates domain preconditions";
        case KNUTH_MORRIS_PRATT_ERR_BUFFER_OVERFLOW: return "Output buffer capacity exceeded";
        case KNUTH_MORRIS_PRATT_ERR_CONVERGENCE_FAIL: return "Numerical algorithm failed to converge within limit";
        default: return "Unrecognized error code";
    }
}
