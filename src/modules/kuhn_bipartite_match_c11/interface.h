#ifndef KUHN_BIPARTITE_MATCH_C11_INTERFACE_H
#define KUHN_BIPARTITE_MATCH_C11_INTERFACE_H

#include "types.h"
#include "errors.h"

int kuhn_max_match(int nl, int nr, const bool adj[32][32], int out_r[32]);

kuhn_bipartite_match_c11_err_t kuhn_bipartite_match_c11_validate_len(size_t n);
uint64_t kuhn_bipartite_match_c11_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t kuhn_bipartite_match_c11_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
kuhn_bipartite_match_c11_err_t kuhn_bipartite_match_c11_verify_guard(bool cond);

#endif /* KUHN_BIPARTITE_MATCH_C11_INTERFACE_H */
