#include "interface.h"

bloom_quotient_filter_err_t qf_verify_count(const quotient_filter_t* qf) {
    if (!qf) return BLOOM_QUOTIENT_FILTER_ERR_NULL;
    size_t c = 0;
    for (size_t i = 0; i < QF_SLOTS; ++i) {
        if (qf->present[i]) c++;
    }
    return c == qf->count ? BLOOM_QUOTIENT_FILTER_OK : BLOOM_QUOTIENT_FILTER_ERR_INVARIANT;
}
