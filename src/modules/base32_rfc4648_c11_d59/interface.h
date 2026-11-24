#ifndef BASE32_RFC4648_C11_D59_INTERFACE_H
#define BASE32_RFC4648_C11_D59_INTERFACE_H

#include "types.h"
#include "errors.h"

size_t b32_encode(const uint8_t *src, size_t len, uint8_t *dst);
int b32_decode(const uint8_t *src, size_t len, uint8_t *dst, size_t *out_len);

base32_rfc4648_c11_d59_err_t base32_rfc4648_c11_d59_validate_len(size_t n);
uint64_t base32_rfc4648_c11_d59_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t base32_rfc4648_c11_d59_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
base32_rfc4648_c11_d59_err_t base32_rfc4648_c11_d59_verify_guard(bool cond);

#endif /* BASE32_RFC4648_C11_D59_INTERFACE_H */
