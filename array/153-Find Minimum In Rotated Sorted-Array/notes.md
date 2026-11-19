# Problem: [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)

## FIND MINIMUM IN ROTATED SORTED ARRAY

**2 Approaches ===>**

---

### First Approach: Neighbour Checking + Boundary Checking

1. Apply Binary Search using `left`, `right` and `mid`.
2. Check whether `mid` is the first or last index. Handle these boundary cases separately.
3. For middle elements, compare `nums[mid]` with both neighbours.
4. If `nums[mid]` is smaller than both neighbours, it is the minimum element.
5. Otherwise, use the rotated sorted array property to decide the search direction:
   - If `nums[mid] >= nums[0]`, minimum is on the right side. So, `left = mid + 1`.
   - Otherwise, minimum is on the left side. So, `right = mid - 1`.
     \

**TIME COMPLEXITY:** O(log n)

**SPACE COMPLEXITY:** O(1)

---

### Second Approach: Binary Search (Standard Approach)

1. Initialize `left = 0` and `right = n - 1`.

2. Calculate the middle index using `mid = left + (right - left) / 2`.

3. Compare `nums[mid]` with the last element `nums[n-1]`.

4. There are two possible cases:

   - **Case 1:** If `nums[mid] > nums[n-1]`, the minimum element must be on the right side of `mid`. So, `left = mid + 1`.
   - **Case 2:** If `nums[mid] <= nums[n-1]`, the minimum element may be `mid` itself or on its left side. So, `right = mid`.

5. Continue Binary Search until `left == right`.

6. Return `nums[left]`.

**Important:** We use `right = mid` instead of `right = mid - 1` because `mid` itself can be the minimum element.

**TIME COMPLEXITY:** O(log n)

**SPACE COMPLEXITY:** O(1)

---