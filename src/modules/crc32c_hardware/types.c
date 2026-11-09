/**
 * @file types.c
 * @brief Core types and configuration for Hardware-Accelerated CRC32-C Checksum Engine.
 * Module: crc32c_hardware
 */

#ifndef CRC32C_HARDWARE_TYPES_H
#define CRC32C_HARDWARE_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define CRC32C_HARDWARE_ALIGNMENT 64
#define CRC32C_HARDWARE_CAPACITY 2048

typedef struct crc32c_hardware_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} crc32c_hardware_config_t;

typedef struct crc32c_hardware_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    crc32c_hardware_config_t config;
} crc32c_hardware_state_t;

#endif /* CRC32C_HARDWARE_TYPES_H */
