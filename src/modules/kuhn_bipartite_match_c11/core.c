#include "interface.h"
#include <math.h>
#include <string.h>

static bool kuhn_dfs(int u, int nr, const bool adj[32][32], bool vis[32], int match_r[32]) {
    for (int v = 0; v < nr; ++v) {
        if (!adj[u][v] || vis[v]) continue;
        vis[v] = true;
        if (match_r[v] < 0 || kuhn_dfs(match_r[v], nr, adj, vis, match_r)) {
            match_r[v] = u;
            return true;
        }
    }
    return false;
}
int kuhn_max_match(int nl, int nr, const bool adj[32][32], int out_r[32]) {
    for (int v = 0; v < nr; ++v) out_r[v] = -1;
    int matched = 0;
    for (int u = 0; u < nl; ++u) {
        bool vis[32] = {false};
        if (kuhn_dfs(u, nr, adj, vis, out_r)) ++matched;
    }
    return matched;
}
