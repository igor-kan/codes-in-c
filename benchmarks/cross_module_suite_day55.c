/* Cross-module integration & throughput driver for Day 55 `codes-in-c` modules. */
#include "../src/modules/stoer_wagner_mincut_c11/interface.h"
#include "../src/modules/zkw_bottom_up_segtree_c/interface.h"
#include "../src/modules/kuhn_bipartite_match_c11/interface.h"
#include "../src/modules/z_algorithm_lcp_c11/interface.h"
#include "../src/modules/fenwick_order_stat_c11/interface.h"
#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint64_t sample[4] = {11ULL, 22ULL, 33ULL, 44ULL};
    uint64_t acc = 0ULL;
    if (stoer_wagner_mincut_c11_validate_len(4) != STOER_WAGNER_MINCUT_C11_OK) return 1;
    acc ^= stoer_wagner_mincut_c11_fast_fold_u64(sample, 4);
    if (zkw_bottom_up_segtree_c_validate_len(4) != ZKW_BOTTOM_UP_SEGTREE_C_OK) return 1;
    acc ^= zkw_bottom_up_segtree_c_fast_fold_u64(sample, 4);
    if (kuhn_bipartite_match_c11_validate_len(4) != KUHN_BIPARTITE_MATCH_C11_OK) return 1;
    acc ^= kuhn_bipartite_match_c11_fast_fold_u64(sample, 4);
    if (z_algorithm_lcp_c11_validate_len(4) != Z_ALGORITHM_LCP_C11_OK) return 1;
    acc ^= z_algorithm_lcp_c11_fast_fold_u64(sample, 4);
    if (fenwick_order_stat_c11_validate_len(4) != FENWICK_ORDER_STAT_C11_OK) return 1;
    acc ^= fenwick_order_stat_c11_fast_fold_u64(sample, 4);
    printf("codes-in-c day55 suite ok acc=%llu\n", (unsigned long long)acc);
    return acc != 0ULL ? 0 : 1;
}
