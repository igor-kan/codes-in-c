#ifndef KNUTH_SHUFFLE_RESERVOIR_ERRORS_H
#define KNUTH_SHUFFLE_RESERVOIR_ERRORS_H

typedef enum knuth_shuffle_reservoir_err {
    KNUTH_SHUFFLE_RESERVOIR_OK = 0,
    KNUTH_SHUFFLE_RESERVOIR_ERR_NULL = -1,
    KNUTH_SHUFFLE_RESERVOIR_ERR_BOUNDS = -2,
    KNUTH_SHUFFLE_RESERVOIR_ERR_INVALID = -3,
    KNUTH_SHUFFLE_RESERVOIR_ERR_OVERFLOW = -4,
    KNUTH_SHUFFLE_RESERVOIR_ERR_INVARIANT = -5
} knuth_shuffle_reservoir_err_t;



static inline const char* knuth_shuffle_reservoir_err_str(knuth_shuffle_reservoir_err_t err) {
    switch (err) {
        case KNUTH_SHUFFLE_RESERVOIR_OK: return "ok";
        case KNUTH_SHUFFLE_RESERVOIR_ERR_NULL: return "null pointer supplied";
        case KNUTH_SHUFFLE_RESERVOIR_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case KNUTH_SHUFFLE_RESERVOIR_ERR_INVALID: return "domain precondition violated";
        case KNUTH_SHUFFLE_RESERVOIR_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case KNUTH_SHUFFLE_RESERVOIR_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* KNUTH_SHUFFLE_RESERVOIR_ERRORS_H */
