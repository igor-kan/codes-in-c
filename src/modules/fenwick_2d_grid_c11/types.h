#ifndef FENWICK_2D_GRID_C11_TYPES_H
#define FENWICK_2D_GRID_C11_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define FW2D_MAX 32
typedef struct {
    int32_t rows;
    int32_t cols;
    int64_t bit[FW2D_MAX + 1][FW2D_MAX + 1];
} fenwick2d_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} fenwick_2d_grid_c11_meta_t;

#endif /* FENWICK_2D_GRID_C11_TYPES_H */
