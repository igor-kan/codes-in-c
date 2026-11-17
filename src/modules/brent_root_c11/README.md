# Brent-Dekker Bracketed Root Finder in C11 (`brent_root_c11`)

> Category: **Numerical Methods** | Language: **C11**

## Overview

Combines inverse quadratic interpolation, secant steps, and guaranteed bisection fallback for robust derivative-free root finding on bracketed continuous functions.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(log(dx/tol)) worst case, superlinear near simple roots` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Endpoint product f(a) * f(b) <= 0 on entry.
- |f(root)| <= tolerance upon convergence.

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
