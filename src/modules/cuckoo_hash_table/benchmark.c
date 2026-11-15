#define _POSIX_C_SOURCE 200809L
#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    cuckoo_map_t m;
    cuckoo_hash_table_init(&m, 8192);
    for (uint64_t i = 1; i <= 4096; ++i) cuckoo_hash_table_insert(&m, i, (int64_t)i);
    volatile int64_t sink = 0;
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (uint64_t i = 1; i <= 4096; ++i) {
        int64_t v = 0;
        if (cuckoo_hash_table_lookup(&m, i, &v)) sink += v;
    }
    clock_gettime(CLOCK_MONOTONIC, &t1);
    double ns = ((double)(t1.tv_sec - t0.tv_sec) * 1e9 + (double)(t1.tv_nsec - t0.tv_nsec)) / 4096.0;
    printf("cuckoo_hash_table lookup_ns=%.2f sink=%lld\n", ns, (long long)sink);
    cuckoo_hash_table_free(&m);
    return 0;
}
