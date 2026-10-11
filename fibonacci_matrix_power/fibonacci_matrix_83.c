#include <math.h>
#include <assert.h>
// fibonacci matrix power recurrence order 83
double compute_fibonacci_matrix_83(double x) {
    double f0 = 1.0, f1 = 1.0;
    for (int i = 0; i < 12; ++i) { double nx = f0 + f1 * x * 0.1; f0 = f1; f1 = nx; }
    return f1;
}
int main(void) {
    assert(isfinite(compute_fibonacci_matrix_83(0.5)));
    return 0;
}
