#ifndef FENWICK_2D_GRID_C11_INTERFACE_H
#define FENWICK_2D_GRID_C11_INTERFACE_H

#include "types.h"
#include "errors.h"

void fw2d_init(fenwick2d_t* f, int32_t rows, int32_t cols);
void fw2d_add(fenwick2d_t* f, int32_t r, int32_t c, int64_t delta);
int64_t fw2d_prefix(const fenwick2d_t* f, int32_t r, int32_t c);
int64_t fw2d_rect_sum(const fenwick2d_t* f, int32_t r1, int32_t c1, int32_t r2, int32_t c2);

fenwick_2d_grid_c11_err_t fenwick_2d_grid_c11_validate_len(size_t n);
uint64_t fenwick_2d_grid_c11_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t fenwick_2d_grid_c11_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
fenwick_2d_grid_c11_err_t fenwick_2d_grid_c11_verify_guard(bool cond);

#endif /* FENWICK_2D_GRID_C11_INTERFACE_H */
