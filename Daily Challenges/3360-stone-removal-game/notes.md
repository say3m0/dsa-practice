Problem : [https://leetcode.com/problems/stone-removal-game/](https://leetcode.com/problems/stone-removal-game/)

# **STONE REMOVAL GAME**

2 Approaches ===>

---

**First approach** : Simulation + Parity Check

1. Initialize `j = 10`, representing the number of stones to remove in the first turn.
2. Run a while loop as long as `n >= j`.
3. Subtract `j` from `n` and decrement `j` after each successful move.
4. After the loop, check `j % 2` to determine the winner.
5. If `j` is odd, Alice wins; otherwise, Bob wins.

**TIME COMPLEXITY :** O(1)

**SPACE COMPLEXITY :** O(1)

---

**Second approach** : Mathematical Formula

1. Observe that the number of stones removed in each turn follows a decreasing sequence: `10, 9, 8, 7, ...`.
2. Let `k` represent the total number of successful moves.
3. Using the sum of an arithmetic progression:

   `n = 10 + 9 + 8 + ... + (11 - k)`

4. Simplifying the equation:

   `n = k(21 - k) / 2`

5. Solving the quadratic equation:

   `k = (21 - sqrt(441 - 8*n)) / 2`

6. Check `k % 2 == 1`:
   - Odd moves → Alice wins.
   - Even moves → Bob wins.

**TIME COMPLEXITY :** O(1)

**SPACE COMPLEXITY :** O(1)

---

**Third approach** : Bitmasking (Precomputation)

1. Precompute the winning and losing states for all possible values of `n` (1 to 50).
2. Store all results in a single integer using different bit positions.
3. Use the hexadecimal constant `0x61F03F807FC00` as the precomputed bitmask.
4. Right-shift the mask by `n` positions using `>> n` to bring the required bit to the least significant position.
5. Apply `& 1` to extract that bit:
   - `1` → Alice wins.
   - `0` → Alice loses.

**TIME COMPLEXITY :** O(1)

**SPACE COMPLEXITY :** O(1)