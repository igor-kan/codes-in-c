#include "interface.h"
#include <assert.h>

int main(void) {
    cms_sketch_t sk;
    assert(count_min_sketch_c_init(&sk, 4, 256) == COUNT_MIN_SKETCH_C_OK);
    for (int i = 0; i < 40; ++i) count_min_sketch_c_add_conservative(&sk, 777ULL, 1);
    for (uint64_t k = 1; k <= 100; ++k) count_min_sketch_c_add_conservative(&sk, k, 1);
    uint64_t est = count_min_sketch_c_query(&sk, 777ULL);
    assert(est >= 40 && est <= 43);
    assert(count_min_sketch_c_check_invariants(&sk, 777ULL, 40) == COUNT_MIN_SKETCH_C_OK);
    count_min_sketch_c_free(&sk);
    return 0;
}
