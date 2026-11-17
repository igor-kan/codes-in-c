# Arena-Backed Self-Adjusting Splay Tree in C11 (`splay_tree_intrusive`)

> Category: **Ordered Search Trees** | Language: **C11**

## Overview

Implements an ordered dictionary via Sleator-Tarjan bottom-up zig/zig-zig/zig-zag rotations in a flat C11 arena supporting lookup, insertion, and erasure.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(log N) amortized insert, find, and delete` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- In-order traversal always yields strictly increasing keys.
- Every child's parent link matches its tree parent.

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
