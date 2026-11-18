#ifndef HERMITE_CUBIC_SPLINE_C11_INTERFACE_H
#define HERMITE_CUBIC_SPLINE_C11_INTERFACE_H

#include "types.h"
#include "errors.h"

void pchip_build(pchip_spline_t* s, const double* x, const double* y, size_t n);
double pchip_eval(const pchip_spline_t* s, double xq);

hermite_cubic_spline_c11_err_t hermite_cubic_spline_c11_validate_len(size_t n);
uint64_t hermite_cubic_spline_c11_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t hermite_cubic_spline_c11_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
hermite_cubic_spline_c11_err_t hermite_cubic_spline_c11_verify_guard(bool cond);

#endif /* HERMITE_CUBIC_SPLINE_C11_INTERFACE_H */
