/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for FNV-1a 64-Bit Fast Non-Cryptographic Hash Engine.
 * Module: hash_fnv1a_64 | Algorithm Family: hashing
 */

#ifndef HASH_FNV1A_64_INTERFACE_H
#define HASH_FNV1A_64_INTERFACE_H

#include "types.c"

typedef int (*hash_fnv1a_64_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct hash_fnv1a_64_vtable {
    int (*init)(hash_fnv1a_64_state_t* state, const hash_fnv1a_64_config_t* cfg);
    int (*execute)(hash_fnv1a_64_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(hash_fnv1a_64_state_t* state);
    int (*destroy)(hash_fnv1a_64_state_t* state);
} hash_fnv1a_64_vtable_t;

#endif /* HASH_FNV1A_64_INTERFACE_H */
