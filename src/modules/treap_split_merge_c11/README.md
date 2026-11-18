# Arena-Allocated Implicit Treap with Split/Merge in C11 (`treap_split_merge_c11`)

> Category: **Randomized Trees** | Language: **C11**

## Overview

Maintains an implicit-key randomized treap inside a contiguous C11 array with subtree size and sum maintenance across functional-style split and merge.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(log N) expected split, merge, and range sum` |
| **Space Complexity** | `O(N) static arena` |

## Mathematical & Safety Invariants

- Subtree size and sum match exact child totals.
- In-order sequence order is preserved across split followed by merge.

## Module Architecture

| File | Lifecycle Role |
| :--- | :--- |
| `types.h` | Stage 01 |
| `errors.h` | Stage 02 |
| `interface.h` | Stage 03 |
| `core.c` | Stage 04 |
| `validation.c` | Stage 05 |
| `fast_path.c` | Stage 06 |
| `concurrent.c` | Stage 07 |
| `invariants.c` | Stage 08 |
| `unit_tests.c` | Stage 09 |
| `property_tests.c` | Stage 10 |
| `benchmark.c` | Stage 11 |
| `README.md` | Stage 12 |

## Verification & Execution Example

```text
gcc -std=c11 -O2 -Wall -Wextra -Werror -pthread core.c validation.c fast_path.c concurrent.c invariants.c unit_tests.c -lm -o test_bin && ./test_bin
```

---
© 2026 Igor Kan
