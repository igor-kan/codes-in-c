/**
 * @file types.c
 * @brief Core types and configuration for Hazard Pointer Domain Manager for Lock-Free Memory.
 * Module: hazard_pointer_domain
 */

#ifndef HAZARD_POINTER_DOMAIN_TYPES_H
#define HAZARD_POINTER_DOMAIN_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define HAZARD_POINTER_DOMAIN_ALIGNMENT 64
#define HAZARD_POINTER_DOMAIN_CAPACITY 4096

typedef struct hazard_pointer_domain_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} hazard_pointer_domain_config_t;

typedef struct hazard_pointer_domain_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    hazard_pointer_domain_config_t config;
} hazard_pointer_domain_state_t;

#endif /* HAZARD_POINTER_DOMAIN_TYPES_H */
