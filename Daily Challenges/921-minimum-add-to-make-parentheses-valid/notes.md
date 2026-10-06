Problem : https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

MINIMUM ADD TO MAKE PARENTHESES VALID

3 Approaches===>
First approach : String Replacement / Simulation
Loop through the string as long as the substring "()" is present.

Replace or erase each occurrence of "()" from the string.

When no "()" remains, return the length of the remaining string.
--
--
TIME COMPLEXITY : O(n^2)
SPACE COMPLEXITY : O(n) because of string modification

Second approach : Stack
Iterate through each character of the string.

If an opening bracket '(' is found, push it onto the stack.

If a closing bracket ')' is found, check if the stack is non-empty. If non-empty, pop from the stack; otherwise, increment unmatched counter.

After the loop, return unmatched counter plus the size of the stack.
--
--
TIME COMPLEXITY : O(n)
SPACE COMPLEXITY : O(n) because of stack

Third approach : Balance Counter (Optimal)
Maintain two integer variables: 'balance' for open brackets and 'open_needed' for unmatched closing brackets.

Traverse through the string character by character.

If '(' appears, increment 'balance'.

If ')' appears, decrement 'balance' if balance > 0; otherwise, increment 'open_needed'.

Return (open_needed + balance) as the total minimum additions required.
--
--
TIME COMPLEXITY : O(n)
SPACE COMPLEXITY : O(1)