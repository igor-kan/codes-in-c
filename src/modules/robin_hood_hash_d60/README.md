# Fixed-Capacity Open-Addressed Robin Hood Hash Map (`robin_hood_hash_d60`)

> Category: **Hash Tables** | Language: **C11**

## Overview

Open-addressed linear-probing table tracking probe sequence length (PSL) and swapping richer elements forward to bound tail lookup latency.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) expected insert/lookup with PSL variance minimization` |
| **Space Complexity** | `O(C) slot array` |

## Mathematical & Safety Invariants

- All inserted keys remain retrievable and PSL invariant holds.

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
