#include "interface.h"
#include <assert.h>
#include <stdint.h>
#include <string.h>

int main(void) {
    // Official xxHash64 test vector: empty input, seed=0 => 0xEF46DB3751D8E999
    uint64_t h_empty = xxhash64_streaming_oneshot("", 0, 0);
    assert(h_empty == 0xEF46DB3751D8E999ULL);

    // Official xxHash64 test vector: empty input, seed=PRIME32_1 (0x9E3779B1) => 0xAC75FDA2929B17EF
    uint64_t h_seed = xxhash64_streaming_oneshot("", 0, 0x9E3779B1ULL);
    assert(h_seed == 0xAC75FDA2929B17EFULL);

    const char* msg = "Nobody inspects the spammish repetition";
    assert(xxhash64_streaming_check_invariants((const uint8_t*)msg, strlen(msg), 0x123456789ABCDEF0ULL) == XXHASH64_STREAMING_OK);

    const uint8_t* bufs[2] = {(const uint8_t*)msg, (const uint8_t*)"abc"};
    size_t lens[2] = {strlen(msg), 3};
    uint64_t out[2] = {0, 0};
    assert(xxhash64_streaming_batch_mt(bufs, lens, out, 2, 42, 2) == XXHASH64_STREAMING_OK);
    assert(out[0] == xxhash64_streaming_oneshot(msg, strlen(msg), 42));
    assert(out[1] == xxhash64_streaming_oneshot("abc", 3, 42));
    return 0;
}
