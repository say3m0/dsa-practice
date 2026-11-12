
# LONGEST CONSECUTIVE SEQUENCE

**Problem:** LeetCode 128

---

## Approach 1: Ordered Set (Sorting + Traversal)

**Idea:**

Use a `set` to remove duplicates and automatically maintain elements in sorted order. Then traverse the set and count consecutive elements.

**Steps ===>**

1. Insert all elements of the array into a `set`.
   - Automatically removes duplicate elements.
   - Maintains elements in ascending order.

2. Traverse the set using an iterator.

3. Access the current element and its next element using `next(it)`.

4. Check whether the difference between the current and next element is exactly 1.
   - If yes, increment `cnt`.
   - Otherwise, update `ans` and reset `cnt` to 1.

5. Continue until the end of the set.

6. Return the maximum consecutive sequence length.

**TIME COMPLEXITY:** O(n log n)

**SPACE COMPLEXITY:** O(n)

---

## Approach 2: Hash Set (Starting Point Optimization)

**Idea:**

Use an `unordered_set` for average O(1) lookup. Instead of checking every element as a possible starting point, only start counting when the previous consecutive element does not exist.

**Steps ===>**

1. Insert all elements of the array into an `unordered_set`.
   - Automatically removes duplicates.
   - Provides average O(1) search.

2. Traverse the unique elements of the `unordered_set`.

3. For each element `u`, check whether `u-1` exists in the set.
   - If it exists, skip the current element because it is not the starting point of a sequence.
   - Otherwise, consider `u` as the starting point.

4. Start a nested `while` loop from `u+1`.
   - If the next consecutive element exists, increment `cnt`.
   - Continue searching until a consecutive element is missing.

5. Update `ans` with the maximum sequence length.

6. Reset `cnt` for the next sequence.

7. Return `ans`.

**TIME COMPLEXITY:** O(n) Average

**SPACE COMPLEXITY:** O(n)

---

## Comparison Between Two Approaches

| Feature | Approach 1: Set | Approach 2: Unordered Set |
|---|---|---|
| Data Structure | Red-Black Tree (typical) | Hash Table |
| Duplicate Removal | Yes | Yes |
| Sorted Elements | Yes | No |
| Search | O(log n) | O(1) average |
| Overall Time | O(n log n) | O(n) average |
| Space | O(n) | O(n) |

---

## IMPORTANT OBSERVATIONS

**Approach 1:**
- Sorting is not explicitly required.
- `set` automatically maintains sorted order.
- Consecutive elements can be identified by comparing adjacent elements.

**Approach 2:**
- Sorting is not required.
- Only sequence starting points are used to begin traversal.
- If `u-1` exists, `u` is skipped.
- Duplicate elements are automatically removed.
- No separate visited or tracking set is required.

**FINAL VERDICT:**

Approach 2 is more efficient for this problem because it achieves O(n) average time complexity using Hash Set and Starting Point Optimization.
