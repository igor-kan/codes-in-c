#ifndef INTROSORT_HEAP_GUARD_ERRORS_H
#define INTROSORT_HEAP_GUARD_ERRORS_H

typedef enum introsort_heap_guard_err {
    INTROSORT_HEAP_GUARD_OK = 0,
    INTROSORT_HEAP_GUARD_ERR_NULL = -1,
    INTROSORT_HEAP_GUARD_ERR_BOUNDS = -2,
    INTROSORT_HEAP_GUARD_ERR_INVALID = -3,
    INTROSORT_HEAP_GUARD_ERR_OVERFLOW = -4,
    INTROSORT_HEAP_GUARD_ERR_INVARIANT = -5
} introsort_heap_guard_err_t;



static inline const char* introsort_heap_guard_err_str(introsort_heap_guard_err_t err) {
    switch (err) {
        case INTROSORT_HEAP_GUARD_OK: return "ok";
        case INTROSORT_HEAP_GUARD_ERR_NULL: return "null pointer supplied";
        case INTROSORT_HEAP_GUARD_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case INTROSORT_HEAP_GUARD_ERR_INVALID: return "domain precondition violated";
        case INTROSORT_HEAP_GUARD_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case INTROSORT_HEAP_GUARD_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* INTROSORT_HEAP_GUARD_ERRORS_H */
