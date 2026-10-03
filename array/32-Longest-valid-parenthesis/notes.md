Problem : https://leetcode.com/problems/longest-valid-parentheses/

**Longest Valid Parentheses**

3 Approaches===>
--
*First approach* : Stack Approach (Index Tracking)
--
1. Use a stack to store the indices of parentheses and push -1 initially as a baseline boundary.
2. Traverse the string: if '(' appears, push its index onto the stack.
3. If ')' appears, pop from the stack. If the stack becomes empty, push the current index as a new invalid boundary.
4. If the stack is not empty after popping, calculate valid length using (current_index - stack.top()) and update the max length.
--
--
TIME COMPLEXITY : O(n)
SPACE COMPLEXITY : O(n)

*Second approach* : Two Counters (Two Pass - Left to Right & Right to Left)
--
1. Maintain 'left' and 'right' counters and iterate through the string twice (Left-to-Right & Right-to-Left).
2. In the Left-to-Right pass, increment 'left' for '(' and 'right' for ')'. If left == right, update max length. If right > left, reset both counters to 0.
3. In the Right-to-Left pass, perform the same logic, but reset counters to 0 if left > right (handling extra '(' cases).
4. Return the maximum valid length found from both passes without using any extra stack space.
--
--
TIME COMPLEXITY : O(n)
SPACE COMPLEXITY : O(1)

*Third approach* : Dynamic Programming (Bottom-Up)
--
1. Define dp[i] array where dp[i] stores the length of the longest valid parentheses substring ending exactly at index 'i'.
2. Initialize all dp[i] = 0. Any index with '(' will automatically have dp[i] = 0 because a valid substring can never end with '('.
3. Case 1 - Simple Pair "...()": If s[i] == ')' and s[i-1] == '(', they directly form a pair of length 2. Add any valid length before this pair: 
   dp[i] = dp[i-2] + 2
4. Case 2 - Nested Structure "...))": If s[i] == ')' and s[i-1] == ')', check the character before the inner valid substring, located at index: 
   prev_idx = i - dp[i-1] - 1
   If s[prev_idx] == '(', it forms a larger valid outer boundary. Add the inner length, outer pair (2), and any prior valid length before prev_idx: 
   dp[i] = dp[i-1] + 2 + dp[prev_idx - 1]
--
--
TIME COMPLEXITY : O(n)
SPACE COMPLEXITY : O(n)