Understood. You wanted **only the Markdown content**, matching your demo format.

**Problem :** [https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

****Find First and Last Position of Element in Sorted Array****

2 Approaches===>

--

**First approach** : LOWER_BOUND + UPPER_BOUND

--

1. Use `lower_bound()` to find the first position of the target.

2. Use `upper_bound()` to find the position just after the last occurrence of the target.

3. Check whether the target actually exists by verifying `lower_bound()` is not `end()` and the element at that position is equal to the target.

4. If the target exists, the first position is the index returned by `lower_bound()` and the last position is the index returned by `upper_bound() - 1`.

5. If the target does not exist, return `[-1, -1]`.

--

--

**TIME COMPLEXITY : O(log n)**

**SPACE COMPLEXITY : O(1)**

--

--

**Second approach** : TWO BINARY SEARCH

--

1. Use one binary search to find the first occurrence of the target.

2. When the target is found, store its index and continue searching toward the left side to find an earlier occurrence.

3. Use another binary search to find the last occurrence of the target.

4. When the target is found, store its index and continue searching toward the right side to find a later occurrence.

5. If the target is not found, return `[-1, -1]`.

--

--

**TIME COMPLEXITY : O(log n)**

**SPACE COMPLEXITY : O(1)**
