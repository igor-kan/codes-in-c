/**
 * @file types.c
 * @brief Core type definitions and operational interfaces for Clenshaw Recurrence Chebyshev Series Evaluator.
 * Module: chebyshev_eval
 */

#ifndef CHEBYSHEV_EVAL_TYPES_H
#define CHEBYSHEV_EVAL_TYPES_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define CHEBYSHEV_EVAL_ALIGNMENT 64
#define CHEBYSHEV_EVAL_SUCCESS 0
#define CHEBYSHEV_EVAL_ERR_NULL_PTR -1
#define CHEBYSHEV_EVAL_ERR_INVALID_PARAM -2
#define CHEBYSHEV_EVAL_ERR_OUT_OF_BOUNDS -3

typedef struct chebyshev_eval_config {
    size_t capacity;
    uint32_t flags;
    double tolerance;
} chebyshev_eval_config_t;

typedef struct chebyshev_eval_context {
    void* buffer;
    size_t size;
    size_t capacity;
    uint64_t operations_count;
    chebyshev_eval_config_t config;
} chebyshev_eval_context_t;

int chebyshev_eval_init(chebyshev_eval_context_t* ctx, const chebyshev_eval_config_t* cfg);
int chebyshev_eval_destroy(chebyshev_eval_context_t* ctx);

#ifdef __cplusplus
}
#endif

#endif /* CHEBYSHEV_EVAL_TYPES_H */
