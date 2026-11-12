/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for PCG-XSH-RR 64-Bit Statistical Random Number Generator.
 * Module: pcg64_random
 */

#include <stdint.h>

#define PCG64_RANDOM_BENCH_CYCLES 100000

typedef struct pcg64_random_profile_results {
    uint64_t start_tsc;
    uint64_t end_tsc;
    double ops_per_second;
} pcg64_random_profile_results_t;
