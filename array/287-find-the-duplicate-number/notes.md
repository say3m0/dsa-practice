# Problem: [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/)

**2 Approaches ===>**

---

**First Approach : Binary Search on Answer**

1. Set `low = 1` and `high = n`.
2. Calculate `mid` and count how many elements in the array are less than or equal to `mid`.
3. If `count > mid`, the duplicate number lies in the range `[low, mid]`.
4. Otherwise, search in the range `[mid + 1, high]`.
5. Continue until `low == high`. That value is the duplicate number.

TIME COMPLEXITY : O(n log n)

SPACE COMPLEXITY : O(1)

---

**Second Approach : Floyd's Cycle Detection Algorithm**

1. Initialize `slow` and `fast` pointers at `nums[0]`.
2. Move `slow` one step at a time and `fast` two steps at a time until they meet. This meeting point is inside the cycle.
3. Reset `slow` to `nums[0]`, keeping `fast` at the meeting point.
4. Move both pointers one step at a time until they meet again.
5. The second meeting point is the duplicate number.

TIME COMPLEXITY : O(n)

SPACE COMPLEXITY : O(1)

---

**Key Difference:**

- Binary Search → Uses the number range and counting.
- Floyd's Cycle Detection → Uses cycle detection with two pointers.