#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    uint16_t bu[2]; size_t bnu = 0;
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        cp_to_utf16(0x1F600u, bu, &bnu); sink += bu[0];
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("utf16_surrogate_c11_d59 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
