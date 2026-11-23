#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    const uint8_t b_m[4] = {1,2,3,4}; fnv1a_stream_t b_st; fnv1a_init(&b_st);
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        fnv1a_update(&b_st, b_m, 4); sink += b_st.state;
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("fnv1a_64_mix_c11_d58 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
