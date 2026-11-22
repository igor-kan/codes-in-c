#ifndef MURMUR3_32_FOLD_C11_D57_INTERFACE_H
#define MURMUR3_32_FOLD_C11_D57_INTERFACE_H

#include "types.h"
#include "errors.h"

uint32_t murmur3_32(const uint8_t *key, size_t len, uint32_t seed);

murmur3_32_fold_c11_d57_err_t murmur3_32_fold_c11_d57_validate_len(size_t n);
uint64_t murmur3_32_fold_c11_d57_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t murmur3_32_fold_c11_d57_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
murmur3_32_fold_c11_d57_err_t murmur3_32_fold_c11_d57_verify_guard(bool cond);

#endif /* MURMUR3_32_FOLD_C11_D57_INTERFACE_H */
