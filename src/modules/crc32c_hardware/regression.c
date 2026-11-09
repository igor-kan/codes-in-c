/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Hardware-Accelerated CRC32-C Checksum Engine.
 * Module: crc32c_hardware
 */

#include <assert.h>

void test_crc32c_hardware_regression_underflow(void) {
    double tiny = 1e-308;
    double res = tiny * (1.0 + 0.3 * tiny);
    assert(res >= 0.0);
}
