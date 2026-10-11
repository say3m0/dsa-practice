## Math & Logic Approach

Let three consecutive Fibonacci numbers be $F_i$, $F_{i+1}$, and $F_{i+2}$.

According to the Fibonacci recurrence relation:
$$F_i + F_{i+1} = F_{i+2}$$

Therefore, the sum of three consecutive terms is:
$$\text{Sum} = F_i + F_{i+1} + F_{i+2}$$

Substituting $F_i + F_{i+1} = F_{i+2}$ into the equation gives:
$$\text{Sum} = F_{i+2} + F_{i+2} = 2 \times F_{i+2}$$

This leads to two key conditions for $n$:
1. **$n$ must be even.** If $n$ is odd, it is impossible for $n$ to be the sum of three consecutive Fibonacci numbers, so return `false` immediately.
2. **$\frac{n}{2}$ must be a Fibonacci number.**

---

## Algorithm Steps

1. If $n \% 2 \neq 0$, return `false`.
2. Calculate $target = \frac{n}{2}$.
3. Generate the Fibonacci sequence starting from $0$.
4. Check if $target$ matches any generated Fibonacci number. If it does, return `true`; otherwise, return `false`.

---

## Complexity Analysis

* **Time Complexity (TC):** $\mathcal{O}(\log n)$  
  * Fibonacci numbers grow exponentially (golden ratio $\approx 1.618$). For $n \le 10^9$, the sequence generation takes fewer than 50 iterations.

* **Space Complexity (SC):** $\mathcal{O}(1)$  
  * Uses only a few variables to maintain state during iterative generation without requiring extra memory.