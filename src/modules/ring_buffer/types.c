/**
 * @file types.c
 * @brief Core type definitions and operational interfaces for Lock-Free SPSC Circular Ring Buffer.
 * Module: ring_buffer
 */

#ifndef RING_BUFFER_TYPES_H
#define RING_BUFFER_TYPES_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define RING_BUFFER_ALIGNMENT 64
#define RING_BUFFER_SUCCESS 0
#define RING_BUFFER_ERR_NULL_PTR -1
#define RING_BUFFER_ERR_INVALID_PARAM -2
#define RING_BUFFER_ERR_OUT_OF_BOUNDS -3

typedef struct ring_buffer_config {
    size_t capacity;
    uint32_t flags;
    double tolerance;
} ring_buffer_config_t;

typedef struct ring_buffer_context {
    void* buffer;
    size_t size;
    size_t capacity;
    uint64_t operations_count;
    ring_buffer_config_t config;
} ring_buffer_context_t;

int ring_buffer_init(ring_buffer_context_t* ctx, const ring_buffer_config_t* cfg);
int ring_buffer_destroy(ring_buffer_context_t* ctx);

#ifdef __cplusplus
}
#endif

#endif /* RING_BUFFER_TYPES_H */
