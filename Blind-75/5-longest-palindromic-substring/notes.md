# 5. Longest Palindromic Substring

**Problem Link:** https://leetcode.com/problems/longest-palindromic-substring/

---

## Approach 1: Expand Around Center

### Idea

A palindrome can have either an odd-length center or an even-length center.

Instead of checking every possible substring, consider each index as a center and expand in both directions as long as the characters match.

There are two cases:

**Case 1: Odd Length Palindrome**

- Initialize two pointers at the same index: `j = i`, `k = i`.
- Expand towards both directions.
- Continue while `s[j] == s[k]` and both pointers are within valid boundaries.

Examples: `"aba"`, `"racecar"`, `"bab"`.

**Case 2: Even Length Palindrome**

- Initialize two pointers at adjacent indices: `j = i`, `k = i + 1`.
- Expand towards both directions.
- Continue while `s[j] == s[k]` and both pointers are within valid boundaries.

Examples: `"abba"`, `"noon"`, `"nnnn"`.

### Steps

1. Initialize `maxLen = 0` to store the maximum palindrome length.
2. Initialize `start = 0` to store the starting index of the longest palindrome.
3. Run a `for` loop to consider every index as a possible center.
4. First, check the Odd Length case:
   - Set `j = i` and `k = i`.
   - Expand both pointers while the characters match.
   - Calculate the current palindrome length using `k - j + 1`.
   - If the current length is greater than `maxLen`, update `maxLen` and `start`.
   - Move `j` left and `k` right.
5. Next, check the Even Length case:
   - Set `j = i` and `k = i + 1`.
   - Expand both pointers while the characters match.
   - Calculate the current palindrome length.
   - If the current length is greater than `maxLen`, update `maxLen` and `start`.
   - Move `j` left and `k` right.
6. Repeat the process for every index.
7. Finally, return the longest palindrome using `s.substr(start, maxLen)`.

### Complexity Analysis

**Time Complexity: O(n²)**

- The outer loop runs `n` times.
- For each index, we perform two expansion operations.
- Each expansion can take up to `O(n)` time.

Therefore, overall time complexity is `O(n²)`.

**Space Complexity: O(1)**

- Only a few extra variables are used.
- No additional data structure is required.

---

## Approach 2: Recursion + Memoization (Top-Down DP)

### Idea

Use recursion to check whether a substring is a palindrome.

For a substring from index `l` to `r`:

- If `l >= r`, the substring is a palindrome.
- If `s[l] == s[r]`, check the inner substring recursively.
- Otherwise, it is not a palindrome.

Use a 2D DP array `t[l][r]` to store previously calculated results and avoid repeated calculations.

After defining the palindrome-checking function, generate all possible substrings and find the longest valid palindrome.

### Recursive Logic

For a substring `s[l...r]`:

1. Base Case:
   - If `l >= r`, return `true`.
2. Memoization:
   - If `t[l][r]` is already calculated, return its stored value.
3. Character Matching:
   - If `s[l] == s[r]`, recursively check the inner substring `solve(s, l+1, r-1)`.
4. If the characters do not match, return `false`.

### Steps

1. Create a 2D DP array `t[1001][1001]`.
2. Initialize the entire DP array with `-1`.
3. Initialize `maxlen = INT_MIN` to store the maximum palindrome length.
4. Initialize `startingIndex = 0` to store the starting index of the longest palindrome.
5. Use two nested loops to generate all possible substrings:
   - Outer loop selects the starting index `i`.
   - Inner loop selects the ending index `j`.
6. For every substring, call the recursive function `solve(s, i, j)`.
7. If the substring is a palindrome:
   - Calculate its length using `j - i + 1`.
   - Compare it with `maxlen`.
   - If the current length is greater, update `maxlen` and `startingIndex`.
8. After checking all possible substrings, return `s.substr(startingIndex, maxlen)`.

### Complexity Analysis

**Time Complexity: O(n²)**

- There are `O(n²)` possible substrings.
- Memoization ensures each `(l, r)` state is calculated at most once.
- Each recursive state performs constant work apart from its recursive call.

Therefore, the overall time complexity is `O(n²)`.

**Space Complexity: O(n²)**

- The 2D DP array requires `O(n²)` space.
- Recursion stack can require up to `O(n)` space.

Overall auxiliary space complexity: `O(n²)`.

---

## Comparison

| Feature | Expand Around Center | Recursion + Memoization |
|---|---|---|
| Technique | Two Pointers | Top-Down DP |
| Time Complexity | O(n²) | O(n²) |
| Space Complexity | O(1) | O(n²) |
| Palindrome Checking | Expand from center | Recursive checking |
| Extra DP Array | No | Yes |
| Recursion | No | Yes |

---
