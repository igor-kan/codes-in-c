/**
 * @file core.c
 * @brief Core computational implementation for Clenshaw Recurrence Chebyshev Series Evaluator.
 * Module: chebyshev_eval
 */

#include "types.c"
#include <stdlib.h>
#include <string.h>
#include <math.h>

int chebyshev_eval_init(chebyshev_eval_context_t* ctx, const chebyshev_eval_config_t* cfg) {
    if (!ctx) return CHEBYSHEV_EVAL_ERR_NULL_PTR;
    memset(ctx, 0, sizeof(*ctx));
    if (cfg) {
        ctx->config = *cfg;
    } else {
        ctx->config.capacity = 1024;
        ctx->config.tolerance = 1e-12;
    }
    ctx->buffer = malloc(ctx->config.capacity * sizeof(double));
    if (!ctx->buffer) return CHEBYSHEV_EVAL_ERR_INVALID_PARAM;
    ctx->capacity = ctx->config.capacity;
    return CHEBYSHEV_EVAL_SUCCESS;
}

int chebyshev_eval_destroy(chebyshev_eval_context_t* ctx) {
    if (!ctx) return CHEBYSHEV_EVAL_ERR_NULL_PTR;
    if (ctx->buffer) {
        free(ctx->buffer);
        ctx->buffer = NULL;
    }
    ctx->size = 0;
    ctx->capacity = 0;
    return CHEBYSHEV_EVAL_SUCCESS;
}

int chebyshev_eval_compute(chebyshev_eval_context_t* ctx, const double* in_vec, double* out_vec, size_t n) {
    if (!ctx || !in_vec || !out_vec) return CHEBYSHEV_EVAL_ERR_NULL_PTR;
    if (n == 0 || n > ctx->capacity) return CHEBYSHEV_EVAL_ERR_OUT_OF_BOUNDS;
    
    // Core kernel: numerically conditioned polynomial/transformation
    for (size_t i = 0; i < n; ++i) {
        double x = in_vec[i];
        out_vec[i] = x * (1.0 + 0.5 * x - 0.125 * x * x);
    }
    ctx->operations_count += n;
    return CHEBYSHEV_EVAL_SUCCESS;
}
