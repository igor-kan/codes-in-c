#ifndef LZ77_SLIDING_MATCH_C11_INTERFACE_H
#define LZ77_SLIDING_MATCH_C11_INTERFACE_H

#include "types.h"
#include "errors.h"

size_t lz77_compress(const uint8_t *src, size_t len, size_t window, lz77_token_t *out, size_t max_tok);
size_t lz77_decompress(const lz77_token_t *tok, size_t ntok, uint8_t *dst);

lz77_sliding_match_c11_err_t lz77_sliding_match_c11_validate_len(size_t n);
uint64_t lz77_sliding_match_c11_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t lz77_sliding_match_c11_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
lz77_sliding_match_c11_err_t lz77_sliding_match_c11_verify_guard(bool cond);

#endif /* LZ77_SLIDING_MATCH_C11_INTERFACE_H */
