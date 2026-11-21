#ifndef LEB128_VARINT_CODEC_C11_INTERFACE_H
#define LEB128_VARINT_CODEC_C11_INTERFACE_H

#include "types.h"
#include "errors.h"

size_t uleb128_encode(uint64_t val, uint8_t *dst);
int uleb128_decode(const uint8_t *src, size_t max_len, uint64_t *out, size_t *consumed);
uint64_t zigzag_encode64(int64_t s);
int64_t zigzag_decode64(uint64_t u);

leb128_varint_codec_c11_err_t leb128_varint_codec_c11_validate_len(size_t n);
uint64_t leb128_varint_codec_c11_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t leb128_varint_codec_c11_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
leb128_varint_codec_c11_err_t leb128_varint_codec_c11_verify_guard(bool cond);

#endif /* LEB128_VARINT_CODEC_C11_INTERFACE_H */
