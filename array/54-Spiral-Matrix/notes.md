**Problem :** https://leetcode.com/problems/spiral-matrix/description/

****Spiral Matrix Traversal****

Approach ===>
--
**Optimal Approach** : BOUNDARY POINTERS (4-POINTER TRAVERSAL)

--
1. Maintain four boundary pointers: `top = 0`, `down = n - 1`, `left = 0`, and `right = m - 1`.
2. Traverse the matrix layer by layer in a clockwise spiral using a `while(left <= right && top <= down)` loop.
3. Step 1 (Top Row): Move from `left` to `right` along row `top`, then increment `top++`.
4. Step 2 (Right Column): Move from `top` to `down` along column `right`, then decrement `right--`.
5. Step 3 (Bottom Row): Check `if (down >= top)`. Move from `right` to `left` along row `down`, then decrement `down--`.
6. Step 4 (Left Column): Check `if (left <= right)`. Move from `down` to `top` along column `left`, then increment `left++`.
7. Repeat the cycle until all elements are traversed and collected in the result array.
--
--
**WHY BOUNDARY CHECKS ARE NEEDED :**
* `top++` and `right--` modify the boundaries mid-cycle.
* `if (down >= top)` prevents duplicate traversal of the same row in $1 \times M$ matrices.
* `if (left <= right)` prevents duplicate traversal of the same column in $N \times 1$ matrices.
--
--
**TIME COMPLEXITY : O(n × m)**
**SPACE COMPLEXITY : O(1)** (Excluding the output vector)
--