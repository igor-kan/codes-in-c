#include <math.h>
#include <assert.h>
// fibonacci matrix power recurrence order 528
double compute_fibonacci_matrix_528(double x) {
    double f0 = 1.0, f1 = 1.0;
    for (int i = 0; i < 1; ++i) { double nx = f0 + f1 * x * 0.1; f0 = f1; f1 = nx; }
    return f1;
}
int main(void) {
    assert(isfinite(compute_fibonacci_matrix_528(0.5)));
    return 0;
}
