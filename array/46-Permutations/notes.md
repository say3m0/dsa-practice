# LeetCode 46: Permutations — Two Backtracking Approaches

Link to Problem: [LeetCode 46 - Permutations](https://leetcode.com/problems/permutations/description/?envType=problem-list-v2&envId=array)

---

## 1. Approach 1: Path Vector with Linear Search (`std::find`)

### Strategy
This approach builds each permutation incrementally using a temporary list (`tempList`). At each recursion step, the algorithm iterates over all elements of `nums` and checks whether the current element is already present in `tempList`. If it is not present, the element is added, the algorithm recurses deeper, and then backtracks by removing the element.

### Steps
1. **Base Case:** When `tempList.size() == nums.size()`, a full valid permutation has been constructed. Append `tempList` to `res` and return.
2. **Looping:** Iterate `i` from `0` to `nums.size() - 1`.
3. **Condition Check:** Use `std::find(tempList.begin(), tempList.end(), nums[i])` to check if `nums[i]` is already in `tempList`. If found, skip it using `continue`.
4. **Choose:** Push `nums[i]` into `tempList`.
5. **Explore:** Make a recursive call to `backtrack(res, tempList, nums)`.
6. **Un-choose (Backtrack):** Remove the last element using `tempList.pop_back()`.

### Analysis
* **Time Complexity:** $O(N \cdot N!)$
  * Generating $N!$ permutations.
  * Searching inside `tempList` takes $O(N)$ time per step.
* **Space Complexity:** $O(N)$
  * Auxiliary space for `tempList` of size up to $N$.
  * Call stack depth goes up to $N$.

---

## 2. Approach 2: In-place Swap-based Backtracking

### Strategy
Instead of building a separate temporary list and scanning it for used elements, this approach reorders the original `nums` vector directly. By swapping the current index `idx` with every candidate index `i` (where $i \ge idx$), each element gets a turn at position `idx`. Once all branches from that swap are explored, a second swap restores the array to its previous configuration.

### Steps
1. **Base Case:** When `idx == nums.size()`, all positions have been filled. Append the current state of `nums` to `res` and return.
2. **Looping:** Iterate `i` from `idx` to `nums.size() - 1`.
3. **Choose (Swap):** Execute `swap(nums[i], nums[idx])` to place `nums[i]` at the current decision index `idx`.
4. **Explore:** Recursively call `backtrack(idx + 1, res, nums)` to decide the element for index `idx + 1`.
5. **Un-choose / Backtrack (Re-swap):** Execute `swap(nums[i], nums[idx])` again to undo the swap and maintain the correct order for subsequent iterations of the loop.

### Analysis
* **Time Complexity:** $O(N \cdot N!)$
  * Generating $N!$ permutations, each copy to `res` takes $O(N)$ time.
  * Swapping and checking take $O(1)$ constant time per step (much faster in practice than Approach 1).
* **Space Complexity:** $O(N)$
  * $O(1)$ extra memory (no extra vector needed).
  * Recursion stack depth is bounded by $N$.

---

## Comparison Table

| Metric | Approach 1 (Path Vector + `find`) | Approach 2 (In-place Swap) |
| :--- | :--- | :--- |
| **Extra Vector Space** | $O(N)$ for `tempList` | $O(1)$ extra space |
| **Element Lookup** | $O(N)$ via `std::find` | $O(1)$ via array indices |
| **Array Mutability** | Leaves `nums` untouched | Modifies `nums` during recursion and restores it |
| **Practical Speed** | Slower (due to linear search) | Faster (direct element swaps) |