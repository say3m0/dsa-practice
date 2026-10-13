
Problem : https://leetcode.com/problems/maximum-alternating-sum-of-squares/

# Maximum Alternating Sum of Squares

**2 Approaches ==>**

---

**First Approach : Sorting + Greedy**

**Main Idea:**
To maximize the alternating sum of squares, we need to place larger absolute values at positive positions and smaller absolute values at negative positions.

**Steps:**

1. Convert all numbers into their absolute values because squaring removes the negative sign.

2. Sort the array in ascending order.

3. Use two pointers:
   - i = 0 (smallest element)
   - j = n - 1 (largest element)

4. Add the square of the largest element and subtract the square of the smallest element.

5. Move both pointers toward the middle.

6. If one middle element remains (odd length), add its square to the answer.

---

**TIME COMPLEXITY : O(n log n)**

**SPACE COMPLEXITY : O(log n)** (Sorting stack)

---

**Second Approach : Greedy + Quickselect (nth_element)**

**Main Idea:**
We do not need to sort the entire array.

We only need to separate the smaller and larger absolute values.

- Smallest floor(n/2) elements ==> Negative squares
- Largest ceil(n/2) elements ==> Positive squares

We can use nth_element() to partition the array efficiently.

**Steps:**

1. Convert every element into its absolute value.

2. Calculate mid = n / 2.

3. Use nth_element() to partition the array around mid.

4. Elements before mid belong to the smaller half.

5. Elements from mid to the end belong to the larger half.

6. Traverse the array:
   - If i < mid, subtract nums[i]^2.
   - Otherwise, add nums[i]^2.

7. Return the maximum alternating sum.

---

**Why nth_element()?**

- Sorting arranges every element in order.
- nth_element only partitions the array around a selected index.
- We do not care about the order inside each partition.
- Therefore, full sorting is unnecessary.

---

**TIME COMPLEXITY : O(n) Average**

**SPACE COMPLEXITY : O(1)** (Typical auxiliary space)


---

**Comparison:**

| Approach | Time Complexity | Space Complexity |
|----------|-----------------|------------------|
| Sorting + Greedy | O(n log n) | O(log n) |
| Quickselect + Greedy | O(n) Average | O(1) Typical |

**Key Observation:**

To maximize the alternating sum of squares, assign the largest absolute values to positive positions and the smallest absolute values to negative positions.

The order within the positive and negative groups does not matter.

**Note:** nth_element() has average linear complexity, not guaranteed worst-case O(n). Both implementations assume abs(nums[i]) fits in int.
