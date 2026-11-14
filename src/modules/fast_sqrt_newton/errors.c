/**
 * @file errors.c
 * @brief Domain diagnostic error codes and messages for Fixed-Point Newton-Raphson Square Root Iteration.
 * Module: fast_sqrt_newton
 */

typedef enum fast_sqrt_newton_error_status {
    FAST_SQRT_NEWTON_OK = 0,
    FAST_SQRT_NEWTON_ERR_INVALID_PARAM = -10,
    FAST_SQRT_NEWTON_ERR_CAPACITY_LIMIT = -11,
    FAST_SQRT_NEWTON_ERR_NUMERICAL_FAULT = -12
} fast_sqrt_newton_error_status_t;

const char* fast_sqrt_newton_error_string(fast_sqrt_newton_error_status_t err) {
    switch (err) {
        case FAST_SQRT_NEWTON_OK: return "Operational success";
        case FAST_SQRT_NEWTON_ERR_INVALID_PARAM: return "Parameter domain precondition violated";
        case FAST_SQRT_NEWTON_ERR_CAPACITY_LIMIT: return "Buffer capacity boundary reached";
        case FAST_SQRT_NEWTON_ERR_NUMERICAL_FAULT: return "Numerical computation anomaly";
        default: return "Unknown module error code";
    }
}
