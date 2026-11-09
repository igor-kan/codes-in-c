/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for DMA-Friendly Circular Ring Buffer with Barriers.
 * Module: circular_dma_ring
 */

#include <stdint.h>

#define CIRCULAR_DMA_RING_BENCH_SAMPLES 100000

typedef struct circular_dma_ring_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} circular_dma_ring_bench_stats_t;
