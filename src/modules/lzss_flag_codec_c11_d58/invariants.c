#include "interface.h"

lzss_flag_codec_c11_d58_err_t lzss_flag_codec_c11_d58_verify_guard(bool cond) {
    if (!cond) {
        return LZSS_FLAG_CODEC_C11_D58_ERR_INVARIANT;
    }
    return LZSS_FLAG_CODEC_C11_D58_OK;
}
