#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    byte_ring64_t br; br64_init(&br); const uint8_t b_d[4] = {1,2,3,4}; uint8_t b_o[4];
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        br64_write(&br, b_d, 4); br64_read(&br, b_o, 4); sink += b_o[0];
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("ring_spsc_bytes_c11_d59 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
