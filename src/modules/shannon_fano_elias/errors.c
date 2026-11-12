/**
 * @file errors.c
 * @brief Domain diagnostic error codes and messages for Shannon-Fano-Elias Cumulative Distribution Codec.
 * Module: shannon_fano_elias
 */

typedef enum shannon_fano_elias_error {
    SHANNON_FANO_ELIAS_SUCCESS = 0,
    SHANNON_FANO_ELIAS_ERR_INVALID_INPUT = -1,
    SHANNON_FANO_ELIAS_ERR_BUFFER_OVERFLOW = -2,
    SHANNON_FANO_ELIAS_ERR_CONVERGENCE_FAIL = -3
} shannon_fano_elias_error_t;

const char* shannon_fano_elias_str_error(shannon_fano_elias_error_t code) {
    switch (code) {
        case SHANNON_FANO_ELIAS_SUCCESS: return "Operation completed successfully";
        case SHANNON_FANO_ELIAS_ERR_INVALID_INPUT: return "Input argument violates domain preconditions";
        case SHANNON_FANO_ELIAS_ERR_BUFFER_OVERFLOW: return "Output buffer capacity exceeded";
        case SHANNON_FANO_ELIAS_ERR_CONVERGENCE_FAIL: return "Numerical algorithm failed to converge within limit";
        default: return "Unrecognized error code";
    }
}
