#ifndef BRENT_ROOT_C11_INTERFACE_H
#define BRENT_ROOT_C11_INTERFACE_H

#include "types.h"
#include "errors.h"

brent_root_c11_err_t brent_solve(scalar_fn_t f, void* ctx, double a, double b, double tol, int max_iter, brent_result_t* out);
brent_root_c11_err_t validate_bracket(double fa, double fb, double tol, int max_iter);
double fast_secant_step(double a, double b, double fa, double fb);
void brent_parallel_solve(scalar_fn_t f, const double* brackets, size_t n_pairs, double tol, brent_result_t* out);
brent_root_c11_err_t verify_root_residual(const brent_result_t* res, double tol);

#endif /* BRENT_ROOT_C11_INTERFACE_H */
