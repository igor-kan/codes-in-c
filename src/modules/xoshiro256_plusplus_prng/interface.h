#ifndef XOSHIRO256_PLUSPLUS_PRNG_INTERFACE_H
#define XOSHIRO256_PLUSPLUS_PRNG_INTERFACE_H

#include "types.h"
#include "errors.h"

xoshiro256_plusplus_prng_err_t xoshiro_seed(xoshiro256pp_state_t* st, uint64_t seed);
uint64_t xoshiro_next(xoshiro256pp_state_t* st);
void xoshiro_jump(xoshiro256pp_state_t* st);
void xoshiro_fill_batch(xoshiro256pp_state_t* st, uint64_t* dst, size_t count);
xoshiro256_plusplus_prng_err_t xoshiro_parallel_reduce_mt(uint64_t seed, size_t words_per_thread, uint64_t* xor_out, size_t num_threads);
xoshiro256_plusplus_prng_err_t xoshiro_verify_invariants(const xoshiro256pp_state_t* st);

#endif /* XOSHIRO256_PLUSPLUS_PRNG_INTERFACE_H */
