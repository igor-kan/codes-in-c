#ifndef PEARSON_R_CORR_C11_D59_INTERFACE_H
#define PEARSON_R_CORR_C11_D59_INTERFACE_H

#include "types.h"
#include "errors.h"

void welford_init(welford_t *w);
void welford_add(welford_t *w, double x);
double welford_var(const welford_t *w);

pearson_r_corr_c11_d59_err_t pearson_r_corr_c11_d59_validate_len(size_t n);
uint64_t pearson_r_corr_c11_d59_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t pearson_r_corr_c11_d59_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
pearson_r_corr_c11_d59_err_t pearson_r_corr_c11_d59_verify_guard(bool cond);

#endif /* PEARSON_R_CORR_C11_D59_INTERFACE_H */
