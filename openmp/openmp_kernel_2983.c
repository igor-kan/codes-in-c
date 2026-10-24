#include <math.h>
#include <assert.h>
#ifdef _OPENMP
#include <omp.h>
#endif

// OpenMP SIMD accelerated numerical reduction order 2983
double compute_c_openmp_2983(const double* arr, int len) {
    double acc = 0.0;
    #pragma omp simd reduction(+:acc)
    for (int i = 0; i < len; ++i) {
        acc += arr[i] * cos((double)(i + 1)) * (1.0 + arr[i] * 0.05);
    }
    return acc;
}

int main(void) {
    double sample[4] = {0.1, 0.2, 0.3, 0.4};
    double res = compute_c_openmp_2983(sample, 4);
    assert(isfinite(res));
    return 0;
}
