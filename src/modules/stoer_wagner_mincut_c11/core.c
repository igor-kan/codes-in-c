#include "interface.h"
#include <math.h>
#include <string.h>

int64_t sw_mincut_c(int n, const int64_t adj[16][16]) {
    int64_t w[16][16];
    memcpy(w, adj, sizeof(w));
    int vtx[16];
    for (int i = 0; i < n; ++i) vtx[i] = i;
    int64_t best = (1LL << 60);
    for (int m = n; m > 1; --m) {
        int64_t wt[16] = {0};
        bool used[16] = {false};
        int prev = -1, last = -1;
        for (int it = 0; it < m; ++it) {
            int sel = -1;
            for (int i = 0; i < m; ++i) {
                if (!used[i] && (sel == -1 || wt[i] > wt[sel])) sel = i;
            }
            used[sel] = true; prev = last; last = sel;
            for (int i = 0; i < m; ++i) if (!used[i]) wt[i] += w[vtx[sel]][vtx[i]];
        }
        if (wt[last] < best) best = wt[last];
        int u = vtx[prev], v = vtx[last];
        for (int i = 0; i < m; ++i) {
            int k = vtx[i];
            if (k != u && k != v) { w[u][k] += w[v][k]; w[k][u] += w[k][v]; }
        }
        vtx[last] = vtx[m - 1];
    }
    return best;
}
