#include "interface.h"
#include <math.h>
#include <string.h>

static size_t rh_hash(uint64_t x) {
    x ^= x >> 33; x *= 0xff51afd7ed558ccdULL;
    x ^= x >> 33; return (size_t)(x & (RH_CAP - 1U));
}
void rh_init_d60(rh_map_t* m) {
    memset(m, 0, sizeof(*m));
}
bool rh_put_d60(rh_map_t* m, uint64_t key, int64_t val) {
    if (m->count >= RH_CAP - 2U) return false;
    size_t idx = rh_hash(key);
    size_t psl = 0;
    while (m->used[idx]) {
        if (m->keys[idx] == key) { m->vals[idx] = val; return true; }
        size_t home = rh_hash(m->keys[idx]);
        size_t cur_psl = (idx + RH_CAP - home) & (RH_CAP - 1U);
        if (cur_psl < psl) {
            uint64_t tk = m->keys[idx]; int64_t tv = m->vals[idx];
            m->keys[idx] = key; m->vals[idx] = val;
            key = tk; val = tv; psl = cur_psl;
        }
        idx = (idx + 1U) & (RH_CAP - 1U);
        ++psl;
    }
    m->keys[idx] = key; m->vals[idx] = val; m->used[idx] = 1;
    m->count += 1U;
    return true;
}
bool rh_get_d60(const rh_map_t* m, uint64_t key, int64_t* out) {
    size_t idx = rh_hash(key);
    size_t psl = 0;
    while (m->used[idx]) {
        if (m->keys[idx] == key) { *out = m->vals[idx]; return true; }
        size_t home = rh_hash(m->keys[idx]);
        size_t cur_psl = (idx + RH_CAP - home) & (RH_CAP - 1U);
        if (cur_psl < psl) return false;
        idx = (idx + 1U) & (RH_CAP - 1U);
        ++psl;
    }
    return false;
}
