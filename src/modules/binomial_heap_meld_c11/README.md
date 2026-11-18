# Arena-Backed Binomial Heap with O(log N) Meld & Extract-Min (`binomial_heap_meld_c11`)

> Category: **Meldable Queues** | Language: **C11**

## Overview

Implements Vuillemin's Binomial Queue using left-child right-sibling arena nodes and degree-indexed root array carries analogous to binary addition.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(log N) binary-addition tree carry meld and min extraction` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- At most one binomial tree of each degree k exists in the root array.
- Extracted sequence is monotonically non-decreasing.

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
