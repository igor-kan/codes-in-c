#include "interface.h"
#include <stdio.h>
#include <time.h>


int main(void) {
    struct timespec t0, t1;
    quotient_filter_t qf; qf_init(&qf); for(uint64_t i=0;i<120;++i) qf_insert(&qf, i);
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += qf_may_contain(&qf, (uint64_t)(iter % 200)) ? 1 : 0;
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("bloom_quotient_filter us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
