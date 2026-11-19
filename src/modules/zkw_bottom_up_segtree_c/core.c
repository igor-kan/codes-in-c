#include "interface.h"
#include <math.h>
#include <string.h>

void zkw_init(zkw_tree_t* z) { memset(z, 0, sizeof(*z)); }
void zkw_set(zkw_tree_t* z, int idx, int64_t val) {
    int p = idx + 1 + ZKW_BASE;
    z->t[p] = val;
    for (p >>= 1; p > 0; p >>= 1) z->t[p] = z->t[p << 1] + z->t[p << 1 | 1];
}
int64_t zkw_sum(const zkw_tree_t* z, int l, int r) {
    int64_t ans = 0;
    for (int s = l + ZKW_BASE, t = r + 2 + ZKW_BASE; s ^ t ^ 1; s >>= 1, t >>= 1) {
        if (~s & 1) ans += z->t[s ^ 1];
        if ( t & 1) ans += z->t[t ^ 1];
    }
    return ans;
}
