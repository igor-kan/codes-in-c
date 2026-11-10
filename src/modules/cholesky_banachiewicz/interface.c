/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for Row-by-Row Cholesky-Banachiewicz Matrix Factorization.
 * Module: cholesky_banachiewicz
 */

#ifndef CHOLESKY_BANACHIEWICZ_INTERFACE_H
#define CHOLESKY_BANACHIEWICZ_INTERFACE_H

#include "types.c"

typedef int (*cholesky_banachiewicz_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct cholesky_banachiewicz_vtable {
    int (*init)(cholesky_banachiewicz_state_t* state, const cholesky_banachiewicz_config_t* cfg);
    int (*execute)(cholesky_banachiewicz_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(cholesky_banachiewicz_state_t* state);
    int (*destroy)(cholesky_banachiewicz_state_t* state);
} cholesky_banachiewicz_vtable_t;

#endif /* CHOLESKY_BANACHIEWICZ_INTERFACE_H */
