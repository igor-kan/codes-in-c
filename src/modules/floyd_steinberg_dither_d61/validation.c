#include "interface.h"

floyd_steinberg_dither_d61_err_t floyd_steinberg_dither_d61_validate_len(size_t n) {
    if (n == 0) {
        return FLOYD_STEINBERG_DITHER_D61_ERR_INVALID;
    }
    return FLOYD_STEINBERG_DITHER_D61_OK;
}
