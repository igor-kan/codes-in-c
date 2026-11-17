#include "interface.h"
#include <stdio.h>
#include <time.h>


int main(void) {
    struct timespec t0, t1;
    splay_tree_t t; splay_init(&t); for(int i=0;i<128;++i) splay_insert(&t, (i*31)%128, i);
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        int64_t v=0; splay_find(&t, iter%128, &v); sink += v;
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("splay_tree_intrusive us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
