/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Vectorized Cosine Similarity and Dot Product with FMA.
 * Module: simd_cosine_similarity
 */

#include <stdint.h>

#define SIMD_COSINE_SIMILARITY_BENCH_SAMPLES 100000

typedef struct simd_cosine_similarity_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} simd_cosine_similarity_bench_stats_t;
