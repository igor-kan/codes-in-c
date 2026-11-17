#include "interface.h"

red_black_tree_c11_err_t llrb_validate(const llrb_tree_t* t) {
    if (!t) return RED_BLACK_TREE_C11_ERR_NULL;
    if (t->cap < 0 || t->cap > LLRB_MAX) return RED_BLACK_TREE_C11_ERR_BOUNDS;
    return RED_BLACK_TREE_C11_OK;
}
