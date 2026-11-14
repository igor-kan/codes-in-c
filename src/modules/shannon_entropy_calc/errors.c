/**
 * @file errors.c
 * @brief Domain diagnostic error codes and messages for Empirical Shannon Entropy Calculator with Log2 Scale.
 * Module: shannon_entropy_calc
 */

typedef enum shannon_entropy_calc_error_status {
    SHANNON_ENTROPY_CALC_OK = 0,
    SHANNON_ENTROPY_CALC_ERR_INVALID_PARAM = -10,
    SHANNON_ENTROPY_CALC_ERR_CAPACITY_LIMIT = -11,
    SHANNON_ENTROPY_CALC_ERR_NUMERICAL_FAULT = -12
} shannon_entropy_calc_error_status_t;

const char* shannon_entropy_calc_error_string(shannon_entropy_calc_error_status_t err) {
    switch (err) {
        case SHANNON_ENTROPY_CALC_OK: return "Operational success";
        case SHANNON_ENTROPY_CALC_ERR_INVALID_PARAM: return "Parameter domain precondition violated";
        case SHANNON_ENTROPY_CALC_ERR_CAPACITY_LIMIT: return "Buffer capacity boundary reached";
        case SHANNON_ENTROPY_CALC_ERR_NUMERICAL_FAULT: return "Numerical computation anomaly";
        default: return "Unknown module error code";
    }
}
