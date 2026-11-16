#include "interface.h"
#include <stdlib.h>

static uint32_t xorshift32(uint32_t* st) {
    uint32_t x = *st ? *st : 0xA5A55A5AU;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    *st = x;
    return x;
}

static int random_level(skiplist_t* sl) {
    int lvl = 1;
    while (lvl < SKIPLIST_MAX_LEVEL && (xorshift32(&sl->rng) & 1U)) ++lvl;
    return lvl;
}

skip_list_probabilistic_err_t sl_init(skiplist_t* sl, uint32_t seed) {
    if (!sl) return SKIP_LIST_PROBABILISTIC_ERR_NULL;
    sl->head = (sl_node_t*)calloc(1, sizeof(sl_node_t));
    if (!sl->head) return SKIP_LIST_PROBABILISTIC_ERR_NULL;
    sl->head->level = SKIPLIST_MAX_LEVEL;
    sl->max_level = 1;
    sl->count = 0;
    sl->rng = seed ? seed : 0x1234567U;
    return SKIP_LIST_PROBABILISTIC_OK;
}

void sl_destroy(skiplist_t* sl) {
    if (!sl || !sl->head) return;
    sl_node_t* cur = sl->head->next[0];
    while (cur) {
        sl_node_t* nxt = cur->next[0];
        free(cur);
        cur = nxt;
    }
    free(sl->head);
    sl->head = NULL;
    sl->count = 0;
}

skip_list_probabilistic_err_t sl_insert(skiplist_t* sl, int64_t key, int64_t value) {
    if (!sl || !sl->head) return SKIP_LIST_PROBABILISTIC_ERR_NULL;
    sl_node_t* update[SKIPLIST_MAX_LEVEL];
    sl_node_t* x = sl->head;
    for (int i = sl->max_level - 1; i >= 0; --i) {
        while (x->next[i] && x->next[i]->key < key) x = x->next[i];
        update[i] = x;
    }
    x = x->next[0];
    if (x && x->key == key) {
        x->value = value;
        return SKIP_LIST_PROBABILISTIC_OK;
    }
    int lvl = random_level(sl);
    if (lvl > sl->max_level) {
        for (int i = sl->max_level; i < lvl; ++i) update[i] = sl->head;
        sl->max_level = lvl;
    }
    sl_node_t* nd = (sl_node_t*)calloc(1, sizeof(sl_node_t));
    if (!nd) return SKIP_LIST_PROBABILISTIC_ERR_NULL;
    nd->key = key;
    nd->value = value;
    nd->level = lvl;
    for (int i = 0; i < lvl; ++i) {
        nd->next[i] = update[i]->next[i];
        update[i]->next[i] = nd;
    }
    ++sl->count;
    return SKIP_LIST_PROBABILISTIC_OK;
}

bool sl_find(const skiplist_t* sl, int64_t key, int64_t* value_out) {
    if (!sl || !sl->head) return false;
    const sl_node_t* x = sl->head;
    for (int i = sl->max_level - 1; i >= 0; --i) {
        while (x->next[i] && x->next[i]->key < key) x = x->next[i];
    }
    x = x->next[0];
    if (x && x->key == key) {
        if (value_out) *value_out = x->value;
        return true;
    }
    return false;
}

bool sl_delete(skiplist_t* sl, int64_t key) {
    if (!sl || !sl->head) return false;
    sl_node_t* update[SKIPLIST_MAX_LEVEL];
    sl_node_t* x = sl->head;
    for (int i = sl->max_level - 1; i >= 0; --i) {
        while (x->next[i] && x->next[i]->key < key) x = x->next[i];
        update[i] = x;
    }
    x = x->next[0];
    if (!x || x->key != key) return false;
    for (int i = 0; i < sl->max_level; ++i) {
        if (update[i]->next[i] != x) break;
        update[i]->next[i] = x->next[i];
    }
    free(x);
    while (sl->max_level > 1 && sl->head->next[sl->max_level - 1] == NULL) --sl->max_level;
    --sl->count;
    return true;
}
