#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(kuhn_bipartite_match_c11_validate_len(1) == KUHN_BIPARTITE_MATCH_C11_OK);
    bool adj[32][32] = {0};
    adj[0][0]=adj[0][1]=adj[1][0]=adj[2][2]=adj[2][3]=adj[3][2]=true;
    int mr[32];
    assert(kuhn_max_match(4, 4, adj, mr) == 4);
    assert(kuhn_bipartite_match_c11_verify_guard(true) == KUHN_BIPARTITE_MATCH_C11_OK);
    return 0;
}
