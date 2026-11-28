#include "interface.h"

goertzel_tone_detector_d61_err_t goertzel_tone_detector_d61_validate_len(size_t n) {
    if (n == 0) {
        return GOERTZEL_TONE_DETECTOR_D61_ERR_INVALID;
    }
    return GOERTZEL_TONE_DETECTOR_D61_OK;
}
