# Problem: [Word Search](https://leetcode.com/problems/word-search/)

# WORD SEARCH

**Approach: Backtracking (DFS)**

1. Traverse the entire board using two nested loops.
2. If the current cell matches the first character of the word, start DFS from that cell.
3. In the recursive function:
   - Check whether `idx == word.size()`. If true, the complete word has been found.
   - Check whether the current position is out of bounds.
   - Check whether the current cell matches `word[idx]`.
4. If the character matches:
   - Store the current character in a temporary variable.
   - Mark the current cell as visited using `$` to prevent revisiting the same cell.
5. Recursively explore all four adjacent directions:
   - Down `(i+1, j)`
   - Up `(i-1, j)`
   - Right `(i, j+1)`
   - Left `(i, j-1)`
6. If any recursive call returns `true`, the word exists in the board.
7. Restore the original character before returning from the recursive function. This is the backtracking step.

**Time Complexity:** `O(m × n × 4 × 3^(L-1))`

**Space Complexity:** `O(L)` for the recursion stack, where `L` is the length of the word.

**Key Concept:** Backtracking + DFS

**Important:** A cell cannot be visited more than once in a single path, but it can be visited again in a different path. That's why we restore the original character after exploring a path.