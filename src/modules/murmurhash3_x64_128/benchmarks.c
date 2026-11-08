/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Optimized 128-Bit MurmurHash3 Hashing Engine.
 * Module: murmurhash3_x64_128
 */

#include <stdint.h>

#define MURMURHASH3_X64_128_BENCH_ITERATIONS 100000

typedef struct murmurhash3_x64_128_bench_result {
    uint64_t total_cycles;
    double throughput_ops_sec;
} murmurhash3_x64_128_bench_result_t;
