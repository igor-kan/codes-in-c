# Dual-Table Cuckoo Hash Map with Worst-Case O(1) Lookups (`cuckoo_hash_table`)

> Category: **Data Structures** | Language: **C11**

## Overview

Open-addressed two-table cuckoo hash map guaranteeing at most two cacheline probes for lookups and deletions, with cycle-detected bounded displacement chains.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) worst-case lookup / O(1) amortized insert` |
| **Space Complexity** | `O(M)` |

## Mathematical & Safety Invariants

- Every inserted key resides at exactly h1(key) in T1 or h2(key) in T2.
- Lookups always inspect at most 2 slots (strict O(1) worst-case).
- Occupancy counter matches active occupied slots across both tables.

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
