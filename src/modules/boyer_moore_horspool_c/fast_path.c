#include "interface.h"

ptrdiff_t bmh_fast_first(const uint8_t* text, size_t n, const uint8_t* pat, const bmh_table_t* tbl) {
    size_t pos = 0;
    if (bmh_find_all(text, n, pat, tbl, &pos, 1) > 0) return (ptrdiff_t)pos;
    return -1;
}
