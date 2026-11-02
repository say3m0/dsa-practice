# Problem: [Minimum Moves to Equal Array Elements II](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/)

## 3 Approaches ===>

---

### First Approach : Sorting + Brute Force

1. First, sort the array.
2. Find the median element.
3. Traverse the whole array and calculate the absolute difference between each element and the median.
4. Sum all the differences to get the minimum moves.

**TIME COMPLEXITY :** O(n log n)

**SPACE COMPLEXITY :** O(1) auxiliary space (excluding sorting stack space).

**Note:** For both odd and even array sizes, use `nums[n/2]` as the median. The `n/2 - 1` index in the above code is incorrect for odd-sized arrays.

---

### Second Approach : Sorting + Two Ends

1. First, sort the array.
2. Select the median element using `nums[n/2]`.
3. Use two pointers/indices to compare elements from both ends of the array.
4. Calculate the distance of both elements from the median and add them to the total moves.
5. Repeat until all pairs are processed.

**TIME COMPLEXITY :** O(n log n)

**SPACE COMPLEXITY :** O(1) auxiliary space (excluding sorting stack space).

---

### Third Approach : nth_element()

1. Use `nth_element()` to place the median at its correct sorted position without sorting the entire array.
2. The element at index `n/2` will be the median.
3. Traverse the whole array and calculate the absolute difference between each element and the median.
4. Sum all differences to get the minimum moves.

**TIME COMPLEXITY :** Average O(n)

**SPACE COMPLEXITY :** O(1) auxiliary space.

---

### Key Observation

The minimum number of moves is obtained by making every element equal to the median.

- `sort()` gives the median after sorting the entire array.
- `nth_element()` finds the median without fully sorting the array.

**Best Approach:** Approach 3 (`nth_element()`) because it has average O(n) time complexity.
