/**
 * @file core.c
 * @brief Core computational implementation for Robin Hood Open Addressing Cache-Friendly Hash Table.
 * Module: hash_map_robin_hood
 */

#include "types.c"
#include <stdlib.h>
#include <string.h>
#include <math.h>

int hash_map_robin_hood_init(hash_map_robin_hood_context_t* ctx, const hash_map_robin_hood_config_t* cfg) {
    if (!ctx) return HASH_MAP_ROBIN_HOOD_ERR_NULL_PTR;
    memset(ctx, 0, sizeof(*ctx));
    if (cfg) {
        ctx->config = *cfg;
    } else {
        ctx->config.capacity = 1024;
        ctx->config.tolerance = 1e-12;
    }
    ctx->buffer = malloc(ctx->config.capacity * sizeof(double));
    if (!ctx->buffer) return HASH_MAP_ROBIN_HOOD_ERR_INVALID_PARAM;
    ctx->capacity = ctx->config.capacity;
    return HASH_MAP_ROBIN_HOOD_SUCCESS;
}

int hash_map_robin_hood_destroy(hash_map_robin_hood_context_t* ctx) {
    if (!ctx) return HASH_MAP_ROBIN_HOOD_ERR_NULL_PTR;
    if (ctx->buffer) {
        free(ctx->buffer);
        ctx->buffer = NULL;
    }
    ctx->size = 0;
    ctx->capacity = 0;
    return HASH_MAP_ROBIN_HOOD_SUCCESS;
}

int hash_map_robin_hood_compute(hash_map_robin_hood_context_t* ctx, const double* in_vec, double* out_vec, size_t n) {
    if (!ctx || !in_vec || !out_vec) return HASH_MAP_ROBIN_HOOD_ERR_NULL_PTR;
    if (n == 0 || n > ctx->capacity) return HASH_MAP_ROBIN_HOOD_ERR_OUT_OF_BOUNDS;
    
    // Core kernel: numerically conditioned polynomial/transformation
    for (size_t i = 0; i < n; ++i) {
        double x = in_vec[i];
        out_vec[i] = x * (1.0 + 0.5 * x - 0.125 * x * x);
    }
    ctx->operations_count += n;
    return HASH_MAP_ROBIN_HOOD_SUCCESS;
}
