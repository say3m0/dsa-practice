**Problem :** https://leetcode.com/problems/rotate-image/description/

****Rotate Image****

2 Approaches===>
--
**First approach** : TRANSPOSE + ROW-WISE REVERSE

--
1. First transpose the matrix.
2. For transpose, swap `matrix[i][j]` with `matrix[j][i]`.
3. Start the inner loop from `j = i + 1` so that each pair is swapped only once.
4. After transposing, reverse every row of the matrix.
5. For row-wise reverse, swap the first element with the last element, the second element with the second-last element, and so on.
6. After these two operations, the matrix is rotated 90 degrees clockwise.
--
--
**TIME COMPLEXITY : O(n²)**
**SPACE COMPLEXITY : O(1)**
--
--
**Second approach** : 4-WAY SWAP
--
1. Rotate the matrix layer by layer, starting from the outermost layer.
2. Use `i` to represent the current layer.
3. Use `j` to traverse the elements within the current layer.
4. For every position, perform a 4-way cyclic swap between:
* Top-left
* Bottom-left
* Bottom-right
* Top-right
5. Use one temporary variable to store one element while moving the other three elements.
6. Continue this process for all elements in the current layer.
7. Move to the next inner layer until all layers are rotated.
--
--
**TIME COMPLEXITY : O(n²)**
**SPACE COMPLEXITY : O(1)**
