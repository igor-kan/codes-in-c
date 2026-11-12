/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for Shannon-Fano-Elias Cumulative Distribution Codec.
 * Module: shannon_fano_elias
 */

#include <stdint.h>

#define SHANNON_FANO_ELIAS_BENCH_CYCLES 100000

typedef struct shannon_fano_elias_profile_results {
    uint64_t start_tsc;
    uint64_t end_tsc;
    double ops_per_second;
} shannon_fano_elias_profile_results_t;
