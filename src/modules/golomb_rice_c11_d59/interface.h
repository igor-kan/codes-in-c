#ifndef GOLOMB_RICE_C11_D59_INTERFACE_H
#define GOLOMB_RICE_C11_D59_INTERFACE_H

#include "types.h"
#include "errors.h"

size_t gr_encode_bits(const uint32_t *vals, size_t n, uint32_t k, uint8_t *bits_out);
size_t gr_decode_bits(const uint8_t *bits, size_t n_bits, uint32_t k, uint32_t *out);

golomb_rice_c11_d59_err_t golomb_rice_c11_d59_validate_len(size_t n);
uint64_t golomb_rice_c11_d59_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t golomb_rice_c11_d59_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
golomb_rice_c11_d59_err_t golomb_rice_c11_d59_verify_guard(bool cond);

#endif /* GOLOMB_RICE_C11_D59_INTERFACE_H */
