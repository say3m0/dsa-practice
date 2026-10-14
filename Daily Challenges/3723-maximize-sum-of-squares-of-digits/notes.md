Problem: [Maximize Sum of Squares of Digits](https://leetcode.com/problems/maximize-sum-of-squares-of-digits/)

**MAXIMIZE SUM OF SQUARES OF DIGITS**

2 Approaches ===>

---

**First Approach: Greedy + Loop**

1. Check if `sum > num * 9`. If true, return an empty string because constructing a valid number is impossible.
2. Traverse through the digit positions using a loop.
3. At each position, take the maximum possible digit using `min(9, remainingSum)`.
4. Append the selected digit to the result and subtract it from the remaining sum.
5. Once the required sum is reached, fill the remaining positions with `0`.
6. Return the resulting string.

**TIME COMPLEXITY:** `O(num)`  
**SPACE COMPLEXITY:** `O(num)` because of the result string.

---

**Second Approach: Greedy + Mathematical Construction**

1. Check if `sum > num * 9`. If true, return an empty string.
2. Calculate `nines = sum / 9` to determine how many `9`s are needed.
3. Calculate `rem = sum % 9` to find the remaining digit.
4. Construct the result by appending `nines` number of `9`s.
5. If `rem > 0`, append the remaining digit.
6. Fill the remaining positions with `0` to make the total length equal to `num`.
7. Return the resulting string.

**TIME COMPLEXITY:** `O(num)`  
**SPACE COMPLEXITY:** `O(num)` because of the result string.

---

**Key Observation:**

To maximize the sum of squares, we should concentrate the digit sum into larger digits rather than distribute it evenly.

**Example:**

`num = 5, sum = 23`

`23 = 9 × 2 + 5`

Result: `"99500"`

**Optimal Approach:** Greedy + Mathematical Construction.

Both approaches are optimal with `O(num)` time complexity because constructing a string of length `num` requires at least `O(num)` time.