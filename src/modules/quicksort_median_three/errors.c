/**
 * @file errors.c
 * @brief Domain diagnostic error codes and messages for In-Place Quicksort with Median-of-Three Partitioning.
 * Module: quicksort_median_three
 */

typedef enum quicksort_median_three_error_status {
    QUICKSORT_MEDIAN_THREE_OK = 0,
    QUICKSORT_MEDIAN_THREE_ERR_INVALID_PARAM = -10,
    QUICKSORT_MEDIAN_THREE_ERR_CAPACITY_LIMIT = -11,
    QUICKSORT_MEDIAN_THREE_ERR_NUMERICAL_FAULT = -12
} quicksort_median_three_error_status_t;

const char* quicksort_median_three_error_string(quicksort_median_three_error_status_t err) {
    switch (err) {
        case QUICKSORT_MEDIAN_THREE_OK: return "Operational success";
        case QUICKSORT_MEDIAN_THREE_ERR_INVALID_PARAM: return "Parameter domain precondition violated";
        case QUICKSORT_MEDIAN_THREE_ERR_CAPACITY_LIMIT: return "Buffer capacity boundary reached";
        case QUICKSORT_MEDIAN_THREE_ERR_NUMERICAL_FAULT: return "Numerical computation anomaly";
        default: return "Unknown module error code";
    }
}
