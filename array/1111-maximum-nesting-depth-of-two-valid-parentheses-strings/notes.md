Problem : https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/

Maximum Nesting Depth of Two Valid Parentheses Strings

3 Approaches===>

First approach : Stack with Pair

1. Use a stack of pairs (char, index) to simulate tracking the nested structure of parentheses.

2. When encountering '(, push it onto the stack. The current stack size represents the current nesting depth. Assign ans[i] = st.size() % 2 to distribute parentheses into group 0 or group 1 based on depth parity.

3. When encountering ')', assign ans[i] = st.size() % 2 first and then pop the top element from the stack as it closes a pair.
--
--
TIME COMPLEXITY : O(n)
SPACE COMPLEXITY : O(n) due to stack storage

--
Second approach : Counter / Depth Tracking (Space Optimized)

1. Since we do not need to retrieve specific element properties from the stack, we can replace the stack with a simple integer counter depth.

2. Increment depth when ( is encountered and assign depth % 2 to the current position.

3. Assign depth % 2 to the current position when ) is encountered, then decrement depth.
--
--
TIME COMPLEXITY : O(n)
SPACE COMPLEXITY : O(1) (excluding output array)



—

Third approach : Bitwise XOR & Parity Matching

1. Observe that alternating group assignment depends on the parity of the index i and whether the character is '(' or ')'.

2. Check (seq[i] == '('), which yields 1 for '(' and 0 for ')'.

3. Perform a Bitwise XOR with index parity (i & 1) to automatically assign alternating groups 0 and 1 to balance depth.
--
--
TIME COMPLEXITY : O(n)
SPACE COMPLEXITY : O(1) (excluding output array)