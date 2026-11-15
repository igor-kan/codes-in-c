#include "interface.h"

count_min_sketch_c_err_t count_min_sketch_c_merge(cms_sketch_t* dst, const cms_sketch_t* src) {
    if (!dst || !src || !dst->table || !src->table) return COUNT_MIN_SKETCH_C_ERR_NULL;
    if (dst->depth != src->depth || dst->width != src->width) return COUNT_MIN_SKETCH_C_ERR_INVALID;
    size_t n = dst->depth * dst->width;
    for (size_t i = 0; i < n; ++i) dst->table[i] += src->table[i];
    dst->total_weight += src->total_weight;
    return COUNT_MIN_SKETCH_C_OK;
}
