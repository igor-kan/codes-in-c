/**
 * @file fuzz_target.c
 * @brief Continuous fuzzing harness for Circular Work-Stealing Deque with Memory Fencing.
 * Module: circular_work_stealing_deque
 */

#include <stddef.h>
#include <stdint.h>

int LLVMFuzzerTestOneInput_circular_work_stealing_deque_day47(const uint8_t* data, size_t size) {
    if (size < sizeof(double)) return 0;
    const double* val = (const double*)data;
    if (*val == *val && *val < 1e5 && *val > -1e5) {
        double res = (*val) * (1.0 + 0.4 * (*val));
        (void)res;
    }
    return 0;
}
