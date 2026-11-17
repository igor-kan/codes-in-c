#include "interface.h"
#include <assert.h>

int main(void) {
    const uint8_t* txt = (const uint8_t*)"HERE IS A SIMPLE EXAMPLE";
    const uint8_t* pat = (const uint8_t*)"EXAMPLE";
    bmh_table_t tbl;
    assert(bmh_compile(pat, 7, &tbl) == BOYER_MOORE_HORSPOOL_C_OK);
    size_t hits[4] = {0};
    size_t c = bmh_find_all(txt, 24, pat, &tbl, hits, 4);
    assert(c == 1 && hits[0] == 17);
    assert(bmh_verify_hits(txt, pat, 7, hits, c) == BOYER_MOORE_HORSPOOL_C_OK);
    return 0;
}
