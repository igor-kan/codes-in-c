#include "interface.h"
#include <stdio.h>
#include <time.h>


int main(void) {
    struct timespec t0, t1;
    llrb_tree_t t; llrb_init(&t); for(int i=0;i<128;++i) llrb_put(&t, i, i);
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        int64_t v=0; llrb_get(&t, iter % 128, &v); sink += v;
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("red_black_tree_c11 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
