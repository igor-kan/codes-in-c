#ifndef BRENT_POLLARD_FACTOR_C11_INTERFACE_H
#define BRENT_POLLARD_FACTOR_C11_INTERFACE_H

#include "types.h"
#include "errors.h"

uint64_t brent_gcd_u64(uint64_t a, uint64_t b);
uint64_t brent_pollard_rho(uint64_t n, uint64_t c);

brent_pollard_factor_c11_err_t brent_pollard_factor_c11_validate_len(size_t n);
uint64_t brent_pollard_factor_c11_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t brent_pollard_factor_c11_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
brent_pollard_factor_c11_err_t brent_pollard_factor_c11_verify_guard(bool cond);

#endif /* BRENT_POLLARD_FACTOR_C11_INTERFACE_H */
