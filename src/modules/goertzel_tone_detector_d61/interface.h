#ifndef GOERTZEL_TONE_DETECTOR_D61_INTERFACE_H
#define GOERTZEL_TONE_DETECTOR_D61_INTERFACE_H

#include "types.h"
#include "errors.h"

goertzel_complex_t goertzel_single_bin(const double* samples, size_t n, uint32_t k);
double goertzel_bin_power(const double* samples, size_t n, uint32_t k);
size_t goertzel_dominant_bin(const double* samples, size_t n, size_t max_bin);

goertzel_tone_detector_d61_err_t goertzel_tone_detector_d61_validate_len(size_t n);
uint64_t goertzel_tone_detector_d61_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t goertzel_tone_detector_d61_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
goertzel_tone_detector_d61_err_t goertzel_tone_detector_d61_verify_guard(bool cond);

#endif /* GOERTZEL_TONE_DETECTOR_D61_INTERFACE_H */
