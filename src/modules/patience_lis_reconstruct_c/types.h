#ifndef PATIENCE_LIS_RECONSTRUCT_C_TYPES_H
#define PATIENCE_LIS_RECONSTRUCT_C_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    size_t length;
    int64_t seq[128];
} lis_result_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} patience_lis_reconstruct_c_meta_t;

#endif /* PATIENCE_LIS_RECONSTRUCT_C_TYPES_H */
