#ifndef LZ77_WINDOW_MATCH_D60_INTERFACE_H
#define LZ77_WINDOW_MATCH_D60_INTERFACE_H

#include "types.h"
#include "errors.h"

size_t lz77_encode_d60(const uint8_t* in, size_t n, lz77_tok_t* out, size_t cap);
size_t lz77_decode_d60(const lz77_tok_t* toks, size_t ntoks, uint8_t* out, size_t cap);

lz77_window_match_d60_err_t lz77_window_match_d60_validate_len(size_t n);
uint64_t lz77_window_match_d60_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t lz77_window_match_d60_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
lz77_window_match_d60_err_t lz77_window_match_d60_verify_guard(bool cond);

#endif /* LZ77_WINDOW_MATCH_D60_INTERFACE_H */
