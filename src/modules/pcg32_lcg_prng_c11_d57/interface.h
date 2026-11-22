#ifndef PCG32_LCG_PRNG_C11_D57_INTERFACE_H
#define PCG32_LCG_PRNG_C11_D57_INTERFACE_H

#include "types.h"
#include "errors.h"

void pcg32_seed(pcg32_rng_t *rng, uint64_t initstate, uint64_t initseq);
uint32_t pcg32_next(pcg32_rng_t *rng);
uint32_t pcg32_bounded(pcg32_rng_t *rng, uint32_t bound);

pcg32_lcg_prng_c11_d57_err_t pcg32_lcg_prng_c11_d57_validate_len(size_t n);
uint64_t pcg32_lcg_prng_c11_d57_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t pcg32_lcg_prng_c11_d57_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
pcg32_lcg_prng_c11_d57_err_t pcg32_lcg_prng_c11_d57_verify_guard(bool cond);

#endif /* PCG32_LCG_PRNG_C11_D57_INTERFACE_H */
