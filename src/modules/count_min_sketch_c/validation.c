#include "interface.h"

count_min_sketch_c_err_t count_min_sketch_c_validate(const cms_sketch_t* sk) {
    if (!sk || !sk->table) return COUNT_MIN_SKETCH_C_ERR_NULL;
    if (sk->depth == 0 || sk->width == 0) return COUNT_MIN_SKETCH_C_ERR_INVALID;
    return COUNT_MIN_SKETCH_C_OK;
}
