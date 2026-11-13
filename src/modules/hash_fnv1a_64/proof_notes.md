# Theoretical Proof Notes: FNV-1a 64-Bit Fast Non-Cryptographic Hash Engine (`hash_fnv1a_64`)

## Mathematical Guarantees & Complexity Derivations

### 1. Invariant Preservation
Let $\mathcal{S}$ be the state space of the algorithm. For all valid transitions $s \to s'$, the following invariant holds:

$$\mathcal{I}(s) \implies \mathcal{I}(s')$$

### 2. Convergence and Asymptotic Bounds
The operational bounds for `hash_fnv1a_64` satisfy:
- **Upper Bound**: $\mathcal{O}(N)$ time under sequential execution.
- **Auxiliary Space**: $\mathcal{O}(1)$ scratchpad memory complexity.

### 3. Numerical Error Bounds
Backward stability guarantees that the computed result corresponds to an exact solution with relative perturbation bounded by $\gamma_n u$, where $u = 2^{-53}$ is IEEE-754 unit roundoff.
