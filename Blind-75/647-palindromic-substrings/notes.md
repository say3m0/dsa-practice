 Problem : [Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/)

# **PALINDROMIC SUBSTRINGS**

**2 Approaches ===>**

---

**First approach :** Dynamic Programming (DP)

1. Create a 2D boolean array `t[n][n]` where `t[i][j] = true` means the substring `s[i...j]` is a palindrome (both indices inclusive).

2. Traverse all possible substring lengths using an outer loop `L` from `1` to `n`.

3. For each substring, calculate the starting index `i` and ending index `j = i + L - 1`.

4. Check three conditions:

   - **Single character (`i == j`)** : Always a palindrome, so `t[i][j] = true`.
   - **Two characters (`i+1 == j`)** : Check whether `s[i] == s[j]`.
   - **More than two characters** : Check whether `s[i] == s[j]` AND the inner substring `t[i+1][j-1]` is already a palindrome.

5. Add `t[i][j]` to `count`. If it is true, one palindrome is found.

6. Finally, return `count`.

**TIME COMPLEXITY :** O(n²)

**SPACE COMPLEXITY :** O(n²)

---

**Second approach :** Expand Around Center

1. Every palindrome has a center. There are two types of centers:

   - **Odd length:** A single character is the center.
   - **Even length:** The gap between two adjacent characters is the center.

2. Traverse the string using an outer loop `i` from `0` to `n-1`.

3. For each index `i`, perform two expansions:

   **Odd length palindrome:**
   - Initialize `j = i` and `k = i`.
   - Check whether `j >= 0`, `k < n` and `s[j] == s[k]`.
   - If all conditions are true, increment `count`.
   - Move outward: `j--` and `k++`.

   **Even length palindrome:**
   - Initialize `j = i` and `k = i+1`.
   - Follow the same checking and expansion process.

4. Every successful expansion represents one new palindrome, so increment `count` each time.

5. Finally, return `count`.

**TIME COMPLEXITY :** O(n²)

**SPACE COMPLEXITY :** O(1)

---

**Key Concepts:**

- **Dynamic Programming:** A larger palindrome depends on its inner substring being a palindrome.
- **Expand Around Center:** Every successful expansion gives one new palindrome.

**Important:**

- DP approach processes shorter substrings before longer substrings.
- Expand Around Center must consider both odd and even length palindromes.
- Both approaches have O(n²) time complexity, but Expand Around Center uses O(1) auxiliary space.
- REMEMBER THE DP APPROACH AS A BLUEPRINT FOR SOLVING PROBLEMS BASED ON PALINDROME.