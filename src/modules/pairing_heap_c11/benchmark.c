#include "interface.h"
#include <stdio.h>
#include <time.h>


int main(void) {
    struct timespec t0, t1;
    int64_t buf[64];
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        for(int i=0;i<64;++i) { buf[i]=(i*29)%64; }
ph_fast_sort(buf, 64);
sink += buf[iter % 64];
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("pairing_heap_c11 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
