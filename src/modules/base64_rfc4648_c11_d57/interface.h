#ifndef BASE64_RFC4648_C11_D57_INTERFACE_H
#define BASE64_RFC4648_C11_D57_INTERFACE_H

#include "types.h"
#include "errors.h"

size_t b64_encode(const uint8_t *src, size_t len, uint8_t *dst);
int b64_decode(const uint8_t *src, size_t len, uint8_t *dst, size_t *out_len);

base64_rfc4648_c11_d57_err_t base64_rfc4648_c11_d57_validate_len(size_t n);
uint64_t base64_rfc4648_c11_d57_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t base64_rfc4648_c11_d57_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
base64_rfc4648_c11_d57_err_t base64_rfc4648_c11_d57_verify_guard(bool cond);

#endif /* BASE64_RFC4648_C11_D57_INTERFACE_H */
