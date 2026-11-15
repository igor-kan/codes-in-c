#include "interface.h"
#include <assert.h>
#include <math.h>

int main(void) {
    double a[8] = {5.5, -2.0, 9.25, 0.0, 1.5, -2.0, 100.0, 3.0};
    introsort_metrics_t m;
    assert(introsort_heap_guard_sort(a, 8, &m) == INTROSORT_HEAP_GUARD_OK);
    assert(introsort_heap_guard_verify(a, 8) == INTROSORT_HEAP_GUARD_OK);
    assert(a[0] == -2.0 && a[1] == -2.0 && a[7] == 100.0);

    double bad[2] = {1.0, NAN};
    assert(introsort_heap_guard_sort(bad, 2, &m) == INTROSORT_HEAP_GUARD_ERR_INVALID);
    return 0;
}
