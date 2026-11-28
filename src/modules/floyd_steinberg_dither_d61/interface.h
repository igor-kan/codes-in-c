#ifndef FLOYD_STEINBERG_DITHER_D61_INTERFACE_H
#define FLOYD_STEINBERG_DITHER_D61_INTERFACE_H

#include "types.h"
#include "errors.h"

size_t floyd_steinberg_dither(const uint8_t* gray, size_t width, size_t height, uint8_t* out);
uint64_t floyd_steinberg_quantization_error(const uint8_t* gray, size_t n, const uint8_t* out);

floyd_steinberg_dither_d61_err_t floyd_steinberg_dither_d61_validate_len(size_t n);
uint64_t floyd_steinberg_dither_d61_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t floyd_steinberg_dither_d61_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
floyd_steinberg_dither_d61_err_t floyd_steinberg_dither_d61_verify_guard(bool cond);

#endif /* FLOYD_STEINBERG_DITHER_D61_INTERFACE_H */
