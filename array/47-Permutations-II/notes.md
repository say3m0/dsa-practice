# LeetCode 47: Permutations II — Two Backtracking Approaches with `unordered_set`

Link to Problem: [LeetCode 47 - Permutations II](https://leetcode.com/problems/permutations-ii/description/)

---

## The Core Concept: How `unordered_set` Guarantees Uniqueness

When input arrays contain duplicate elements (e.g., `nums = [1, 1, 2]`), standard permutation algorithms generate duplicate outputs. To prevent this, both approaches below enforce a strict rule at **each decision point**:

> **Rule:** At any given position (index) in the permutation, a particular value (e.g., `1`) can only be placed **ONCE**.

### Why Checking Value at Current Level is Sufficient

1. **Identical Decision Branches:** Placing `1` (first occurrence) at position `0` explores all valid permutations formed by the remaining pool of elements `{1, 2}`.
2. **Duplicate Subtrees:** If we later place `1` (second occurrence) at position `0`, the remaining pool of elements is still `{1, 2}`. Recursively processing this would generate the exact same set of subtrees and lead to duplicate permutations.
3. **Branch Pruning:** By maintaining an `unordered_set` at each recursion level, `s.count(nums[i])` or `usedInThisLevel.count(nums[i])` checks if `nums[i]` has already been chosen for the current position. If true, `continue` immediately skips the duplicate branch before making a recursive call.

---

## 1. Approach 1: In-Place Swap with Local `unordered_set`

### Strategy
This approach modifies the input vector in-place using `swap`. To handle duplicates, an `unordered_set<int> s` is created inside each recursive call. It tracks which values have already been swapped into the current decision slot `idx`.

### Steps
1. **Base Case:** When `idx == nums.size()`, append `nums` to `res` and return.
2. **Local Set:** Initialize `unordered_set<int> s` local to the current function call (scoped to `idx`).
3. **Looping:** Iterate `i` from `idx` to `nums.size() - 1`.
4. **Uniqueness Check:** If `s.count(nums[i]) > 0`, skip this iteration with `continue`.
5. **Mark Used:** Insert `nums[i]` into `s`.
6. **Swap & Explore:** Execute `swap(nums[i], nums[idx])`, recursively call `backtrack(idx + 1, res, nums)`, and restore state with `swap(nums[i], nums[idx])`.

---

## 2. Approach 2: Path Vector (`tempList`) + `visited` Array + Level `unordered_set`

### Strategy
This approach builds permutations explicitly using `tempList`. It uses a global `visited` boolean array to prevent re-using the same array index, alongside a local `unordered_set` (`usedInThisLevel`) to prevent choosing the same *value* multiple times at the current tree level.

### Steps
1. **Base Case:** When `tempList.size() == nums.size()`, append `tempList` to `res` and return.
2. **Local Level Set:** Initialize `unordered_set<int> usedInThisLevel` to track values used at the current depth.
3. **Looping:** Iterate `i` from `0` to `nums.size() - 1`.
4. **Duplicate Value Check:** If `usedInThisLevel.count(nums[i]) > 0`, skip with `continue`.
5. **Used Index Check:** If `visited[i] == true`, skip with `continue`.
6. **Choose & Explore:**
   * Set `visited[i] = true`.
   * Append `nums[i]` to `tempList`.
   * Insert `nums[i]` into `usedInThisLevel`.
   * Recurse: `backtrack(res, tempList, nums, visited)`.
7. **Backtrack:**
   * Remove last element: `tempList.pop_back()`.
   * Unmark index: `visited[i] = false`.

---

## Comparison Table

| Metric | Approach 1 (In-Place Swap) | Approach 2 (`tempList` + `visited`) |
| :--- | :--- | :--- |
| **Extra Memory for Path** | $O(1)$ extra space | $O(N)$ for `tempList` |
| **Index Tracking** | Handled implicitly via `idx` boundary | Handled explicitly via `visited` vector |
| **Uniqueness Guard** | `unordered_set` per `idx` level | `unordered_set` per tree level |
| **Pruning Performance** | High (Prunes before recursing) | High (Prunes before recursing) |