#ifndef KNUTH_SHUFFLE_RESERVOIR_INTERFACE_H
#define KNUTH_SHUFFLE_RESERVOIR_INTERFACE_H

#include "types.h"
#include "errors.h"

uint64_t splitmix64_next(prng64_t* rng);
knuth_shuffle_reservoir_err_t fisher_yates_shuffle(int64_t* arr, size_t n, uint64_t seed);
knuth_shuffle_reservoir_err_t reservoir_sample_l(const int64_t* stream, size_t n, int64_t* sample, size_t k, uint64_t seed);
knuth_shuffle_reservoir_err_t validate_sample_bounds(size_t n, size_t k);
void fast_bounded_permute(int64_t* arr, size_t n, prng64_t* rng);
void parallel_independent_shuffles(int64_t* a, int64_t* b, size_t n, uint64_t seed);
knuth_shuffle_reservoir_err_t verify_permutation_parity(const int64_t* orig, const int64_t* shuf, size_t n);

#endif /* KNUTH_SHUFFLE_RESERVOIR_INTERFACE_H */
