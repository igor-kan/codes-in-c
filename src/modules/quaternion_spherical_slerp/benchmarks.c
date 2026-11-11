/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Spherical Linear Interpolation (SLERP) for Quaternions.
 * Module: quaternion_spherical_slerp
 */

#include <stdint.h>

#define QUATERNION_SPHERICAL_SLERP_BENCH_SAMPLES 100000

typedef struct quaternion_spherical_slerp_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} quaternion_spherical_slerp_bench_stats_t;
