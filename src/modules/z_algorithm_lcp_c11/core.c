#include "interface.h"
#include <math.h>
#include <string.h>

void build_z_array(const char* s, size_t n, size_t* z) {
    if (n == 0) return;
    z[0] = n;
    size_t l = 0, r = 0;
    for (size_t i = 1; i < n; ++i) {
        z[i] = (i <= r && z[i - l] < r - i + 1) ? z[i - l] : (i <= r ? r - i + 1 : 0);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) { l = i; r = i + z[i] - 1; }
    }
}
size_t z_find_occurrences(const char* pat, const char* text, size_t* out, size_t max_out) {
    size_t m = strlen(pat), n = strlen(text), tot = m + 1 + n;
    char buf[256];
    size_t z[256] = {0};
    memcpy(buf, pat, m); buf[m] = '$'; memcpy(buf + m + 1, text, n);
    build_z_array(buf, tot, z);
    size_t hits = 0;
    for (size_t i = m + 1; i < tot; ++i) {
        if (z[i] == m) {
            if (out && hits < max_out) out[hits] = i - m - 1;
            ++hits;
        }
    }
    return hits;
}
