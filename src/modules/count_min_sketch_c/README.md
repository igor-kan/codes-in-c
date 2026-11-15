# Conservative-Update Count-Min Sketch Streaming Frequency Estimator (`count_min_sketch_c`)

> Category: **Streaming Sketches** | Language: **C11**

## Overview

Probabilistic sub-linear streaming frequency sketch supporting d pairwise-independent SplitMix64 row hashes, conservative update (Estan-Varghese) bias reduction, and never-underestimate guarantees.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(d) per update/query` |
| **Space Complexity** | `O(d * w)` |

## Mathematical & Safety Invariants

- Query estimate f_hat(x) >= true_freq(x) holds deterministically for positive increments.
- Conservative update never exceeds standard Count-Min estimate: f_cu(x) <= f_cm(x).
- Row widths and depths are validated positive dimensions.

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
