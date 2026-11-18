#include "interface.h"
#include <math.h>
#include <string.h>

static uint64_t mix64_c(uint64_t x) {
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
}
void hring_init(hash_ring_t* r) { r->count = 0; }
void hring_add_node(hash_ring_t* r, int32_t node_id, int32_t replicas) {
    for (int32_t k = 0; k < replicas && r->count < 256; ++k) {
        uint64_t tok = mix64_c(((uint64_t)node_id << 32) ^ (uint64_t)k);
        size_t pos = r->count++;
        while (pos > 0 && r->ring[pos - 1].token > tok) {
            r->ring[pos] = r->ring[pos - 1];
            --pos;
        }
        r->ring[pos] = (vnode_t){tok, node_id};
    }
}
int32_t hring_locate(const hash_ring_t* r, uint64_t key) {
    uint64_t h = mix64_c(key);
    size_t lo = 0, hi = r->count;
    while (lo < hi) {
        size_t mid = (lo + hi) >> 1;
        if (r->ring[mid].token < h) lo = mid + 1;
        else hi = mid;
    }
    return r->ring[lo < r->count ? lo : 0].node_id;
}
