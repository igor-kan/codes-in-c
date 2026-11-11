/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for Harris Lock-Free Ordered Linked List with Marked Pointers.
 * Module: lockfree_ordered_list
 */

typedef enum lockfree_ordered_list_error_code {
    LOCKFREE_ORDERED_LIST_STATUS_OK = 0,
    LOCKFREE_ORDERED_LIST_ERR_NULL_PTR = -20,
    LOCKFREE_ORDERED_LIST_ERR_OUT_OF_BOUNDS = -21,
    LOCKFREE_ORDERED_LIST_ERR_DIVERGENCE = -22
} lockfree_ordered_list_error_code_t;

const char* lockfree_ordered_list_error_message(lockfree_ordered_list_error_code_t code) {
    switch (code) {
        case LOCKFREE_ORDERED_LIST_STATUS_OK: return "Operational success";
        case LOCKFREE_ORDERED_LIST_ERR_NULL_PTR: return "Null pointer argument";
        case LOCKFREE_ORDERED_LIST_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case LOCKFREE_ORDERED_LIST_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
