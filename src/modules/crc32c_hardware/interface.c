/**
 * @file interface.c
 * @brief Abstract contracts and prototypes for Hardware-Accelerated CRC32-C Checksum Engine.
 * Module: crc32c_hardware
 */

#ifndef CRC32C_HARDWARE_INTERFACE_H
#define CRC32C_HARDWARE_INTERFACE_H

#include "types.c"

typedef int (*crc32c_hardware_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct crc32c_hardware_vtable {
    int (*init)(crc32c_hardware_state_t* state, const crc32c_hardware_config_t* cfg);
    int (*execute)(crc32c_hardware_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*destroy)(crc32c_hardware_state_t* state);
} crc32c_hardware_vtable_t;

#endif /* CRC32C_HARDWARE_INTERFACE_H */
