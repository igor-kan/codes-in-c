#ifndef SKIP_LIST_PROBABILISTIC_INTERFACE_H
#define SKIP_LIST_PROBABILISTIC_INTERFACE_H

#include "types.h"
#include "errors.h"

skip_list_probabilistic_err_t sl_init(skiplist_t* sl, uint32_t seed);
void sl_destroy(skiplist_t* sl);
skip_list_probabilistic_err_t sl_insert(skiplist_t* sl, int64_t key, int64_t value);
bool sl_find(const skiplist_t* sl, int64_t key, int64_t* value_out);
bool sl_delete(skiplist_t* sl, int64_t key);
skip_list_probabilistic_err_t sl_validate_state(const skiplist_t* sl);
skip_list_probabilistic_err_t sl_batch_search_mt(const skiplist_t* sl, const int64_t* keys, int64_t* out_vals, size_t n_keys, size_t num_threads);
skip_list_probabilistic_err_t sl_verify_invariants(const skiplist_t* sl);

#endif /* SKIP_LIST_PROBABILISTIC_INTERFACE_H */
