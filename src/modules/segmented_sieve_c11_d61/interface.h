#ifndef SEGMENTED_SIEVE_C11_D61_INTERFACE_H
#define SEGMENTED_SIEVE_C11_D61_INTERFACE_H

#include "types.h"
#include "errors.h"

size_t segmented_sieve(uint64_t low, uint64_t high, sieve_result_t* out);

segmented_sieve_c11_d61_err_t segmented_sieve_c11_d61_validate_len(size_t n);
uint64_t segmented_sieve_c11_d61_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t segmented_sieve_c11_d61_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
segmented_sieve_c11_d61_err_t segmented_sieve_c11_d61_verify_guard(bool cond);

#endif /* SEGMENTED_SIEVE_C11_D61_INTERFACE_H */
