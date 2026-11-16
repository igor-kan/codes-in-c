#include "interface.h"
#include <string.h>

size_t packbits_worst_case_size(size_t src_len) {
    return src_len + (src_len + 127U) / 128U + 2U;
}

rle_packbits_codec_err_t packbits_encode(const uint8_t* src, size_t len, uint8_t* dst, size_t dst_cap, size_t* out_len) {
    if (!dst || !out_len || (len > 0 && !src)) return RLE_PACKBITS_CODEC_ERR_NULL;
    if (dst_cap < packbits_worst_case_size(len)) return RLE_PACKBITS_CODEC_ERR_BOUNDS;
    size_t i = 0, w = 0;
    while (i < len) {
        size_t run = 1;
        while (i + run < len && run < 128U && src[i + run] == src[i]) ++run;
        if (run >= 2U) {
            dst[w++] = (uint8_t)(257U - run); // -(run - 1) as uint8_t
            dst[w++] = src[i];
            i += run;
        } else {
            size_t lit_start = i;
            size_t lit = 1;
            ++i;
            while (i < len && lit < 128U) {
                if (i + 1 < len && src[i] == src[i + 1]) break;
                ++lit;
                ++i;
            }
            dst[w++] = (uint8_t)(lit - 1U);
            memcpy(dst + w, src + lit_start, lit);
            w += lit;
        }
    }
    *out_len = w;
    return RLE_PACKBITS_CODEC_OK;
}

rle_packbits_codec_err_t packbits_decode(const uint8_t* src, size_t len, uint8_t* dst, size_t dst_cap, size_t* out_len) {
    if (!dst || !out_len || (len > 0 && !src)) return RLE_PACKBITS_CODEC_ERR_NULL;
    size_t i = 0, w = 0;
    while (i < len) {
        int8_t hdr = (int8_t)src[i++];
        if (hdr == -128) continue;
        if (hdr >= 0) {
            size_t cnt = (size_t)hdr + 1U;
            if (i + cnt > len) return RLE_PACKBITS_CODEC_ERR_INVALID;
            if (w + cnt > dst_cap) return RLE_PACKBITS_CODEC_ERR_BOUNDS;
            memcpy(dst + w, src + i, cnt);
            i += cnt;
            w += cnt;
        } else {
            size_t cnt = (size_t)(-hdr) + 1U;
            if (i >= len) return RLE_PACKBITS_CODEC_ERR_INVALID;
            if (w + cnt > dst_cap) return RLE_PACKBITS_CODEC_ERR_BOUNDS;
            memset(dst + w, src[i++], cnt);
            w += cnt;
        }
    }
    *out_len = w;
    return RLE_PACKBITS_CODEC_OK;
}
