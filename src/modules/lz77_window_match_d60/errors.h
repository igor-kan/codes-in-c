#ifndef LZ77_WINDOW_MATCH_D60_ERRORS_H
#define LZ77_WINDOW_MATCH_D60_ERRORS_H

typedef enum lz77_window_match_d60_err {
    LZ77_WINDOW_MATCH_D60_OK = 0,
    LZ77_WINDOW_MATCH_D60_ERR_NULL = -1,
    LZ77_WINDOW_MATCH_D60_ERR_BOUNDS = -2,
    LZ77_WINDOW_MATCH_D60_ERR_INVALID = -3,
    LZ77_WINDOW_MATCH_D60_ERR_OVERFLOW = -4,
    LZ77_WINDOW_MATCH_D60_ERR_INVARIANT = -5
} lz77_window_match_d60_err_t;



static inline const char* lz77_window_match_d60_err_str(lz77_window_match_d60_err_t err) {
    switch (err) {
        case LZ77_WINDOW_MATCH_D60_OK: return "ok";
        case LZ77_WINDOW_MATCH_D60_ERR_NULL: return "null pointer supplied";
        case LZ77_WINDOW_MATCH_D60_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case LZ77_WINDOW_MATCH_D60_ERR_INVALID: return "domain precondition violated";
        case LZ77_WINDOW_MATCH_D60_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case LZ77_WINDOW_MATCH_D60_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* LZ77_WINDOW_MATCH_D60_ERRORS_H */
