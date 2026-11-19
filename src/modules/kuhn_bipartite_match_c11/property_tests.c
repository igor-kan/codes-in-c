#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(kuhn_bipartite_match_c11_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    bool adj[32][32] = {0}; adj[0][0]=adj[1][0]=adj[2][1]=true; int mr[32]; assert(kuhn_max_match(3, 2, adj, mr) == 2);
    return 0;
}
