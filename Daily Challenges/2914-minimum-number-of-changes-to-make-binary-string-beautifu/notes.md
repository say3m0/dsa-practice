Minimum Number of Changes to Make Binary String Beautiful

Problem: LeetCode – 2914

Approach 1: Greedy (Pair-by-Pair)

Idea:

Divide the string into consecutive blocks of size 2.

Each block must contain identical characters (00 or 11).

If the two characters are different, we need exactly one change.

Count the number of such pairs.

Why block size *2* ? Because valid even length uniform string canbe divided by 2 easily.

Complexity Analysis:

Time Complexity: O(n)

Space Complexity: O(1)