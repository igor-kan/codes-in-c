#ifndef DELTA_ZIG_FRAME_C11_D57_INTERFACE_H
#define DELTA_ZIG_FRAME_C11_D57_INTERFACE_H

#include "types.h"
#include "errors.h"

void delta_encode(const int64_t *src, size_t n, int64_t *deltas);
void delta_decode(const int64_t *deltas, size_t n, int64_t *dst);

delta_zig_frame_c11_d57_err_t delta_zig_frame_c11_d57_validate_len(size_t n);
uint64_t delta_zig_frame_c11_d57_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t delta_zig_frame_c11_d57_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
delta_zig_frame_c11_d57_err_t delta_zig_frame_c11_d57_verify_guard(bool cond);

#endif /* DELTA_ZIG_FRAME_C11_D57_INTERFACE_H */
