#include "interface.h"

xor_linked_list_d61_err_t xor_linked_list_d61_verify_guard(bool cond) {
    if (!cond) {
        return XOR_LINKED_LIST_D61_ERR_INVARIANT;
    }
    return XOR_LINKED_LIST_D61_OK;
}
