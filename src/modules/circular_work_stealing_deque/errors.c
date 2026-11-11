/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for Circular Work-Stealing Deque with Memory Fencing.
 * Module: circular_work_stealing_deque
 */

typedef enum circular_work_stealing_deque_error_code {
    CIRCULAR_WORK_STEALING_DEQUE_STATUS_OK = 0,
    CIRCULAR_WORK_STEALING_DEQUE_ERR_NULL_PTR = -20,
    CIRCULAR_WORK_STEALING_DEQUE_ERR_OUT_OF_BOUNDS = -21,
    CIRCULAR_WORK_STEALING_DEQUE_ERR_DIVERGENCE = -22
} circular_work_stealing_deque_error_code_t;

const char* circular_work_stealing_deque_error_message(circular_work_stealing_deque_error_code_t code) {
    switch (code) {
        case CIRCULAR_WORK_STEALING_DEQUE_STATUS_OK: return "Operational success";
        case CIRCULAR_WORK_STEALING_DEQUE_ERR_NULL_PTR: return "Null pointer argument";
        case CIRCULAR_WORK_STEALING_DEQUE_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case CIRCULAR_WORK_STEALING_DEQUE_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
