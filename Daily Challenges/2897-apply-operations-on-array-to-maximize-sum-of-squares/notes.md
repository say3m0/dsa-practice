
Problem : https://leetcode.com/problems/apply-operations-on-array-to-maximize-sum-of-squares/

# Apply Operations on Array to Maximize Sum of Squares

**Approach : Greedy + Bit Manipulation**

**Main Idea:**
We need to maximize the sum of squares of k elements.

The operation allows us to redistribute set bits between two numbers using AND and OR.

To maximize the sum of squares, we should combine as many set bits as possible into larger numbers.

---

**Steps:**

1. Create a count array of size 32 to store the frequency of each set bit.

2. Traverse every number in nums and check each bit position (0 to 31).

3. If the b-th bit is set, increment count[b].

4. Run a loop k times to construct k numbers.

5. For each number, start with curr = 0 and traverse all 32 bit positions.

6. If count[b] > 0:
   - Set the b-th bit in curr using bitwise OR.
   - Decrease count[b] by 1.

7. Add curr * curr to the result and take modulo (1e9 + 7).

8. Return the final result.

---

**Why Greedy Works?**

- The AND and OR operations preserve the total count of set bits at every position.
- Combining set bits into larger numbers maximizes the sum of squares.
- Therefore, we greedily construct each number using all currently available set bits.

---

**TIME COMPLEXITY : O(32 * n + 32 * k) = O(n + k)**

**SPACE COMPLEXITY : O(32) = O(1)**

---