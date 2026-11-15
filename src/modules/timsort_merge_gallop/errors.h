#ifndef TIMSORT_MERGE_GALLOP_ERRORS_H
#define TIMSORT_MERGE_GALLOP_ERRORS_H

typedef enum timsort_merge_gallop_err {
    TIMSORT_MERGE_GALLOP_OK = 0,
    TIMSORT_MERGE_GALLOP_ERR_NULL = -1,
    TIMSORT_MERGE_GALLOP_ERR_BOUNDS = -2,
    TIMSORT_MERGE_GALLOP_ERR_INVALID = -3,
    TIMSORT_MERGE_GALLOP_ERR_OVERFLOW = -4,
    TIMSORT_MERGE_GALLOP_ERR_INVARIANT = -5
} timsort_merge_gallop_err_t;



static inline const char* timsort_merge_gallop_err_str(timsort_merge_gallop_err_t err) {
    switch (err) {
        case TIMSORT_MERGE_GALLOP_OK: return "ok";
        case TIMSORT_MERGE_GALLOP_ERR_NULL: return "null pointer supplied";
        case TIMSORT_MERGE_GALLOP_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case TIMSORT_MERGE_GALLOP_ERR_INVALID: return "domain precondition violated";
        case TIMSORT_MERGE_GALLOP_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case TIMSORT_MERGE_GALLOP_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* TIMSORT_MERGE_GALLOP_ERRORS_H */
