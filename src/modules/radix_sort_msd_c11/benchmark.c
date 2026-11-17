#include "interface.h"
#include <stdio.h>
#include <time.h>


int main(void) {
    struct timespec t0, t1;
    uint32_t arr[256];
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        for(int i=0;i<256;++i) { arr[i]=(uint32_t)(i*1664525U+1013904223U); }
msd_radix_sort(arr, 256, (msd_config_t){16});
sink += arr[iter%256];
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("radix_sort_msd_c11 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
