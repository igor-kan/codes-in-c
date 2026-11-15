#ifndef XXHASH64_STREAMING_ERRORS_H
#define XXHASH64_STREAMING_ERRORS_H

typedef enum xxhash64_streaming_err {
    XXHASH64_STREAMING_OK = 0,
    XXHASH64_STREAMING_ERR_NULL = -1,
    XXHASH64_STREAMING_ERR_BOUNDS = -2,
    XXHASH64_STREAMING_ERR_INVALID = -3,
    XXHASH64_STREAMING_ERR_OVERFLOW = -4,
    XXHASH64_STREAMING_ERR_INVARIANT = -5
} xxhash64_streaming_err_t;



static inline const char* xxhash64_streaming_err_str(xxhash64_streaming_err_t err) {
    switch (err) {
        case XXHASH64_STREAMING_OK: return "ok";
        case XXHASH64_STREAMING_ERR_NULL: return "null pointer supplied";
        case XXHASH64_STREAMING_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case XXHASH64_STREAMING_ERR_INVALID: return "domain precondition violated";
        case XXHASH64_STREAMING_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case XXHASH64_STREAMING_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* XXHASH64_STREAMING_ERRORS_H */
