#include "interface.h"
#include <assert.h>

int main(void) {
    quotient_filter_t qf;
    qf_init(&qf);
    for (uint64_t k = 100; k < 140; ++k) assert(qf_insert(&qf, k) == BLOOM_QUOTIENT_FILTER_OK);
    for (uint64_t k = 100; k < 140; ++k) assert(qf_may_contain(&qf, k));
    assert(qf_delete(&qf, 115));
    assert(!qf_may_contain(&qf, 115));
    assert(qf_may_contain(&qf, 116));
    assert(qf_verify_count(&qf) == BLOOM_QUOTIENT_FILTER_OK);
    return 0;
}
