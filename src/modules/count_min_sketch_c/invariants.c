#include "interface.h"

count_min_sketch_c_err_t count_min_sketch_c_check_invariants(const cms_sketch_t* sk, uint64_t item, uint64_t known_min) {
    if (count_min_sketch_c_validate(sk) != COUNT_MIN_SKETCH_C_OK) return COUNT_MIN_SKETCH_C_ERR_INVALID;
    uint64_t est = count_min_sketch_c_query(sk, item);
    if (est < known_min || est > sk->total_weight) return COUNT_MIN_SKETCH_C_ERR_INVARIANT;
    return COUNT_MIN_SKETCH_C_OK;
}
