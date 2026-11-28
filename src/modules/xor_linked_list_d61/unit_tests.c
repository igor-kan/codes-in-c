#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(xor_linked_list_d61_validate_len(1) == XOR_LINKED_LIST_D61_OK);
    xor_list_t xl; xor_list_init(&xl);
    assert(xor_list_push_back(&xl, 10) == 1);
    assert(xor_list_push_back(&xl, 20) == 1);
    assert(xor_list_push_back(&xl, 30) == 1);
    int64_t vals[4];
    size_t n = xor_list_forward(&xl, vals, 4);
    assert(n == 3 && vals[0] == 10 && vals[1] == 20 && vals[2] == 30);
    assert(xor_list_size(&xl) == 3);
    assert(xor_linked_list_d61_verify_guard(true) == XOR_LINKED_LIST_D61_OK);
    return 0;
}
