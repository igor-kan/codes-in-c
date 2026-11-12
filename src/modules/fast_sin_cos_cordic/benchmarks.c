/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for CORDIC Shift-and-Add Trigonometric Vector Rotation.
 * Module: fast_sin_cos_cordic
 */

#include <stdint.h>

#define FAST_SIN_COS_CORDIC_BENCH_CYCLES 100000

typedef struct fast_sin_cos_cordic_profile_results {
    uint64_t start_tsc;
    uint64_t end_tsc;
    double ops_per_second;
} fast_sin_cos_cordic_profile_results_t;
