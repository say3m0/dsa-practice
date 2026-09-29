# Check if There is a Valid Parentheses Path

**Problem:** [Check if There is a Valid Parentheses Path - LeetCode](https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-path/)

Given an $m \times n$ grid of parentheses `'('` and `')'`, return `true` if there is a valid parentheses string path from top-left $(0, 0)$ to bottom-right $(m-1, n-1)$ moving only **Right** or **Down**.

---

### Core Intuition & Prerequisites

1. **Path Length:** Top-left to bottom-right always takes $(n + m - 1)$ steps. If the total path length is odd, a balanced parentheses string is mathematically impossible (must be even).
2. **Boundary Conditions:** The first cell `grid[0][0]` must be `'('` and the last cell `grid[n-1][m-1]` must be `')'`.
3. **Balance Tracker (`bal`):**
   * Encountering `'('` increases the balance by `+1`.
   * Encountering `')'` decreases the balance by `-1`.
   * A path is valid if `bal >= 0` at every intermediate step and `bal == 0` at the destination.
4. **Maximum Balance Bound:** The maximum possible open brackets in any valid path cannot exceed $(n + m) / 2$.

---

## 1. First Approach: Top-Down DP (DFS + Memoization)

### Why this approach?
* **Natural Backtracking:** Modeling movement (Right/Down) as recursive function calls matches natural decision-tree thinking.
* **Redundancy Elimination:** Memoization caches already computed states $(r, c, bal)$, preventing exponential re-computation.

### Algorithm Steps
1. Perform basic edge checks (odd path length, invalid start or end characters).
2. Define a recursive helper function `solve(r, c, bal)`:
   * **Out of Bounds / Invalid State:** If $r \ge n$, $c \ge m$, or $bal < 0$, return `false`.
   * **Update Balance:** $bal = bal + (grid[r][c] == '(' ? 1 : -1)$. If $bal < 0$, return `false`.
   * **Base Case:** At destination $(n-1, m-1)$, return `true` if $bal == 0$, else `false`.
   * **Memo Check:** If `dp[r][c][bal]` is already computed, return the cached result.
   * **Transitions:** Recursively explore moving **Down** `solve(r + 1, c, bal)` and **Right** `solve(r, c + 1, bal)`.
   * **Store & Return:** Save the combined boolean result (`Down || Right`) in `dp[r][c][bal]` and return it.

--
* **TIME COMPLEXITY:** $O(n \times m \times \text{max\_bal})$
* **SPACE COMPLEXITY:** $O(n \times m \times \text{max\_bal})$ — 3D Memoization table + recursion call stack depth $O(n + m)$.
--

---

## 2. Second Approach: Bottom-Up DP (Tabulation)

### Why this approach?
* **No Stack Overflow Risk:** Completely eliminates recursion overhead and potential call stack limits on larger grid dimensions.
* **Iterative Filling:** Iteratively calculates valid states starting from cell $(0, 0)$ forward to destination $(n-1, m-1)$.

### Algorithm Steps
1. Perform initial edge checks (odd path length, invalid boundary characters).
2. Create a 3D boolean dynamic programming array `dp[n][m][max_bal + 1]`, initialized to `false`.
3. **Base Case:** Set `dp[0][0][1] = true` since `grid[0][0]` must be `'('`.
4. Iterate row `r` from `0` to `n-1`, column `c` from `0` to `m-1`, and `bal` from `0` to `max_bal`:
   * If `dp[r][c][bal]` is `false`, skip it (unreachable state).
   * **Move Down:** If $r + 1 < n$, compute $next\_bal$. If valid ($0 \le next\_bal \le max\_bal$), set `dp[r + 1][c][next_bal] = true`.
   * **Move Right:** If $c + 1 < m$, compute $next\_bal$. If valid ($0 \le next\_bal \le max\_bal$), set `dp[r][c + 1][next_bal] = true`.
5. Return the boolean value at `dp[n-1][m-1][0]`.

--
* **TIME COMPLEXITY:** $O(n \times m \times \text{max\_bal})$
* **SPACE COMPLEXITY:** $O(n \times m \times \text{max\_bal})$ — 3D DP table.
--

---

## 3. Third Approach: Breadth-First Search (BFS)

### Why this approach?
* **Level-by-Level Exploration:** Explores all possible grid states step-by-step using a FIFO queue.
* **Early Termination:** Allows immediate return of `true` as soon as the first valid path reaches the destination with `bal == 0`, without processing remaining grid states.

### Algorithm Steps
1. Perform initial edge checks.
2. Maintain a 3D boolean array `visited[n][m][max_bal + 1]` to prevent re-enqueueing duplicate states.
3. Initialize a queue holding tuples of `{row, col, balance}`.
4. Push initial state `{0, 0, 1}` to the queue and set `visited[0][0][1] = true`.
5. While the queue is not empty:
   * Dequeue state `{r, c, bal}`.
   * If $r == n - 1$, $c == m - 1$, and $bal == 0$, immediately return `true`.
   * Evaluate candidate transitions: **Down** `(r + 1, c)` and **Right** `(r, c + 1)`.
   * For each valid move within grid boundaries, compute `next_bal`.
   * If $0 \le next\_bal \le max\_bal$ and state is unvisited, mark `visited` and push state to queue.
6. If the queue empties without reaching the destination in a balanced state, return `false`.

--
* **TIME COMPLEXITY:** $O(n \times m \times \text{max\_bal})$
* **SPACE COMPLEXITY:** $O(n \times m \times \text{max\_bal})$ — Queue size + 3D visited array.
--

---

## Comparison Summary

| Approach | Design Pattern | Core Advantage | Memory Bottleneck |
| :--- | :--- | :--- | :--- |
| **1. Top-Down DP** | DFS + Memoization | Intuitive implementation with lazy evaluation | Recursion Call Stack + 3D Memo Table |
| **2. Bottom-Up DP** | Iterative Tabulation | Predictable execution with zero stack overflow risk | Full 3D DP Table |
| **3. BFS** | Queue Traversal | Enables early termination on finding the first valid path | Queue memory + 3D Visited Table |