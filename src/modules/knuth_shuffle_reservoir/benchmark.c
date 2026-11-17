#include "interface.h"
#include <stdio.h>
#include <time.h>


int main(void) {
    struct timespec t0, t1;
    int64_t buf[128]; for(int i=0;i<128;++i) buf[i]=i;
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        fisher_yates_shuffle(buf, 128, (uint64_t)(iter + 1)); sink += buf[iter % 128];
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("knuth_shuffle_reservoir us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
