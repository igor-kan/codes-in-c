#include "interface.h"
#include <assert.h>

int main(void) {
    int64_t keys[16] = {5, 12, 3, 8, 20, 1, 9, 14, 100, 50, 2, 7, 11, 30, 4, 6};
    int64_t sums[2] = {0, 0};
    splay_parallel_queries(keys, 16, sums);
    assert(sums[0] == (5+12+3+8+20+1+9+14) * 2);
    assert(sums[1] == (100+50+2+7+11+30+4+6) * 2);
    return 0;
}
