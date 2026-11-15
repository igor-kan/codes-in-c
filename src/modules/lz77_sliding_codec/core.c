#include "interface.h"
#include <string.h>

lz77_sliding_codec_err_t lz77_sliding_codec_encode(
    const uint8_t* src, size_t src_len,
    lz77_token_t* out_tok, size_t max_tok, size_t* out_count, size_t window_size
) {
    if (!out_count || (src_len > 0 && (!src || !out_tok))) return LZ77_SLIDING_CODEC_ERR_NULL;
    if (window_size == 0 || window_size > LZ77_MAX_WINDOW) return LZ77_SLIDING_CODEC_ERR_INVALID;
    size_t pos = 0, cnt = 0;
    while (pos < src_len) {
        if (cnt >= max_tok) return LZ77_SLIDING_CODEC_ERR_BOUNDS;
        size_t wstart = (pos > window_size) ? (pos - window_size) : 0;
        size_t best_len = 0, best_off = 0;
        for (size_t s = wstart; s < pos; ++s) {
            size_t len = 0;
            while (len < LZ77_MAX_MATCH && (pos + len) < src_len && src[s + len] == src[pos + len]) {
                len++;
            }
            if (len > best_len) {
                best_len = len;
                best_off = pos - s;
            }
        }
        lz77_token_t tok = {0, 0, 0, 0};
        tok.offset = (uint16_t)best_off;
        tok.length = (uint8_t)best_len;
        if (pos + best_len < src_len) {
            tok.next = src[pos + best_len];
            tok.has_next = 1;
            pos += best_len + 1;
        } else {
            tok.has_next = 0;
            pos += best_len;
        }
        out_tok[cnt++] = tok;
    }
    *out_count = cnt;
    return LZ77_SLIDING_CODEC_OK;
}

lz77_sliding_codec_err_t lz77_sliding_codec_decode(
    const lz77_token_t* toks, size_t tok_count,
    uint8_t* dst, size_t dst_cap, size_t* out_len
) {
    if (!out_len || (tok_count > 0 && (!toks || !dst))) return LZ77_SLIDING_CODEC_ERR_NULL;
    size_t pos = 0;
    for (size_t i = 0; i < tok_count; ++i) {
        lz77_token_t t = toks[i];
        if (t.length > 0) {
            if (t.offset == 0 || (size_t)t.offset > pos) return LZ77_SLIDING_CODEC_ERR_INVALID;
            if (pos + t.length > dst_cap) return LZ77_SLIDING_CODEC_ERR_BOUNDS;
            for (size_t k = 0; k < t.length; ++k) {
                dst[pos] = dst[pos - t.offset];
                pos++;
            }
        }
        if (t.has_next) {
            if (pos >= dst_cap) return LZ77_SLIDING_CODEC_ERR_BOUNDS;
            dst[pos++] = t.next;
        }
    }
    *out_len = pos;
    return LZ77_SLIDING_CODEC_OK;
}
