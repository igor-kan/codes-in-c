#ifndef BOYER_MOORE_HORSPOOL_C_INTERFACE_H
#define BOYER_MOORE_HORSPOOL_C_INTERFACE_H

#include "types.h"
#include "errors.h"

boyer_moore_horspool_c_err_t bmh_compile(const uint8_t* pat, size_t m, bmh_table_t* out);
size_t bmh_find_all(const uint8_t* text, size_t n, const uint8_t* pat, const bmh_table_t* tbl, size_t* out_pos, size_t max_out);
boyer_moore_horspool_c_err_t bmh_validate_inputs(const uint8_t* text, size_t n, const uint8_t* pat, size_t m);
ptrdiff_t bmh_fast_first(const uint8_t* text, size_t n, const uint8_t* pat, const bmh_table_t* tbl);
size_t bmh_parallel_count(const uint8_t* text, size_t n, const uint8_t* pat, size_t m);
boyer_moore_horspool_c_err_t bmh_verify_hits(const uint8_t* text, const uint8_t* pat, size_t m, const size_t* pos, size_t cnt);

#endif /* BOYER_MOORE_HORSPOOL_C_INTERFACE_H */
