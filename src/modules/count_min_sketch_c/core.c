#include "interface.h"
#include <stdlib.h>

static inline size_t row_hash(uint64_t item, size_t row, size_t width) {
    uint64_t z = item ^ (0x9E3779B97F4A7C15ULL * (uint64_t)(row + 1));
    z = (z ^ (z >> 30)) * 0xBF58476D1CE4E5B9ULL;
    z = (z ^ (z >> 27)) * 0x94D049BB133111EBULL;
    return (size_t)((z ^ (z >> 31)) % width);
}

count_min_sketch_c_err_t count_min_sketch_c_init(cms_sketch_t* sk, size_t depth, size_t width) {
    if (!sk) return COUNT_MIN_SKETCH_C_ERR_NULL;
    if (depth == 0 || width == 0) return COUNT_MIN_SKETCH_C_ERR_INVALID;
    sk->table = (uint64_t*)calloc(depth * width, sizeof(uint64_t));
    if (!sk->table) return COUNT_MIN_SKETCH_C_ERR_BOUNDS;
    sk->depth = depth;
    sk->width = width;
    sk->total_weight = 0;
    return COUNT_MIN_SKETCH_C_OK;
}

void count_min_sketch_c_free(cms_sketch_t* sk) {
    if (!sk) return;
    free(sk->table);
    sk->table = NULL;
    sk->depth = sk->width = 0;
}

void count_min_sketch_c_add_conservative(cms_sketch_t* sk, uint64_t item, uint64_t count) {
    if (!sk || !sk->table) return;
    uint64_t min_v = UINT64_MAX;
    for (size_t r = 0; r < sk->depth; ++r) {
        size_t col = row_hash(item, r, sk->width);
        uint64_t v = sk->table[r * sk->width + col];
        if (v < min_v) min_v = v;
    }
    uint64_t target = min_v + count;
    for (size_t r = 0; r < sk->depth; ++r) {
        size_t col = row_hash(item, r, sk->width);
        uint64_t* cell = &sk->table[r * sk->width + col];
        if (*cell < target) *cell = target;
    }
    sk->total_weight += count;
}

uint64_t count_min_sketch_c_query(const cms_sketch_t* sk, uint64_t item) {
    if (!sk || !sk->table) return 0;
    uint64_t min_v = UINT64_MAX;
    for (size_t r = 0; r < sk->depth; ++r) {
        size_t col = row_hash(item, r, sk->width);
        uint64_t v = sk->table[r * sk->width + col];
        if (v < min_v) min_v = v;
    }
    return min_v;
}
