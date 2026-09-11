**Problem :** https://leetcode.com/problems/search-in-rotated-sorted-array/description/

****Search in Rotated Sorted Array****

**Algorithm**

1. Initialize:

   * `left = 0`
   * `right = nums.length - 1`

2. While `left <= right`:

   * Calculate `mid`.
   * If `nums[mid] == target`, return `mid`.

3. If the left half is sorted:

   * Check whether `target` lies between `nums[left]` and `nums[mid]`.
   * If yes, move `right = mid - 1`.
   * Otherwise, move `left = mid + 1`.

4. Otherwise, the right half is sorted:

   * Check whether `target` lies between `nums[mid]` and `nums[right]`.
   * If yes, move `left = mid + 1`.
   * Otherwise, move `right = mid - 1`.

5. If the loop finishes, the target does not exist, so return `-1`.

## Complexity Analysis

* **Time Complexity:** `O(log n)` — each iteration eliminates approximately half of the remaining search space.
* **Space Complexity:** `O(1)` — only a constant number of variables are used.
