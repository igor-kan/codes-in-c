#include "interface.h"

goertzel_tone_detector_d61_err_t goertzel_tone_detector_d61_verify_guard(bool cond) {
    if (!cond) {
        return GOERTZEL_TONE_DETECTOR_D61_ERR_INVARIANT;
    }
    return GOERTZEL_TONE_DETECTOR_D61_OK;
}
