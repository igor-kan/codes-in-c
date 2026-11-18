#include "interface.h"
#include <math.h>
#include <string.h>

static uint64_t gear_table_val(uint8_t b) {
    uint64_t x = (uint64_t)(b + 1U) * 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    return x ^ (x >> 27);
}
size_t gear_cdc_split(const uint8_t* buf, size_t n, size_t min_len, size_t max_len, uint64_t mask, cdc_chunk_t* out, size_t max_chunks) {
    size_t start = 0, cnt = 0;
    uint64_t fp = 0;
    for (size_t i = 0; i < n && cnt < max_chunks; ++i) {
        fp = (fp << 1) + gear_table_val(buf[i]);
        size_t cur_len = i - start + 1;
        if ((cur_len >= min_len && (fp & mask) == 0) || cur_len >= max_len || i + 1 == n) {
            out[cnt++] = (cdc_chunk_t){start, cur_len};
            start = i + 1;
            fp = 0;
        }
    }
    return cnt;
}
