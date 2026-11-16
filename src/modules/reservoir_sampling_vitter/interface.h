#ifndef RESERVOIR_SAMPLING_VITTER_INTERFACE_H
#define RESERVOIR_SAMPLING_VITTER_INTERFACE_H

#include "types.h"
#include "errors.h"

reservoir_sampling_vitter_err_t reservoir_init(reservoir_t* r, int64_t* backing, size_t k, uint64_t seed);
void reservoir_observe(reservoir_t* r, int64_t value);
reservoir_sampling_vitter_err_t reservoir_validate(const reservoir_t* r);
void reservoir_observe_batch(reservoir_t* r, const int64_t* values, size_t n);
reservoir_sampling_vitter_err_t reservoir_mt_histogram(size_t k, size_t stream_len, size_t trials, uint64_t* freq_out, size_t num_threads);
reservoir_sampling_vitter_err_t reservoir_verify_invariants(const reservoir_t* r, int64_t min_val, int64_t max_val);

#endif /* RESERVOIR_SAMPLING_VITTER_INTERFACE_H */
