#include "interface.h"
#include <string.h>

cobs_framing_codec_err_t cobs_encode_fast(const uint8_t* src, size_t len, uint8_t* dst, size_t* out_len) {
    if (!dst || !out_len || (len > 0 && !src)) return COBS_FRAMING_CODEC_ERR_NULL;
    size_t i = 0, w = 1, code_pos = 0;
    while (i < len) {
        const uint8_t* z = (const uint8_t*)memchr(src + i, 0, (len - i > 254U) ? 254U : (len - i));
        if (!z) {
            size_t chunk = (len - i > 254U) ? 254U : (len - i);
            memcpy(dst + w, src + i, chunk);
            dst[code_pos] = (uint8_t)(chunk + 1U);
            w += chunk;
            i += chunk;
            if (chunk == 254U && i < len) {
                code_pos = w++;
            } else if (chunk == 254U) {
                code_pos = w++;
                dst[code_pos] = 1U;
            }
        } else {
            size_t chunk = (size_t)(z - (src + i));
            if (chunk > 0) memcpy(dst + w, src + i, chunk);
            dst[code_pos] = (uint8_t)(chunk + 1U);
            w += chunk;
            code_pos = w++;
            i += chunk + 1U;
            if (i == len) dst[code_pos] = 1U;
        }
    }
    if (len == 0) dst[0] = 1U;
    *out_len = w;
    return COBS_FRAMING_CODEC_OK;
}
