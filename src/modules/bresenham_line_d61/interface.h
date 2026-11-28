#ifndef BRESENHAM_LINE_D61_INTERFACE_H
#define BRESENHAM_LINE_D61_INTERFACE_H

#include "types.h"
#include "errors.h"

size_t bresenham_line(int32_t x0, int32_t y0, int32_t x1, int32_t y1, bres_line_t* out);

bresenham_line_d61_err_t bresenham_line_d61_validate_len(size_t n);
uint64_t bresenham_line_d61_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t bresenham_line_d61_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
bresenham_line_d61_err_t bresenham_line_d61_verify_guard(bool cond);

#endif /* BRESENHAM_LINE_D61_INTERFACE_H */
