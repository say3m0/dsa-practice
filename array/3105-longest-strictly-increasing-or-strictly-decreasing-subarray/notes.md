
# LONGEST STRICTLY INCREASING OR STRICTLY DECREASING SUBARRAY

**Problem:** LeetCode 3105

---

## Approach 1: Separate Conditions + Reset

**Idea:**

Maintain two variables to track the length of strictly increasing and strictly decreasing subarrays.

- `incre` → Current increasing subarray length.
- `decre` → Current decreasing subarray length.
- `ans` → Maximum length found so far.

**Steps ===>**

1. Traverse the array using a loop, comparing each element with its next element.

2. If both adjacent elements are equal:
   - Update `ans` with the maximum of `incre` and `decre`.
   - Reset both `incre` and `decre` to 1.

3. If the current element is smaller than the next element:
   - Increase `incre`.
   - Update `ans` when necessary.
   - Reset `decre` to 1.

4. If the current element is greater than the next element:
   - Increase `decre`.
   - Update `ans` when necessary.
   - Reset `incre` to 1.

5. Finally, return the maximum among `ans`, `incre`, and `decre` to consider the last subarray.

**TIME COMPLEXITY:** O(n)

**SPACE COMPLEXITY:** O(1)

---

## Approach 2: Mutually Exclusive Conditions

**Idea:**

Instead of separately handling all reset conditions, use mutually exclusive comparisons to update the increasing and decreasing lengths.

**Steps ===>**

1. Initialize `incre = 1`, `decre = 1`, and `ans = 0`.

2. If the array contains only one element, return 1.

3. Traverse the array and compare adjacent elements.

4. If both adjacent elements are equal:
   - Reset both `incre` and `decre` to 1.

5. If the current element is smaller than the next element:
   - Increment `incre`.
   - Reset `decre` to 1.

6. If the current element is greater than the next element:
   - Increment `decre`.
   - Reset `incre` to 1.

7. Update `ans` with the maximum of `incre` and `decre` after every iteration.

8. Return `ans`.

**TIME COMPLEXITY:** O(n)

**SPACE COMPLEXITY:** O(1)

---

## Key Difference Between Two Approaches

| Approach 1 | Approach 2 |
|---|---|
| Uses separate `if-else` conditions | Uses mutually exclusive `if` conditions |
| Updates `ans` when a sequence breaks | Updates `ans` in every iteration |
| Final return considers `ans`, `incre`, and `decre` | Final `ans` already contains the maximum |
| More explicit reset handling | Cleaner state transitions |

---

## IMPORTANT OBSERVATION

- Strictly increasing means `nums[i] < nums[i+1]`.
- Strictly decreasing means `nums[i] > nums[i+1]`.
- Equal adjacent elements break both increasing and decreasing subarrays.
- Every new subarray starts with length 1.
- The last active subarray must also be considered when using Approach 1.

**Both approaches have O(n) time and O(1) auxiliary space complexity.**
