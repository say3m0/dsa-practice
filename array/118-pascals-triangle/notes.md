# Pascal's Triangle - 3 Algorithmic Approaches

**Problem Link:** [LeetCode #118 - Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/)

---

## 1. Dynamic Programming (Standard / Optimal Approach)

### Explanation
This is the most intuitive and standard way to construct Pascal's Triangle. Every row starts and ends with `1`. For all other positions in between, each number is simply the sum of the two numbers located directly above it in the preceding row.

### Step-by-Step Algorithm
1. Initialize an empty 2D array/list to store all rows of the triangle.
2. Loop through each row index from `0` up to `numRows - 1`:
   * Set the first and last elements of the current row to `1`.
   * For any middle positions (from index `1` up to `row - 1`), calculate the value by adding the element at `(previous_row, column - 1)` and the element at `(previous_row, column)`.
   * Append the completed row to the triangle list.
3. Return the fully generated triangle.

### Complexity Analysis
* **Time Complexity:** $\mathcal{O}(n^2)$ — computing each element takes constant $\mathcal{O}(1)$ time, and there are $\frac{n(n + 1)}{2}$ total elements.
* **Space Complexity:** $\mathcal{O}(1)$ auxiliary space (excluding the memory required to store the output structure).

---

## 2. Combination / $n\text{Cr}$ Approach

### Explanation
Pascal's Triangle is fundamentally tied to combinations in combinatorics. The element at row `i` and column `j` (0-indexed) directly corresponds to the combination value $n\text{Cr}$, which represents choosing `r` items from `n` total items.

### Step-by-Step Algorithm
1. Understand the mathematical relation for any position $(i, j)$:
   $$\text{Value at } (i, j) = \binom{i}{j} = \frac{i!}{j!(i - j)!}$$
2. Create an iterative helper function to compute $n\text{Cr}$ efficiently without calculating full factorials (to prevent integer overflow):
   * Start with a result value of `1`.
   * Multiply by $(n - k)$ and divide by $(k + 1)$ for `k` ranging from `0` to `r - 1`.
3. Construct the 2D array by iterating through every row `i` and column `j`, calling the $n\text{Cr}$ calculation for each cell individually.

### Complexity Analysis
* **Time Complexity:** $\mathcal{O}(n^3)$ — calculating $n\text{Cr}$ independently for every single cell takes $\mathcal{O}(k)$ time per element.
* **Space Complexity:** $\mathcal{O}(1)$ auxiliary space (excluding the output structure).

---

## 3. Optimized Row Generation Approach

### Explanation
Instead of calculating $n\text{Cr}$ from scratch for every single cell (which leads to redundant multiplications), you can derive any element in a row directly from its preceding element in the same row. This enables generating an entire row independently in linear time.

### Step-by-Step Algorithm
1. Understand the transition formula between adjacent elements in the same row:
   $$\text{element}_k = \text{element}_{k-1} \times \frac{\text{row} - k + 1}{k}$$
2. For each row from `1` to `numRows`:
   * Initialize a new row list with the first element set to `1`.
   * Keep a running variable starting at `1`.
   * Loop `col` from `1` to `row - 1`, update the running variable using the transition formula, and push the new value into the row list.
   * Append the generated row to the main 2D output list.

### Complexity Analysis
* **Time Complexity:** $\mathcal{O}(n^2)$ — generates each row in $\mathcal{O}(\text{row})$ time without redundant multiplications.
* **Space Complexity:** $\mathcal{O}(1)$ auxiliary space (excluding the output structure).

---

## Approach Comparison

| Approach | Time Complexity | Auxiliary Space | Key Advantage |
| :--- | :--- | :--- | :--- |
| **1. Dynamic Programming** | $\mathcal{O}(n^2)$ | $\mathcal{O}(1)$ | Most straightforward implementation using basic addition. |
| **2. Pure $n\text{Cr}$** | $\mathcal{O}(n^3)$ | $\mathcal{O}(1)$ | Ideal if you only need to calculate a single specific cell at $(i, j)$. |
| **3. Optimized Row Generation** | $\mathcal{O}(n^2)$ | $\mathcal{O}(1)$ | Ideal if you need to compute a specific row independently. |