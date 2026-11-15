#include "interface.h"

lz77_sliding_codec_err_t lz77_sliding_codec_validate_tokens(const lz77_token_t* toks, size_t tok_count, size_t max_window) {
    if (tok_count > 0 && !toks) return LZ77_SLIDING_CODEC_ERR_NULL;
    size_t pos = 0;
    for (size_t i = 0; i < tok_count; ++i) {
        if (toks[i].length > 0 && (toks[i].offset == 0 || toks[i].offset > pos || toks[i].offset > max_window)) {
            return LZ77_SLIDING_CODEC_ERR_INVALID;
        }
        pos += toks[i].length + (toks[i].has_next ? 1U : 0U);
    }
    return LZ77_SLIDING_CODEC_OK;
}
