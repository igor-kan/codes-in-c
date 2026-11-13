/**
 * @file errors.c
 * @brief Domain diagnostic error codes and messages for Fast Inverse Square Root with Bitwise IEEE-754 Hack.
 * Module: fast_inv_sqrt_quake
 */

typedef enum fast_inv_sqrt_quake_error_status {
    FAST_INV_SQRT_QUAKE_OK = 0,
    FAST_INV_SQRT_QUAKE_ERR_INVALID_PARAM = -10,
    FAST_INV_SQRT_QUAKE_ERR_CAPACITY_LIMIT = -11,
    FAST_INV_SQRT_QUAKE_ERR_NUMERICAL_FAULT = -12
} fast_inv_sqrt_quake_error_status_t;

const char* fast_inv_sqrt_quake_error_string(fast_inv_sqrt_quake_error_status_t err) {
    switch (err) {
        case FAST_INV_SQRT_QUAKE_OK: return "Operational success";
        case FAST_INV_SQRT_QUAKE_ERR_INVALID_PARAM: return "Parameter domain precondition violated";
        case FAST_INV_SQRT_QUAKE_ERR_CAPACITY_LIMIT: return "Buffer capacity boundary reached";
        case FAST_INV_SQRT_QUAKE_ERR_NUMERICAL_FAULT: return "Numerical computation anomaly";
        default: return "Unknown module error code";
    }
}
