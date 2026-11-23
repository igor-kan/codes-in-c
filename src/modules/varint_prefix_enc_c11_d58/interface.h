#ifndef VARINT_PREFIX_ENC_C11_D58_INTERFACE_H
#define VARINT_PREFIX_ENC_C11_D58_INTERFACE_H

#include "types.h"
#include "errors.h"

size_t pvar_encode(uint64_t v, uint8_t *dst);
int pvar_decode(const uint8_t *src, size_t avail, uint64_t *out, size_t *used);

varint_prefix_enc_c11_d58_err_t varint_prefix_enc_c11_d58_validate_len(size_t n);
uint64_t varint_prefix_enc_c11_d58_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t varint_prefix_enc_c11_d58_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
varint_prefix_enc_c11_d58_err_t varint_prefix_enc_c11_d58_verify_guard(bool cond);

#endif /* VARINT_PREFIX_ENC_C11_D58_INTERFACE_H */
