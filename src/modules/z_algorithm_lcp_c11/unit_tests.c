#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(z_algorithm_lcp_c11_validate_len(1) == Z_ALGORITHM_LCP_C11_OK);
    size_t hits[16] = {0};
    size_t c = z_find_occurrences("aba", "ababaababa", hits, 16);
    assert(c == 4 && hits[0] == 0 && hits[1] == 2 && hits[2] == 5 && hits[3] == 7);
    assert(z_algorithm_lcp_c11_verify_guard(true) == Z_ALGORITHM_LCP_C11_OK);
    return 0;
}
