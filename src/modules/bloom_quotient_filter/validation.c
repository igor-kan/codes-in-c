#include "interface.h"

bloom_quotient_filter_err_t qf_validate(const quotient_filter_t* qf) {
    if (!qf) return BLOOM_QUOTIENT_FILTER_ERR_NULL;
    if (qf->count > QF_SLOTS) return BLOOM_QUOTIENT_FILTER_ERR_BOUNDS;
    return BLOOM_QUOTIENT_FILTER_OK;
}
