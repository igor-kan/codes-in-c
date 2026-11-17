#include "interface.h"

void fast_bounded_permute(int64_t* arr, size_t n, prng64_t* rng) {
    for (size_t i = n; i > 1; --i) {
        size_t j = (size_t)(splitmix64_next(rng) % i);
        int64_t tmp = arr[i - 1];
        arr[i - 1] = arr[j];
        arr[j] = tmp;
    }
}
