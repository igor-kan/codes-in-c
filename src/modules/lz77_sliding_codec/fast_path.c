#include "interface.h"
#include <stdint.h>

lz77_sliding_codec_err_t lz77_sliding_codec_encode_fast(
    const uint8_t* src, size_t src_len,
    lz77_token_t* out_tok, size_t max_tok, size_t* out_count
) {
    // 256-entry 2-byte rolling index head table for fast candidate lookup
    if (!out_count || (src_len > 0 && (!src || !out_tok))) return LZ77_SLIDING_CODEC_ERR_NULL;
    size_t head[256];
    for (size_t i = 0; i < 256; ++i) head[i] = (size_t)-1;
    size_t pos = 0, cnt = 0;
    while (pos < src_len) {
        if (cnt >= max_tok) return LZ77_SLIDING_CODEC_ERR_BOUNDS;
        size_t best_len = 0, best_off = 0;
        if (pos + 2 < src_len) {
            uint8_t key = (uint8_t)(src[pos] ^ (src[pos + 1] * 31U));
            size_t cand = head[key];
            if (cand != (size_t)-1 && cand < pos && (pos - cand) <= 1024U) {
                while (best_len < LZ77_MAX_MATCH && (pos + best_len) < src_len && src[cand + best_len] == src[pos + best_len]) {
                    best_len++;
                }
                if (best_len >= 3) best_off = pos - cand; else best_len = 0;
            }
            head[key] = pos;
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
