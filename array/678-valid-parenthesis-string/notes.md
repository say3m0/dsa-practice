Problem : https://leetcode.com/problems/valid-parenthesis-string/

**VALID PARENTHESIS STRING**

2 Approaches===>
--
*First approach* : Stack Approach (Index Tracking)
--
1. Use two stacks: openBrackets to store indices of '(' and stars to store indices of '*'.
2. Traverse the string: push indices for '(' and '*' into their respective stacks. For ')', try popping from openBrackets first; if empty, pop from stars. If both are empty, return false.
3. After the loop, match remaining '(' with '*'. Ensure openBrackets.top() < stars.top() so that '*' appears after '(' to balance it.
4. If all '(' are matched (i.e., openBrackets is empty), return true; otherwise, return false.
--
--
TIME COMPLEXITY : O(n)
SPACE COMPLEXITY : O(n) because of two stacks

*Second approach* : Two-Pass Greedy Approach / Two Pointer
--
1. Perform a left-to-right pass treating both '(' and '*' as open brackets (+1) and ')' as (-1). If the balance ever drops below 0, return false (too many closing brackets).
2. Perform a right-to-left pass treating both ')' and '*' as closing brackets (+1) and '(' as (-1). If the balance ever drops below 0, return false (too many opening brackets).
3. If both passes complete successfully without balance dropping below zero, return true.
--
--
TIME COMPLEXITY : O(n)
SPACE COMPLEXITY : O(1)