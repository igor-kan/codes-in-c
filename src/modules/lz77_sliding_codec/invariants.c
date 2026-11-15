#include "interface.h"
#include <stdlib.h>
#include <string.h>

lz77_sliding_codec_err_t lz77_sliding_codec_verify_roundtrip(const uint8_t* src, size_t src_len, size_t window_size) {
    if (src_len > 0 && !src) return LZ77_SLIDING_CODEC_ERR_NULL;
    lz77_token_t* toks = (lz77_token_t*)malloc((src_len + 1) * sizeof(lz77_token_t));
    uint8_t* rec = (uint8_t*)malloc(src_len + 1);
    if (!toks || !rec) { free(toks); free(rec); return LZ77_SLIDING_CODEC_ERR_BOUNDS; }
    size_t cnt = 0, dec_len = 0;
    lz77_sliding_codec_err_t err = lz77_sliding_codec_encode(src, src_len, toks, src_len + 1, &cnt, window_size);
    if (err == LZ77_SLIDING_CODEC_OK) err = lz77_sliding_codec_validate_tokens(toks, cnt, window_size);
    if (err == LZ77_SLIDING_CODEC_OK) err = lz77_sliding_codec_decode(toks, cnt, rec, src_len + 1, &dec_len);
    if (err == LZ77_SLIDING_CODEC_OK && (dec_len != src_len || (src_len > 0 && memcmp(src, rec, src_len) != 0))) {
        err = LZ77_SLIDING_CODEC_ERR_INVARIANT;
    }
    free(toks);
    free(rec);
    return err;
}
