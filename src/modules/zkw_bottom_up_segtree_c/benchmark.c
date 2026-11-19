#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    zkw_tree_t z; zkw_init(&z); for (int i = 0; i < 8; ++i) zkw_set(&z, i, i + 1);
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += zkw_sum(&z, 1, 6);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("zkw_bottom_up_segtree_c us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
