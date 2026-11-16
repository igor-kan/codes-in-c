#ifndef RESERVOIR_SAMPLING_VITTER_ERRORS_H
#define RESERVOIR_SAMPLING_VITTER_ERRORS_H

typedef enum reservoir_sampling_vitter_err {
    RESERVOIR_SAMPLING_VITTER_OK = 0,
    RESERVOIR_SAMPLING_VITTER_ERR_NULL = -1,
    RESERVOIR_SAMPLING_VITTER_ERR_BOUNDS = -2,
    RESERVOIR_SAMPLING_VITTER_ERR_INVALID = -3,
    RESERVOIR_SAMPLING_VITTER_ERR_OVERFLOW = -4,
    RESERVOIR_SAMPLING_VITTER_ERR_INVARIANT = -5
} reservoir_sampling_vitter_err_t;



static inline const char* reservoir_sampling_vitter_err_str(reservoir_sampling_vitter_err_t err) {
    switch (err) {
        case RESERVOIR_SAMPLING_VITTER_OK: return "ok";
        case RESERVOIR_SAMPLING_VITTER_ERR_NULL: return "null pointer supplied";
        case RESERVOIR_SAMPLING_VITTER_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case RESERVOIR_SAMPLING_VITTER_ERR_INVALID: return "domain precondition violated";
        case RESERVOIR_SAMPLING_VITTER_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case RESERVOIR_SAMPLING_VITTER_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* RESERVOIR_SAMPLING_VITTER_ERRORS_H */
