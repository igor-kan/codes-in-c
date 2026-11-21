#ifndef COBS_FRAMING_CODEC_C11_INTERFACE_H
#define COBS_FRAMING_CODEC_C11_INTERFACE_H

#include "types.h"
#include "errors.h"

size_t cobs_encode(const uint8_t *src, size_t len, uint8_t *dst);
int cobs_decode(const uint8_t *src, size_t len, uint8_t *dst, size_t *out_len);

cobs_framing_codec_c11_err_t cobs_framing_codec_c11_validate_len(size_t n);
uint64_t cobs_framing_codec_c11_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t cobs_framing_codec_c11_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
cobs_framing_codec_c11_err_t cobs_framing_codec_c11_verify_guard(bool cond);

#endif /* COBS_FRAMING_CODEC_C11_INTERFACE_H */
