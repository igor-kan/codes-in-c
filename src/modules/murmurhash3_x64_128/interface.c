/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for Optimized 128-Bit MurmurHash3 Hashing Engine.
 * Module: murmurhash3_x64_128
 */

#ifndef MURMURHASH3_X64_128_INTERFACE_H
#define MURMURHASH3_X64_128_INTERFACE_H

#include "types.c"

typedef int (*murmurhash3_x64_128_transform_fn)(const double* in_data, double* out_data, size_t n);

typedef struct murmurhash3_x64_128_interface {
    int (*init)(murmurhash3_x64_128_state_t* state, const murmurhash3_x64_128_config_t* cfg);
    int (*execute)(murmurhash3_x64_128_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(murmurhash3_x64_128_state_t* state);
    int (*destroy)(murmurhash3_x64_128_state_t* state);
} murmurhash3_x64_128_interface_t;

#endif /* MURMURHASH3_X64_128_INTERFACE_H */
