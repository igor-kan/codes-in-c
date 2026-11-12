/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for CORDIC Shift-and-Add Trigonometric Vector Rotation.
 * Module: fast_sin_cos_cordic | Algorithm Family: cordic
 */

#ifndef FAST_SIN_COS_CORDIC_INTERFACE_H
#define FAST_SIN_COS_CORDIC_INTERFACE_H

#include "types.c"

typedef int (*fast_sin_cos_cordic_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct fast_sin_cos_cordic_vtable {
    int (*init)(fast_sin_cos_cordic_state_t* state, const fast_sin_cos_cordic_config_t* cfg);
    int (*execute)(fast_sin_cos_cordic_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(fast_sin_cos_cordic_state_t* state);
    int (*destroy)(fast_sin_cos_cordic_state_t* state);
} fast_sin_cos_cordic_vtable_t;

#endif /* FAST_SIN_COS_CORDIC_INTERFACE_H */
