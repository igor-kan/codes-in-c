# Monotone Fritsch-Carlson Piecewise Cubic Hermite Interpolator (`hermite_cubic_spline_c11`)

> Category: **Numerical Interpolation** | Language: **C11**

## Overview

Computes shape-preserving cubic Hermite tangents over sorted nodes (x_i, y_i) with Fritsch-Carlson monotonicity limiting to prevent overshoot oscillations.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N) tangent slope limiting + O(log N) interval evaluation` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- Interpolant reproduces exact knot values y_i at x = x_i.
- Monotone data produces strictly monotone interpolated values on every subinterval.

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
