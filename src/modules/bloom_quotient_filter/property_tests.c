#include "interface.h"
#include <assert.h>

int main(void) {
    quotient_filter_t qf;
    qf_init(&qf);
    uint64_t keys[80];
    for (size_t i = 0; i < 80; ++i) {
        keys[i] = 10000ULL + i * 17ULL;
        assert(qf_insert(&qf, keys[i]) == BLOOM_QUOTIENT_FILTER_OK);
    }
    size_t hits = qf_parallel_probe_hits(&qf, keys, 80);
    assert(hits == 80);
    return 0;
}
