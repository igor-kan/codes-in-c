/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for FNV-1a 64-Bit Fast Non-Cryptographic Hash Engine.
 * Module: hash_fnv1a_64
 */

#include <stdint.h>

#define HASH_FNV1A_64_BENCH_ITERATIONS 100000

typedef struct hash_fnv1a_64_bench_metrics {
    uint64_t tsc_cycles;
    double ops_per_sec;
} hash_fnv1a_64_bench_metrics_t;
