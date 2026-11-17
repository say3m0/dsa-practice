
Problem : [https://leetcode.com/problems/maximum-subarray/](https://leetcode.com/problems/maximum-subarray/)

# MAXIMUM SUBARRAY

**3 Approaches ===>**

---

**First Approach : PREFIX SUM + MINIMUM PREFIX SUM**

1. Maintain a running prefix sum (`prepSum`) by continuously adding the current element.
2. Maintain the minimum prefix sum (`minSum`) encountered so far.
3. For every index, calculate `prepSum - minSum` to get the maximum subarray sum ending at the current position.
4. Update the answer and then update `minSum`.

**TIME COMPLEXITY : O(n)**

**SPACE COMPLEXITY : O(1)**

---

**Second Approach : KADANE'S ALGORITHM**

1. Maintain a running subarray sum (`freqSum`) and a global maximum sum (`maxSum`).
2. Add the current element to `freqSum`.
3. Update `maxSum` after every addition.
4. If `freqSum` becomes negative, reset it to zero because a negative running sum will decrease the sum of any future subarray.
5. Continue until all elements are traversed.

**TIME COMPLEXITY : O(n)**

**SPACE COMPLEXITY : O(1)**

---

**Third Approach : DIVIDE AND CONQUER**

1. Divide the array into two halves using the middle index.
2. Recursively find the maximum subarray sum in the left half.
3. Recursively find the maximum subarray sum in the right half.
4. Find the maximum crossing subarray sum:
   - Calculate the maximum suffix sum of the left half.
   - Calculate the maximum prefix sum of the right half.
   - Add both sums to get the crossing maximum.
5. Return the maximum among Left Maximum, Right Maximum and Crossing Maximum.

**TIME COMPLEXITY : O(n log n)**

**SPACE COMPLEXITY : O(log n)** because of recursion stack.
