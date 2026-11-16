# 2243. Calculate Digit Sum of a String

**Problem Link:** https://leetcode.com/problems/calculate-digit-sum-of-a-string/

---

## Approach: String Simulation (While Loop + Nested For Loop)

### Idea

Repeatedly divide the string into consecutive groups of size `k`. Calculate the sum of the digits in each group and concatenate those sums to create a new string.

Continue this process until the string's length becomes less than or equal to `k`.

### Steps

1. Run a `while` loop while `s.size() > k`.
2. Create an empty string `t` to store the result of the current round.
3. Use a `for` loop with `i += k` to select each group.
4. For every group, initialize `x = 0`.
5. Use an inner loop to traverse the current group:
   - Start from index `i`.
   - Continue while `j < i + k` and `j < s.size()`.
   - Convert each character into its numeric digit using `s[j] - '0'`.
   - Add the digit to `x`.
6. Convert the group sum into a string using `to_string(x)` and append it to `t`.
7. After processing all groups, update `s = t`.
8. When the `while` loop ends, return `s`.

---

## Time Complexity

Let `n` be the initial length of the string.

- In each round, every character is processed once.
- The string length decreases approximately by a factor of `k` after each round.
- Number of rounds: `O(log_k n)`.

**Overall Time Complexity: `O(n log_k n)`**

## Space Complexity

`O(n)` — A new string is created in each round to store the grouped digit sums.

---
