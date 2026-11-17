#include "interface.h"
#include <stdio.h>
#include <time.h>


int main(void) {
    struct timespec t0, t1;
    const uint8_t* t=(const uint8_t*)"needle_in_a_haystack_needle_again"; bmh_table_t tbl; bmh_compile((const uint8_t*)"needle", 6, &tbl);
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += bmh_fast_first(t, 33, (const uint8_t*)"needle", &tbl);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("boyer_moore_horspool_c us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
