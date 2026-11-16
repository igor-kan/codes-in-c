#ifndef TRIDIAGONAL_THOMAS_C11_INTERFACE_H
#define TRIDIAGONAL_THOMAS_C11_INTERFACE_H

#include "types.h"
#include "errors.h"

tridiagonal_thomas_c11_err_t tdma_solve(size_t n, const double* a, const double* b, const double* c, const double* d, double* x, double* c_prime, double* d_prime);
tridiagonal_thomas_c11_err_t tdma_validate(size_t n, const double* a, const double* b, const double* c, const double* d, const double* x);
tridiagonal_thomas_c11_err_t tdma_solve_constant_coeff(size_t n, double sub, double diag, double sup, const double* d, double* x);
tridiagonal_thomas_c11_err_t tdma_batch_solve_mt(size_t n_systems, size_t n, const double* sub, const double* diag, const double* sup, const double* rhs_batch, double* x_batch, size_t num_threads);
tridiagonal_thomas_c11_err_t tdma_verify_residual(size_t n, const double* a, const double* b, const double* c, const double* d, const double* x, double tol);

#endif /* TRIDIAGONAL_THOMAS_C11_INTERFACE_H */
