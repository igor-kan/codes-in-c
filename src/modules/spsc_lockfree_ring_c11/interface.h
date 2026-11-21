#ifndef SPSC_LOCKFREE_RING_C11_INTERFACE_H
#define SPSC_LOCKFREE_RING_C11_INTERFACE_H

#include "types.h"
#include "errors.h"

void spsc16_init(spsc_ring16_t *q);
int spsc16_push(spsc_ring16_t *q, uint64_t v);
int spsc16_pop(spsc_ring16_t *q, uint64_t *out);
uint32_t spsc16_len(const spsc_ring16_t *q);

spsc_lockfree_ring_c11_err_t spsc_lockfree_ring_c11_validate_len(size_t n);
uint64_t spsc_lockfree_ring_c11_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t spsc_lockfree_ring_c11_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
spsc_lockfree_ring_c11_err_t spsc_lockfree_ring_c11_verify_guard(bool cond);

#endif /* SPSC_LOCKFREE_RING_C11_INTERFACE_H */
