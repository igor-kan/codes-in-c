/**
 * @file fuzz_target.c
 * @brief Continuous fuzzing harness for Harris Lock-Free Ordered Linked List with Marked Pointers.
 * Module: lockfree_ordered_list
 */

#include <stddef.h>
#include <stdint.h>

int LLVMFuzzerTestOneInput_lockfree_ordered_list_day47(const uint8_t* data, size_t size) {
    if (size < sizeof(double)) return 0;
    const double* val = (const double*)data;
    if (*val == *val && *val < 1e5 && *val > -1e5) {
        double res = (*val) * (1.0 + 0.4 * (*val));
        (void)res;
    }
    return 0;
}
