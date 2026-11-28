#ifndef FLOYD_STEINBERG_DITHER_D61_ERRORS_H
#define FLOYD_STEINBERG_DITHER_D61_ERRORS_H

typedef enum floyd_steinberg_dither_d61_err {
    FLOYD_STEINBERG_DITHER_D61_OK = 0,
    FLOYD_STEINBERG_DITHER_D61_ERR_NULL = -1,
    FLOYD_STEINBERG_DITHER_D61_ERR_BOUNDS = -2,
    FLOYD_STEINBERG_DITHER_D61_ERR_INVALID = -3,
    FLOYD_STEINBERG_DITHER_D61_ERR_OVERFLOW = -4,
    FLOYD_STEINBERG_DITHER_D61_ERR_INVARIANT = -5
} floyd_steinberg_dither_d61_err_t;



static inline const char* floyd_steinberg_dither_d61_err_str(floyd_steinberg_dither_d61_err_t err) {
    switch (err) {
        case FLOYD_STEINBERG_DITHER_D61_OK: return "ok";
        case FLOYD_STEINBERG_DITHER_D61_ERR_NULL: return "null pointer supplied";
        case FLOYD_STEINBERG_DITHER_D61_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case FLOYD_STEINBERG_DITHER_D61_ERR_INVALID: return "domain precondition violated";
        case FLOYD_STEINBERG_DITHER_D61_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case FLOYD_STEINBERG_DITHER_D61_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* FLOYD_STEINBERG_DITHER_D61_ERRORS_H */
