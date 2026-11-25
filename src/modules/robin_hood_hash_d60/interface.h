#ifndef ROBIN_HOOD_HASH_D60_INTERFACE_H
#define ROBIN_HOOD_HASH_D60_INTERFACE_H

#include "types.h"
#include "errors.h"

void rh_init_d60(rh_map_t* m);
bool rh_put_d60(rh_map_t* m, uint64_t key, int64_t val);
bool rh_get_d60(const rh_map_t* m, uint64_t key, int64_t* out);

robin_hood_hash_d60_err_t robin_hood_hash_d60_validate_len(size_t n);
uint64_t robin_hood_hash_d60_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t robin_hood_hash_d60_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
robin_hood_hash_d60_err_t robin_hood_hash_d60_verify_guard(bool cond);

#endif /* ROBIN_HOOD_HASH_D60_INTERFACE_H */
