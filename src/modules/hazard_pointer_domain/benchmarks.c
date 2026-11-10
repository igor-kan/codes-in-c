/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Hazard Pointer Domain Manager for Lock-Free Memory.
 * Module: hazard_pointer_domain
 */

#include <stdint.h>

#define HAZARD_POINTER_DOMAIN_BENCH_SAMPLES 100000

typedef struct hazard_pointer_domain_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} hazard_pointer_domain_bench_stats_t;
