/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Hardware-Accelerated CRC32-C Checksum Engine.
 * Module: crc32c_hardware
 */

#include <stdint.h>

#define CRC32C_HARDWARE_BENCH_SAMPLES 100000

typedef struct crc32c_hardware_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} crc32c_hardware_bench_stats_t;
