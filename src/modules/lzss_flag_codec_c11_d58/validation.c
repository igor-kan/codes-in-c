#include "interface.h"

lzss_flag_codec_c11_d58_err_t lzss_flag_codec_c11_d58_validate_len(size_t n) {
    if (n == 0) {
        return LZSS_FLAG_CODEC_C11_D58_ERR_INVALID;
    }
    return LZSS_FLAG_CODEC_C11_D58_OK;
}
