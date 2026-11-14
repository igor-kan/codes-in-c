/**
 * @file errors.c
 * @brief Domain diagnostic error codes and messages for Atomic CAS-Based Lock-Free Circular Queue Buffer.
 * Module: circular_queue_cas
 */

typedef enum circular_queue_cas_error_status {
    CIRCULAR_QUEUE_CAS_OK = 0,
    CIRCULAR_QUEUE_CAS_ERR_INVALID_PARAM = -10,
    CIRCULAR_QUEUE_CAS_ERR_CAPACITY_LIMIT = -11,
    CIRCULAR_QUEUE_CAS_ERR_NUMERICAL_FAULT = -12
} circular_queue_cas_error_status_t;

const char* circular_queue_cas_error_string(circular_queue_cas_error_status_t err) {
    switch (err) {
        case CIRCULAR_QUEUE_CAS_OK: return "Operational success";
        case CIRCULAR_QUEUE_CAS_ERR_INVALID_PARAM: return "Parameter domain precondition violated";
        case CIRCULAR_QUEUE_CAS_ERR_CAPACITY_LIMIT: return "Buffer capacity boundary reached";
        case CIRCULAR_QUEUE_CAS_ERR_NUMERICAL_FAULT: return "Numerical computation anomaly";
        default: return "Unknown module error code";
    }
}
