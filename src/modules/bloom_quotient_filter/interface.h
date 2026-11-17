#ifndef BLOOM_QUOTIENT_FILTER_INTERFACE_H
#define BLOOM_QUOTIENT_FILTER_INTERFACE_H

#include "types.h"
#include "errors.h"

void qf_init(quotient_filter_t* qf);
bloom_quotient_filter_err_t qf_insert(quotient_filter_t* qf, uint64_t key);
bool qf_may_contain(const quotient_filter_t* qf, uint64_t key);
bool qf_delete(quotient_filter_t* qf, uint64_t key);
bloom_quotient_filter_err_t qf_validate(const quotient_filter_t* qf);
uint16_t qf_fast_fingerprint(uint64_t key, uint32_t* out_quotient);
size_t qf_parallel_probe_hits(const quotient_filter_t* qf, const uint64_t* keys, size_t n);
bloom_quotient_filter_err_t qf_verify_count(const quotient_filter_t* qf);

#endif /* BLOOM_QUOTIENT_FILTER_INTERFACE_H */
