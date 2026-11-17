#include "interface.h"
#include <assert.h>

int main(void) {
    const uint8_t* txt = (const uint8_t*)"abracadabra_abracadabra";
    const uint8_t* pat = (const uint8_t*)"abra";
    size_t hits[8] = {0};
    bmh_table_t tbl;
    assert(bmh_compile(pat, 4, &tbl) == BOYER_MOORE_HORSPOOL_C_OK);
    size_t cnt = bmh_find_all(txt, 23, pat, &tbl, hits, 8);
    assert(cnt == 4);
    assert(bmh_parallel_count(txt, 23, pat, 4) == 4);
    assert(bmh_verify_hits(txt, pat, 4, hits, cnt) == BOYER_MOORE_HORSPOOL_C_OK);
    return 0;
}
