/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for Shannon-Fano-Elias Cumulative Distribution Codec.
 * Module: shannon_fano_elias | Algorithm Family: compression
 */

#ifndef SHANNON_FANO_ELIAS_INTERFACE_H
#define SHANNON_FANO_ELIAS_INTERFACE_H

#include "types.c"

typedef int (*shannon_fano_elias_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct shannon_fano_elias_vtable {
    int (*init)(shannon_fano_elias_state_t* state, const shannon_fano_elias_config_t* cfg);
    int (*execute)(shannon_fano_elias_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(shannon_fano_elias_state_t* state);
    int (*destroy)(shannon_fano_elias_state_t* state);
} shannon_fano_elias_vtable_t;

#endif /* SHANNON_FANO_ELIAS_INTERFACE_H */
