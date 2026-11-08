/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for Lock-Free Bounded MPMC Circular Queue.
 * Module: atomic_mpmc_queue
 */

typedef enum atomic_mpmc_queue_error {
    ATOMIC_MPMC_QUEUE_OK = 0,
    ATOMIC_MPMC_QUEUE_ERR_NULL = -100,
    ATOMIC_MPMC_QUEUE_ERR_CAPACITY = -101,
    ATOMIC_MPMC_QUEUE_ERR_CONVERGENCE = -102
} atomic_mpmc_queue_error_t;

const char* atomic_mpmc_queue_strerror(atomic_mpmc_queue_error_t err) {
    switch (err) {
        case ATOMIC_MPMC_QUEUE_OK: return "Success";
        case ATOMIC_MPMC_QUEUE_ERR_NULL: return "Encountered null pointer argument";
        case ATOMIC_MPMC_QUEUE_ERR_CAPACITY: return "Capacity limit exceeded";
        case ATOMIC_MPMC_QUEUE_ERR_CONVERGENCE: return "Numerical algorithm failed to converge";
        default: return "Unknown error";
    }
}
