#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    treap_arena_t tr; treap_c_init(&tr); for (int i = 1; i <= 16; ++i) tr.root = treap_c_merge(&tr, tr.root, treap_c_new(&tr, i, (uint32_t)i * 7919u));
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += tr.pool[tr.root].sum;
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("treap_split_merge_c11 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
