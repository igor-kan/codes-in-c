#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(robin_hood_hash_d60_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    rh_map_t m; rh_init_d60(&m);
    for (uint64_t k = 1; k <= 30; ++k) assert(rh_put_d60(&m, k * 7ULL, (int64_t)(k * k)));
    for (uint64_t k = 1; k <= 30; ++k) {
        int64_t out = 0;
        assert(rh_get_d60(&m, k * 7ULL, &out) && out == (int64_t)(k * k));
    }
    int64_t miss = 0;
    assert(!rh_get_d60(&m, 99999ULL, &miss));
    return 0;
}
