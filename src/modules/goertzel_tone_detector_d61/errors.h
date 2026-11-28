#ifndef GOERTZEL_TONE_DETECTOR_D61_ERRORS_H
#define GOERTZEL_TONE_DETECTOR_D61_ERRORS_H

typedef enum goertzel_tone_detector_d61_err {
    GOERTZEL_TONE_DETECTOR_D61_OK = 0,
    GOERTZEL_TONE_DETECTOR_D61_ERR_NULL = -1,
    GOERTZEL_TONE_DETECTOR_D61_ERR_BOUNDS = -2,
    GOERTZEL_TONE_DETECTOR_D61_ERR_INVALID = -3,
    GOERTZEL_TONE_DETECTOR_D61_ERR_OVERFLOW = -4,
    GOERTZEL_TONE_DETECTOR_D61_ERR_INVARIANT = -5
} goertzel_tone_detector_d61_err_t;



static inline const char* goertzel_tone_detector_d61_err_str(goertzel_tone_detector_d61_err_t err) {
    switch (err) {
        case GOERTZEL_TONE_DETECTOR_D61_OK: return "ok";
        case GOERTZEL_TONE_DETECTOR_D61_ERR_NULL: return "null pointer supplied";
        case GOERTZEL_TONE_DETECTOR_D61_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case GOERTZEL_TONE_DETECTOR_D61_ERR_INVALID: return "domain precondition violated";
        case GOERTZEL_TONE_DETECTOR_D61_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case GOERTZEL_TONE_DETECTOR_D61_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* GOERTZEL_TONE_DETECTOR_D61_ERRORS_H */
