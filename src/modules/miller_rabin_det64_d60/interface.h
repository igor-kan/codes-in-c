#ifndef MILLER_RABIN_DET64_D60_INTERFACE_H
#define MILLER_RABIN_DET64_D60_INTERFACE_H

#include "types.h"
#include "errors.h"

uint64_t mulmod_u64_d60(uint64_t a, uint64_t b, uint64_t mod);
uint64_t powmod_u64_d60(uint64_t base, uint64_t exp, uint64_t mod);
bool is_prime_u64_d60(uint64_t n);

miller_rabin_det64_d60_err_t miller_rabin_det64_d60_validate_len(size_t n);
uint64_t miller_rabin_det64_d60_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t miller_rabin_det64_d60_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
miller_rabin_det64_d60_err_t miller_rabin_det64_d60_verify_guard(bool cond);

#endif /* MILLER_RABIN_DET64_D60_INTERFACE_H */
