#ifndef COBS_FRAMING_CODEC_ERRORS_H
#define COBS_FRAMING_CODEC_ERRORS_H

typedef enum cobs_framing_codec_err {
    COBS_FRAMING_CODEC_OK = 0,
    COBS_FRAMING_CODEC_ERR_NULL = -1,
    COBS_FRAMING_CODEC_ERR_BOUNDS = -2,
    COBS_FRAMING_CODEC_ERR_INVALID = -3,
    COBS_FRAMING_CODEC_ERR_OVERFLOW = -4,
    COBS_FRAMING_CODEC_ERR_INVARIANT = -5
} cobs_framing_codec_err_t;



static inline const char* cobs_framing_codec_err_str(cobs_framing_codec_err_t err) {
    switch (err) {
        case COBS_FRAMING_CODEC_OK: return "ok";
        case COBS_FRAMING_CODEC_ERR_NULL: return "null pointer supplied";
        case COBS_FRAMING_CODEC_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case COBS_FRAMING_CODEC_ERR_INVALID: return "domain precondition violated";
        case COBS_FRAMING_CODEC_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case COBS_FRAMING_CODEC_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* COBS_FRAMING_CODEC_ERRORS_H */
