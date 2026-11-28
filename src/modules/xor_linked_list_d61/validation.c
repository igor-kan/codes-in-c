#include "interface.h"

xor_linked_list_d61_err_t xor_linked_list_d61_validate_len(size_t n) {
    if (n == 0) {
        return XOR_LINKED_LIST_D61_ERR_INVALID;
    }
    return XOR_LINKED_LIST_D61_OK;
}
