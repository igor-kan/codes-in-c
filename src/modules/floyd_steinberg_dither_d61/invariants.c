#include "interface.h"

floyd_steinberg_dither_d61_err_t floyd_steinberg_dither_d61_verify_guard(bool cond) {
    if (!cond) {
        return FLOYD_STEINBERG_DITHER_D61_ERR_INVARIANT;
    }
    return FLOYD_STEINBERG_DITHER_D61_OK;
}
