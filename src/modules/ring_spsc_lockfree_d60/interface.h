#ifndef RING_SPSC_LOCKFREE_D60_INTERFACE_H
#define RING_SPSC_LOCKFREE_D60_INTERFACE_H

#include "types.h"
#include "errors.h"

void spsc_init_d60(spsc_ring_t* q);
bool spsc_push_d60(spsc_ring_t* q, int64_t val);
bool spsc_pop_d60(spsc_ring_t* q, int64_t* out);
size_t spsc_size_d60(const spsc_ring_t* q);

ring_spsc_lockfree_d60_err_t ring_spsc_lockfree_d60_validate_len(size_t n);
uint64_t ring_spsc_lockfree_d60_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t ring_spsc_lockfree_d60_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
ring_spsc_lockfree_d60_err_t ring_spsc_lockfree_d60_verify_guard(bool cond);

#endif /* RING_SPSC_LOCKFREE_D60_INTERFACE_H */
