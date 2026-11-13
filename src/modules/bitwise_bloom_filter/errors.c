/**
 * @file errors.c
 * @brief Domain diagnostic error codes and messages for 64-Bit Aligned Bitwise Bloom Filter with Multi-Hash.
 * Module: bitwise_bloom_filter
 */

typedef enum bitwise_bloom_filter_error_status {
    BITWISE_BLOOM_FILTER_OK = 0,
    BITWISE_BLOOM_FILTER_ERR_INVALID_PARAM = -10,
    BITWISE_BLOOM_FILTER_ERR_CAPACITY_LIMIT = -11,
    BITWISE_BLOOM_FILTER_ERR_NUMERICAL_FAULT = -12
} bitwise_bloom_filter_error_status_t;

const char* bitwise_bloom_filter_error_string(bitwise_bloom_filter_error_status_t err) {
    switch (err) {
        case BITWISE_BLOOM_FILTER_OK: return "Operational success";
        case BITWISE_BLOOM_FILTER_ERR_INVALID_PARAM: return "Parameter domain precondition violated";
        case BITWISE_BLOOM_FILTER_ERR_CAPACITY_LIMIT: return "Buffer capacity boundary reached";
        case BITWISE_BLOOM_FILTER_ERR_NUMERICAL_FAULT: return "Numerical computation anomaly";
        default: return "Unknown module error code";
    }
}
