#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    hash_ring_t ring; hring_init(&ring); hring_add_node(&ring, 1, 8); hring_add_node(&ring, 2, 8);
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += hring_locate(&ring, (uint64_t)iter);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("consistent_hash_ring_c11 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
