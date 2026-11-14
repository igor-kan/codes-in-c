/**
 * @file errors.c
 * @brief Domain diagnostic error codes and messages for SipHash-2-4 Round Mixing Function with Bitwise Rotations.
 * Module: siphash_round_c
 */

typedef enum siphash_round_c_error_status {
    SIPHASH_ROUND_C_OK = 0,
    SIPHASH_ROUND_C_ERR_INVALID_PARAM = -10,
    SIPHASH_ROUND_C_ERR_CAPACITY_LIMIT = -11,
    SIPHASH_ROUND_C_ERR_NUMERICAL_FAULT = -12
} siphash_round_c_error_status_t;

const char* siphash_round_c_error_string(siphash_round_c_error_status_t err) {
    switch (err) {
        case SIPHASH_ROUND_C_OK: return "Operational success";
        case SIPHASH_ROUND_C_ERR_INVALID_PARAM: return "Parameter domain precondition violated";
        case SIPHASH_ROUND_C_ERR_CAPACITY_LIMIT: return "Buffer capacity boundary reached";
        case SIPHASH_ROUND_C_ERR_NUMERICAL_FAULT: return "Numerical computation anomaly";
        default: return "Unknown module error code";
    }
}
