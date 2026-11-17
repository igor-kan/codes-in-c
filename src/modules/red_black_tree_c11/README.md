# Sedgewick Left-Leaning Red-Black Tree (LLRB) in C11 (`red_black_tree_c11`)

> Category: **Balanced Trees** | Language: **C11**

## Overview

Implements Sedgewick's Left-Leaning Red-Black BST using static arena nodes, enforcing zero right-leaning red links, zero consecutive red links, and constant black depth.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(log N) worst-case insertion and search` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- Root node is always colored black.
- Every root-to-null path contains an identical count of black nodes.

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
