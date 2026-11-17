#include "interface.h"
#include <string.h>

boyer_moore_horspool_c_err_t bmh_compile(const uint8_t* pat, size_t m, bmh_table_t* out) {
    if (!pat || !out) return BOYER_MOORE_HORSPOOL_C_ERR_NULL;
    if (m == 0) return BOYER_MOORE_HORSPOOL_C_ERR_INVALID;
    for (size_t i = 0; i < 256; ++i) out->skip[i] = m;
    for (size_t i = 0; i + 1 < m; ++i) out->skip[pat[i]] = m - 1 - i;
    out->pat_len = m;
    return BOYER_MOORE_HORSPOOL_C_OK;
}

size_t bmh_find_all(const uint8_t* text, size_t n, const uint8_t* pat, const bmh_table_t* tbl, size_t* out_pos, size_t max_out) {
    size_t m = tbl->pat_len;
    if (n < m) return 0;
    size_t found = 0, i = 0;
    while (i <= n - m) {
        size_t j = m - 1;
        while (text[i + j] == pat[j]) {
            if (j == 0) {
                if (found < max_out && out_pos) out_pos[found] = i;
                found++;
                break;
            }
            --j;
        }
        i += tbl->skip[text[i + m - 1]];
    }
    return found;
}
