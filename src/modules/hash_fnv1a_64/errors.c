/**
 * @file errors.c
 * @brief Domain diagnostic error codes and messages for FNV-1a 64-Bit Fast Non-Cryptographic Hash Engine.
 * Module: hash_fnv1a_64
 */

typedef enum hash_fnv1a_64_error_status {
    HASH_FNV1A_64_OK = 0,
    HASH_FNV1A_64_ERR_INVALID_PARAM = -10,
    HASH_FNV1A_64_ERR_CAPACITY_LIMIT = -11,
    HASH_FNV1A_64_ERR_NUMERICAL_FAULT = -12
} hash_fnv1a_64_error_status_t;

const char* hash_fnv1a_64_error_string(hash_fnv1a_64_error_status_t err) {
    switch (err) {
        case HASH_FNV1A_64_OK: return "Operational success";
        case HASH_FNV1A_64_ERR_INVALID_PARAM: return "Parameter domain precondition violated";
        case HASH_FNV1A_64_ERR_CAPACITY_LIMIT: return "Buffer capacity boundary reached";
        case HASH_FNV1A_64_ERR_NUMERICAL_FAULT: return "Numerical computation anomaly";
        default: return "Unknown module error code";
    }
}
