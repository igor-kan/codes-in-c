/**
 * @file errors.c
 * @brief Domain diagnostic error codes and messages for CORDIC Shift-and-Add Trigonometric Vector Rotation.
 * Module: fast_sin_cos_cordic
 */

typedef enum fast_sin_cos_cordic_error {
    FAST_SIN_COS_CORDIC_SUCCESS = 0,
    FAST_SIN_COS_CORDIC_ERR_INVALID_INPUT = -1,
    FAST_SIN_COS_CORDIC_ERR_BUFFER_OVERFLOW = -2,
    FAST_SIN_COS_CORDIC_ERR_CONVERGENCE_FAIL = -3
} fast_sin_cos_cordic_error_t;

const char* fast_sin_cos_cordic_str_error(fast_sin_cos_cordic_error_t code) {
    switch (code) {
        case FAST_SIN_COS_CORDIC_SUCCESS: return "Operation completed successfully";
        case FAST_SIN_COS_CORDIC_ERR_INVALID_INPUT: return "Input argument violates domain preconditions";
        case FAST_SIN_COS_CORDIC_ERR_BUFFER_OVERFLOW: return "Output buffer capacity exceeded";
        case FAST_SIN_COS_CORDIC_ERR_CONVERGENCE_FAIL: return "Numerical algorithm failed to converge within limit";
        default: return "Unrecognized error code";
    }
}
