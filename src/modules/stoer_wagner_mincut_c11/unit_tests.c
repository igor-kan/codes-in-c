#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(stoer_wagner_mincut_c11_validate_len(1) == STOER_WAGNER_MINCUT_C11_OK);
    int64_t g[16][16] = {0};
    g[0][1]=g[1][0]=2; g[0][4]=g[4][0]=3; g[1][2]=g[2][1]=3;
    g[1][4]=g[4][1]=2; g[2][3]=g[3][2]=4; g[3][4]=g[4][3]=1;
    assert(sw_mincut_c(5, g) == 4);
    assert(stoer_wagner_mincut_c11_verify_guard(true) == STOER_WAGNER_MINCUT_C11_OK);
    return 0;
}
