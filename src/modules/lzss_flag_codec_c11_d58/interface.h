#ifndef LZSS_FLAG_CODEC_C11_D58_INTERFACE_H
#define LZSS_FLAG_CODEC_C11_D58_INTERFACE_H

#include "types.h"
#include "errors.h"

size_t lzss_compress(const uint8_t *src, size_t n, lzss_op_t *ops);
size_t lzss_decompress(const lzss_op_t *ops, size_t n_ops, uint8_t *dst);

lzss_flag_codec_c11_d58_err_t lzss_flag_codec_c11_d58_validate_len(size_t n);
uint64_t lzss_flag_codec_c11_d58_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t lzss_flag_codec_c11_d58_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
lzss_flag_codec_c11_d58_err_t lzss_flag_codec_c11_d58_verify_guard(bool cond);

#endif /* LZSS_FLAG_CODEC_C11_D58_INTERFACE_H */
