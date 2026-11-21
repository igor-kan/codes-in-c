#ifndef RESERVOIR_R_SKIP_C11_INTERFACE_H
#define RESERVOIR_R_SKIP_C11_INTERFACE_H

#include "types.h"
#include "errors.h"

size_t reservoir_sample_u64(size_t n_stream, size_t k, uint64_t seed, size_t *out);

reservoir_r_skip_c11_err_t reservoir_r_skip_c11_validate_len(size_t n);
uint64_t reservoir_r_skip_c11_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t reservoir_r_skip_c11_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
reservoir_r_skip_c11_err_t reservoir_r_skip_c11_verify_guard(bool cond);

#endif /* RESERVOIR_R_SKIP_C11_INTERFACE_H */
