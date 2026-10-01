# Longest Common Prefix (LeetCode 14) – Code Note

## Problem Overview
Given an array of strings, find the longest common prefix string amongst all strings. If there is no common prefix, return an empty string `""`.

---

## Code Approaches & Analysis

### 1. Sorting Approach (Lexicographical Boundary Comparison)

* **Concept:**
  * Sort the array of strings lexicographically (alphabetically).
  * After sorting, strings with common prefixes group together, meaning the **first** and the **last** string in the sorted array will have the maximum possible difference.
  * Compare character by character only between the first string (`strs[0]`) and the last string (`strs.back()`).
  * As soon as a character mismatch occurs between these two, stop comparing and return the accumulated common prefix.

* **Complexity:**
  * **Time Complexity:** $\mathcal{O}(N \cdot M \log N)$ — Sorting $N$ strings of average length $M$ dominates the runtime; the subsequent linear comparison takes at most $\mathcal{O}(M)$ steps.
  * **Space Complexity:** $\mathcal{O}(1)$ or $\mathcal{O}(N \cdot M)$ — Depends on the space required by the sorting algorithm implementation.

---

### 2. Vertical Scanning Approach (Nested Character-by-Character Loop)

* **Concept:**
  * Iterate through each character position $i$ of the first string (`strs[0]`) using an outer loop.
  * Use an inner loop to check the $i$-th character of all other strings in the array vertically.
  * If the character position $i$ reaches the end of any string OR if a character mismatch is found (`strs[0][i] != strs[j][i]`), immediately return the substring of `strs[0]` from index `0` to `i`.
  * If the loops finish without any mismatch, `strs[0]` itself is the longest common prefix.

* **Complexity:**
  * **Time Complexity:** $\mathcal{O}(S)$ or $\mathcal{O}(N \cdot M)$ — $S$ is the sum of all characters across all strings. In the worst case, it checks every character ($N \times M$ operations), but in best/average cases, it returns early upon the first mismatch.
  * **Space Complexity:** $\mathcal{O}(1)$ — Operates directly on the input vector without allocating extra memory structures.

---

## Comparison Summary

| Approach | Time Complexity | Space Complexity | Pros | Cons |
| :--- | :--- | :--- | :--- | :--- |
| **1. Sorting Approach** | $\mathcal{O}(N \cdot M \log N)$ | $\mathcal{O}(1)$ | Very short code and simple comparison logic | Slower for large $N$ due to $\mathcal{O}(N \log N)$ sorting overhead |
| **2. Vertical Scanning** | $\mathcal{O}(N \cdot M)$ | $\mathcal{O}(1)$ | Optimal linear time; stops early on character mismatch | Contains nested loop logic |