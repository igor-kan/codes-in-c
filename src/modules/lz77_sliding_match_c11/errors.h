#ifndef LZ77_SLIDING_MATCH_C11_ERRORS_H
#define LZ77_SLIDING_MATCH_C11_ERRORS_H

typedef enum lz77_sliding_match_c11_err {
    LZ77_SLIDING_MATCH_C11_OK = 0,
    LZ77_SLIDING_MATCH_C11_ERR_NULL = -1,
    LZ77_SLIDING_MATCH_C11_ERR_BOUNDS = -2,
    LZ77_SLIDING_MATCH_C11_ERR_INVALID = -3,
    LZ77_SLIDING_MATCH_C11_ERR_OVERFLOW = -4,
    LZ77_SLIDING_MATCH_C11_ERR_INVARIANT = -5
} lz77_sliding_match_c11_err_t;



static inline const char* lz77_sliding_match_c11_err_str(lz77_sliding_match_c11_err_t err) {
    switch (err) {
        case LZ77_SLIDING_MATCH_C11_OK: return "ok";
        case LZ77_SLIDING_MATCH_C11_ERR_NULL: return "null pointer supplied";
        case LZ77_SLIDING_MATCH_C11_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case LZ77_SLIDING_MATCH_C11_ERR_INVALID: return "domain precondition violated";
        case LZ77_SLIDING_MATCH_C11_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case LZ77_SLIDING_MATCH_C11_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* LZ77_SLIDING_MATCH_C11_ERRORS_H */
