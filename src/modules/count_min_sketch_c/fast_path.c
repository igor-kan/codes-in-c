#include "interface.h"

void count_min_sketch_c_add_standard(cms_sketch_t* sk, uint64_t item, uint64_t count) {
    if (!sk || !sk->table) return;
    for (size_t r = 0; r < sk->depth; ++r) {
        uint64_t z = item ^ (0x9E3779B97F4A7C15ULL * (uint64_t)(r + 1));
        z = (z ^ (z >> 30)) * 0xBF58476D1CE4E5B9ULL;
        z = (z ^ (z >> 27)) * 0x94D049BB133111EBULL;
        size_t col = (size_t)((z ^ (z >> 31)) % sk->width);
        sk->table[r * sk->width + col] += count;
    }
    sk->total_weight += count;
}
