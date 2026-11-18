#ifndef CONSISTENT_HASH_RING_C11_INTERFACE_H
#define CONSISTENT_HASH_RING_C11_INTERFACE_H

#include "types.h"
#include "errors.h"

void hring_init(hash_ring_t* r);
void hring_add_node(hash_ring_t* r, int32_t node_id, int32_t replicas);
int32_t hring_locate(const hash_ring_t* r, uint64_t key);

consistent_hash_ring_c11_err_t consistent_hash_ring_c11_validate_len(size_t n);
uint64_t consistent_hash_ring_c11_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t consistent_hash_ring_c11_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
consistent_hash_ring_c11_err_t consistent_hash_ring_c11_verify_guard(bool cond);

#endif /* CONSISTENT_HASH_RING_C11_INTERFACE_H */
