# VALID ANAGRAM

Problem: https://leetcode.com/problems/valid-anagram/

**2 Approaches ===>**

---

**First Approach: Frequency Count**

1. Check whether the lengths of both strings are equal.
2. Create a frequency array of size 26.
3. Traverse both strings simultaneously:
   - Increment the frequency of `s[i]`.
   - Decrement the frequency of `t[i]`.
4. Check whether all frequency values are `0`.
5. If all are `0`, return `true`; otherwise, return `false`.

**TIME COMPLEXITY:** O(n)

**SPACE COMPLEXITY:** O(1)

---

**Second Approach: Sorting**

1. Check whether the lengths of both strings are equal.
2. Sort both strings.
3. Compare the two sorted strings.
4. If both strings are equal, return `true`; otherwise, return `false`.

**TIME COMPLEXITY:** O(n log n)

**SPACE COMPLEXITY:** Implementation-dependent (excluding input storage).