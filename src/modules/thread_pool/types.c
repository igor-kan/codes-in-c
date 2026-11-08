/**
 * @file types.c
 * @brief Core type definitions and operational interfaces for Work-Stealing POSIX Thread Pool Engine.
 * Module: thread_pool
 */

#ifndef THREAD_POOL_TYPES_H
#define THREAD_POOL_TYPES_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define THREAD_POOL_ALIGNMENT 64
#define THREAD_POOL_SUCCESS 0
#define THREAD_POOL_ERR_NULL_PTR -1
#define THREAD_POOL_ERR_INVALID_PARAM -2
#define THREAD_POOL_ERR_OUT_OF_BOUNDS -3

typedef struct thread_pool_config {
    size_t capacity;
    uint32_t flags;
    double tolerance;
} thread_pool_config_t;

typedef struct thread_pool_context {
    void* buffer;
    size_t size;
    size_t capacity;
    uint64_t operations_count;
    thread_pool_config_t config;
} thread_pool_context_t;

int thread_pool_init(thread_pool_context_t* ctx, const thread_pool_config_t* cfg);
int thread_pool_destroy(thread_pool_context_t* ctx);

#ifdef __cplusplus
}
#endif

#endif /* THREAD_POOL_TYPES_H */
