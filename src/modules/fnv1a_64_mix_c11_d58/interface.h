#ifndef FNV1A_64_MIX_C11_D58_INTERFACE_H
#define FNV1A_64_MIX_C11_D58_INTERFACE_H

#include "types.h"
#include "errors.h"

void fnv1a_init(fnv1a_stream_t *st);
void fnv1a_update(fnv1a_stream_t *st, const uint8_t *buf, size_t n);

fnv1a_64_mix_c11_d58_err_t fnv1a_64_mix_c11_d58_validate_len(size_t n);
uint64_t fnv1a_64_mix_c11_d58_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t fnv1a_64_mix_c11_d58_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
fnv1a_64_mix_c11_d58_err_t fnv1a_64_mix_c11_d58_verify_guard(bool cond);

#endif /* FNV1A_64_MIX_C11_D58_INTERFACE_H */
