#ifndef LZ77_SLIDING_CODEC_INTERFACE_H
#define LZ77_SLIDING_CODEC_INTERFACE_H

#include "types.h"
#include "errors.h"

lz77_sliding_codec_err_t lz77_sliding_codec_encode(const uint8_t* src, size_t src_len, lz77_token_t* out_tok, size_t max_tok, size_t* out_count, size_t window_size);
lz77_sliding_codec_err_t lz77_sliding_codec_decode(const lz77_token_t* toks, size_t tok_count, uint8_t* dst, size_t dst_cap, size_t* out_len);
lz77_sliding_codec_err_t lz77_sliding_codec_validate_tokens(const lz77_token_t* toks, size_t tok_count, size_t max_window);
lz77_sliding_codec_err_t lz77_sliding_codec_encode_fast(const uint8_t* src, size_t src_len, lz77_token_t* out_tok, size_t max_tok, size_t* out_count);
lz77_sliding_codec_err_t lz77_sliding_codec_batch_encode(const uint8_t** srcs, const size_t* lens, size_t* out_counts, size_t batch_size);
lz77_sliding_codec_err_t lz77_sliding_codec_verify_roundtrip(const uint8_t* src, size_t src_len, size_t window_size);

#endif /* LZ77_SLIDING_CODEC_INTERFACE_H */
