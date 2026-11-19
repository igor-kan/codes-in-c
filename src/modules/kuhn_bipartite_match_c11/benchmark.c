#include "interface.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;
    bool adj[32][32] = {0}; adj[0][0]=adj[0][1]=adj[1][0]=true; int mr[32];
    timespec_get(&t0, TIME_UTC);
    volatile int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += kuhn_max_match(2, 2, adj, mr);
    }
    timespec_get(&t1, TIME_UTC);
    double us = (double)(t1.tv_sec - t0.tv_sec) * 1e6 + (double)(t1.tv_nsec - t0.tv_nsec) * 1e-3;
    printf("kuhn_bipartite_match_c11 us=%.1f sink=%lld\n", us, (long long)sink);
    return 0;
}
