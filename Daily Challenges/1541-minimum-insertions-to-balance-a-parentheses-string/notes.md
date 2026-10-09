## Complexity Comparison: Minimum Insertions to Balance a Parentheses String

Problem Link: [1541. Minimum Insertions to Balance a Parentheses String](https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/)

| Solution | Time Complexity (TC) | Space Complexity (SC) | Description |
| :--- | :--- | :--- | :--- |
| **1. Stack-Based Solution** *(Your 1st code)* | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ | Scans the string once, but uses an extra `std::stack<char>` requiring auxiliary memory up to linear space. |
| **2. Open-Counter Solution** *(Your 2nd code)* | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ | Replaces the stack with an `open` counter variable, optimizing space down to constant memory, though it uses manual index skipping (`i++`). |
| **3. Optimal Balance-Counter Solution** *(Proposed code)* | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ | Cleanest approach using a `bal` variable to track required closing brackets directly. Runs in constant space with no index manipulation. |

> **Note:** $n$ represents the length of the input string `s`.