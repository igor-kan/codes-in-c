/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for Hazard Pointer Domain Manager for Lock-Free Memory.
 * Module: hazard_pointer_domain
 */

#ifndef HAZARD_POINTER_DOMAIN_INTERFACE_H
#define HAZARD_POINTER_DOMAIN_INTERFACE_H

#include "types.c"

typedef int (*hazard_pointer_domain_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct hazard_pointer_domain_vtable {
    int (*init)(hazard_pointer_domain_state_t* state, const hazard_pointer_domain_config_t* cfg);
    int (*execute)(hazard_pointer_domain_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(hazard_pointer_domain_state_t* state);
    int (*destroy)(hazard_pointer_domain_state_t* state);
} hazard_pointer_domain_vtable_t;

#endif /* HAZARD_POINTER_DOMAIN_INTERFACE_H */
