#ifndef COUNT_MIN_SKETCH_C_INTERFACE_H
#define COUNT_MIN_SKETCH_C_INTERFACE_H

#include "types.h"
#include "errors.h"

count_min_sketch_c_err_t count_min_sketch_c_init(cms_sketch_t* sk, size_t depth, size_t width);
void count_min_sketch_c_free(cms_sketch_t* sk);
void count_min_sketch_c_add_conservative(cms_sketch_t* sk, uint64_t item, uint64_t count);
uint64_t count_min_sketch_c_query(const cms_sketch_t* sk, uint64_t item);
count_min_sketch_c_err_t count_min_sketch_c_validate(const cms_sketch_t* sk);
void count_min_sketch_c_add_standard(cms_sketch_t* sk, uint64_t item, uint64_t count);
count_min_sketch_c_err_t count_min_sketch_c_merge(cms_sketch_t* dst, const cms_sketch_t* src);
count_min_sketch_c_err_t count_min_sketch_c_check_invariants(const cms_sketch_t* sk, uint64_t item, uint64_t known_min);

#endif /* COUNT_MIN_SKETCH_C_INTERFACE_H */
