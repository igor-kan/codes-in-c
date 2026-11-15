#include "interface.h"
#include <stdlib.h>
#include <string.h>

static const uint8_t* g_rot_src = NULL;
static size_t g_rot_n = 0;

static int cmp_rot(const void* a, const void* b) {
    size_t ia = *(const size_t*)a;
    size_t ib = *(const size_t*)b;
    for (size_t k = 0; k < g_rot_n; ++k) {
        uint8_t ca = g_rot_src[(ia + k) % g_rot_n];
        uint8_t cb = g_rot_src[(ib + k) % g_rot_n];
        if (ca != cb) return (ca < cb) ? -1 : 1;
    }
    return 0;
}

burrows_wheeler_bwt_err_t burrows_wheeler_bwt_forward(const uint8_t* src, size_t n, uint8_t* out_bwt, size_t* primary_idx) {
    if (!src || !out_bwt || !primary_idx) return BURROWS_WHEELER_BWT_ERR_NULL;
    if (n == 0) { *primary_idx = 0; return BURROWS_WHEELER_BWT_OK; }
    size_t* idx = (size_t*)malloc(n * sizeof(size_t));
    if (!idx) return BURROWS_WHEELER_BWT_ERR_BOUNDS;
    for (size_t i = 0; i < n; ++i) idx[i] = i;
    g_rot_src = src;
    g_rot_n = n;
    qsort(idx, n, sizeof(size_t), cmp_rot);
    for (size_t i = 0; i < n; ++i) {
        size_t s = idx[i];
        out_bwt[i] = src[(s + n - 1) % n];
        if (s == 0) *primary_idx = i;
    }
    free(idx);
    return BURROWS_WHEELER_BWT_OK;
}

burrows_wheeler_bwt_err_t burrows_wheeler_bwt_inverse(const uint8_t* bwt, size_t n, size_t primary_idx, uint8_t* out_src) {
    if (!bwt || !out_src) return BURROWS_WHEELER_BWT_ERR_NULL;
    if (n == 0) return BURROWS_WHEELER_BWT_OK;
    if (primary_idx >= n) return BURROWS_WHEELER_BWT_ERR_BOUNDS;
    size_t counts[256] = {0};
    for (size_t i = 0; i < n; ++i) counts[bwt[i]]++;
    size_t cum[256];
    size_t sum = 0;
    for (size_t c = 0; c < 256; ++c) {
        cum[c] = sum;
        sum += counts[c];
    }
    size_t* lf = (size_t*)malloc(n * sizeof(size_t));
    if (!lf) return BURROWS_WHEELER_BWT_ERR_BOUNDS;
    size_t seen[256] = {0};
    for (size_t i = 0; i < n; ++i) {
        uint8_t ch = bwt[i];
        lf[i] = cum[ch] + seen[ch]++;
    }
    size_t cur = primary_idx;
    for (size_t i = n; i > 0; --i) {
        out_src[i - 1] = bwt[cur];
        cur = lf[cur];
    }
    free(lf);
    return BURROWS_WHEELER_BWT_OK;
}

burrows_wheeler_bwt_err_t burrows_wheeler_bwt_mtf_encode(const uint8_t* src, size_t n, uint8_t* out) {
    if (!src || !out) return BURROWS_WHEELER_BWT_ERR_NULL;
    uint8_t dict[256];
    for (size_t i = 0; i < 256; ++i) dict[i] = (uint8_t)i;
    for (size_t i = 0; i < n; ++i) {
        uint8_t target = src[i];
        size_t pos = 0;
        while (dict[pos] != target) pos++;
        out[i] = (uint8_t)pos;
        if (pos > 0) {
            memmove(dict + 1, dict, pos);
            dict[0] = target;
        }
    }
    return BURROWS_WHEELER_BWT_OK;
}

burrows_wheeler_bwt_err_t burrows_wheeler_bwt_mtf_decode(const uint8_t* src, size_t n, uint8_t* out) {
    if (!src || !out) return BURROWS_WHEELER_BWT_ERR_NULL;
    uint8_t dict[256];
    for (size_t i = 0; i < 256; ++i) dict[i] = (uint8_t)i;
    for (size_t i = 0; i < n; ++i) {
        uint8_t idx = src[i];
        uint8_t ch = dict[idx];
        out[i] = ch;
        if (idx > 0) {
            memmove(dict + 1, dict, idx);
            dict[0] = ch;
        }
    }
    return BURROWS_WHEELER_BWT_OK;
}
