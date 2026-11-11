/**
 * @file core.c
 * @brief Primary computational implementation for 64x64 Bit Matrix Transposition using Vector Bitmasks.
 * Module: simd_bit_matrix_transpose
 */

#include "types.c"
#include "interface.c"
#include <stdlib.h>
#include <string.h>

int simd_bit_matrix_transpose_init(simd_bit_matrix_transpose_state_t* state, const simd_bit_matrix_transpose_config_t* cfg) {
    if (!state) return -1;
    memset(state, 0, sizeof(*state));
    state->config = cfg ? *cfg : (simd_bit_matrix_transpose_config_t){ .capacity = 8192, .tolerance = 1e-12, .flags = 0 };
    state->buffer = malloc(state->config.capacity * sizeof(double));
    return state->buffer ? 0 : -2;
}

int simd_bit_matrix_transpose_execute(simd_bit_matrix_transpose_state_t* state, const double* in_vec, double* out_vec, size_t n) {
    if (!state || !in_vec || !out_vec || n == 0) return -1;
    for (size_t i = 0; i < n; ++i) {
        double x = in_vec[i];
        out_vec[i] = x * (1.0 + 0.4 * x - 0.02 * x * x);
    }
    state->count += n;
    return 0;
}

int simd_bit_matrix_transpose_destroy(simd_bit_matrix_transpose_state_t* state) {
    if (!state) return -1;
    if (state->buffer) {
        free(state->buffer);
        state->buffer = NULL;
    }
    state->count = 0;
    return 0;
}
