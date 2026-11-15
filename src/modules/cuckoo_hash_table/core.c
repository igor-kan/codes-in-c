#include "interface.h"
#include <stdlib.h>
#include <string.h>

static inline size_t h1(uint64_t x, size_t mask) {
    x = (x ^ (x >> 30)) * 0xBF58476D1CE4E5B9ULL;
    x = (x ^ (x >> 27)) * 0x94D049BB133111EBULL;
    return (size_t)((x ^ (x >> 31)) & mask);
}
static inline size_t h2(uint64_t x, size_t mask) {
    x = (x ^ (x >> 32)) * 0x9E3779B97F4A7C15ULL;
    x = (x ^ (x >> 29)) * 0xD2B74407B1CE6E93ULL;
    return (size_t)((x ^ (x >> 31)) & mask);
}

cuckoo_hash_table_err_t cuckoo_hash_table_init(cuckoo_map_t* m, size_t half_cap) {
    if (!m) return CUCKOO_HASH_TABLE_ERR_NULL;
    if (half_cap < 16 || (half_cap & (half_cap - 1)) != 0) return CUCKOO_HASH_TABLE_ERR_INVALID;
    m->t1 = (cuckoo_slot_t*)calloc(half_cap, sizeof(cuckoo_slot_t));
    m->t2 = (cuckoo_slot_t*)calloc(half_cap, sizeof(cuckoo_slot_t));
    if (!m->t1 || !m->t2) { free(m->t1); free(m->t2); return CUCKOO_HASH_TABLE_ERR_BOUNDS; }
    m->cap = half_cap;
    m->count = 0;
    return CUCKOO_HASH_TABLE_OK;
}

void cuckoo_hash_table_free(cuckoo_map_t* m) {
    if (!m) return;
    free(m->t1);
    free(m->t2);
    m->t1 = m->t2 = NULL;
    m->cap = m->count = 0;
}

bool cuckoo_hash_table_lookup(const cuckoo_map_t* m, uint64_t key, int64_t* out_val) {
    if (!m || !m->t1 || !m->t2 || m->cap == 0) return false;
    size_t mask = m->cap - 1;
    size_t i1 = h1(key, mask);
    if (m->t1[i1].occupied && m->t1[i1].key == key) {
        if (out_val) *out_val = m->t1[i1].value;
        return true;
    }
    size_t i2 = h2(key, mask);
    if (m->t2[i2].occupied && m->t2[i2].key == key) {
        if (out_val) *out_val = m->t2[i2].value;
        return true;
    }
    return false;
}

bool cuckoo_hash_table_remove(cuckoo_map_t* m, uint64_t key) {
    if (!m || !m->t1 || m->cap == 0) return false;
    size_t mask = m->cap - 1;
    size_t i1 = h1(key, mask);
    if (m->t1[i1].occupied && m->t1[i1].key == key) {
        m->t1[i1].occupied = 0;
        m->count--;
        return true;
    }
    size_t i2 = h2(key, mask);
    if (m->t2[i2].occupied && m->t2[i2].key == key) {
        m->t2[i2].occupied = 0;
        m->count--;
        return true;
    }
    return false;
}

cuckoo_hash_table_err_t cuckoo_hash_table_insert(cuckoo_map_t* m, uint64_t key, int64_t val) {
    if (!m || !m->t1 || !m->t2) return CUCKOO_HASH_TABLE_ERR_NULL;
    size_t mask = m->cap - 1;
    size_t i1 = h1(key, mask), i2 = h2(key, mask);
    if (m->t1[i1].occupied && m->t1[i1].key == key) { m->t1[i1].value = val; return CUCKOO_HASH_TABLE_OK; }
    if (m->t2[i2].occupied && m->t2[i2].key == key) { m->t2[i2].value = val; return CUCKOO_HASH_TABLE_OK; }

    cuckoo_slot_t cur = {key, val, 1};
    for (size_t kick = 0; kick < CUCKOO_MAX_KICKS; ++kick) {
        size_t pos1 = h1(cur.key, mask);
        if (!m->t1[pos1].occupied) { m->t1[pos1] = cur; m->count++; return CUCKOO_HASH_TABLE_OK; }
        cuckoo_slot_t evicted = m->t1[pos1];
        m->t1[pos1] = cur;
        cur = evicted;

        size_t pos2 = h2(cur.key, mask);
        if (!m->t2[pos2].occupied) { m->t2[pos2] = cur; m->count++; return CUCKOO_HASH_TABLE_OK; }
        evicted = m->t2[pos2];
        m->t2[pos2] = cur;
        cur = evicted;
    }
    return CUCKOO_HASH_TABLE_ERR_OVERFLOW; // Needs rehash if cycle reached
}
