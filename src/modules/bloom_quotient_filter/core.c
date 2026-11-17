#include "interface.h"

void qf_init(quotient_filter_t* qf) {
    for (size_t i = 0; i < QF_SLOTS; ++i) {
        qf->occupied[i] = false;
        qf->rem[i] = 0;
        qf->present[i] = false;
    }
    qf->count = 0;
}

bloom_quotient_filter_err_t qf_insert(quotient_filter_t* qf, uint64_t key) {
    if (!qf) return BLOOM_QUOTIENT_FILTER_ERR_NULL;
    if (qf->count >= QF_SLOTS - 1) return BLOOM_QUOTIENT_FILTER_ERR_BOUNDS;
    uint32_t q = 0;
    uint16_t r = qf_fast_fingerprint(key, &q);
    qf->occupied[q] = true;
    for (uint32_t step = 0; step < QF_SLOTS; ++step) {
        uint32_t idx = (q + step) & (QF_SLOTS - 1U);
        if (qf->present[idx] && qf->rem[idx] == ((uint16_t)(q << 8) | r)) {
            return BLOOM_QUOTIENT_FILTER_OK;
        }
        if (!qf->present[idx]) {
            qf->present[idx] = true;
            qf->rem[idx] = (uint16_t)((q << 8) | r);
            qf->count++;
            return BLOOM_QUOTIENT_FILTER_OK;
        }
    }
    return BLOOM_QUOTIENT_FILTER_ERR_BOUNDS;
}

bool qf_may_contain(const quotient_filter_t* qf, uint64_t key) {
    uint32_t q = 0;
    uint16_t r = qf_fast_fingerprint(key, &q);
    if (!qf->occupied[q]) return false;
    uint16_t tag = (uint16_t)((q << 8) | r);
    for (uint32_t step = 0; step < QF_SLOTS; ++step) {
        uint32_t idx = (q + step) & (QF_SLOTS - 1U);
        if (qf->present[idx] && qf->rem[idx] == tag) return true;
        if (!qf->present[idx] && !qf->occupied[idx]) return false;
    }
    return false;
}

bool qf_delete(quotient_filter_t* qf, uint64_t key) {
    uint32_t q = 0;
    uint16_t r = qf_fast_fingerprint(key, &q);
    if (!qf->occupied[q]) return false;
    uint16_t tag = (uint16_t)((q << 8) | r);
    for (uint32_t step = 0; step < QF_SLOTS; ++step) {
        uint32_t idx = (q + step) & (QF_SLOTS - 1U);
        if (qf->present[idx] && qf->rem[idx] == tag) {
            qf->present[idx] = false;
            qf->rem[idx] = 0;
            qf->count--;
            return true;
        }
    }
    return false;
}
