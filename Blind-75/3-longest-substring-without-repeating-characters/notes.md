# Longest Substring Without Repeating Characters

**Problem Link:** [LeetCode 3 - Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)

---

## Solution-1: Sliding Window + Map (Last Seen Index)

### Thought Process

1. Take a map to store each character and its latest index.

2. Traverse the string using a loop.

3. If the current character is new, insert it into the map with its current index.

4. Otherwise, identify the latest valid boundary.

   ```cpp
   boundary = max(boundary, mp[s[i]] + 1);
   ```

   **Why `max()`?**

   Suppose the string is `"abba"`.

   - When we encounter the second `b` (index 2), the boundary moves to index 2.
   - When we encounter the last `a` (index 3), its previous index is 0.
   - If we directly use `mp[s[i]] + 1`, the boundary becomes 1.

   But is index 1 the latest valid boundary? NO. The latest boundary is still index 2.

   Therefore, we must take the maximum to ensure that the boundary never moves backward.

5. Update the character's latest index.

   ```cpp
   mp[s[i]] = i;
   ```

   **Why???**

   We need to store the latest position of each character.

   For example, in `"abca"`, the latest position of `a` becomes index 3 instead of index 0.

   This latest position helps us identify the correct boundary when that character appears again.

6. Calculate the current valid window length and update the answer.

   ```cpp
   ans = max(ans, i - boundary + 1);
   ```

   **Why `+1`?**

   Because both the starting index (`boundary`) and ending index (`i`) are included in the substring.

**Time Complexity:** O(n log k), where k is the number of distinct characters.

**Space Complexity:** O(k), for storing distinct characters in the map.

---

## Solution-2: Sliding Window + Fixed-size Hash Array

### Thought Process

1. Take a fixed-size vector of size 256 and initialize every element with `-1`.

   ```cpp
   vector<int> v(256, -1);
   ```

   Here, each index represents a character, and its value stores the character's latest position.

   Initially, `-1` means the character has never appeared.

2. Take two pointers:

   - `i` = starting index of the current valid window.
   - `j` = current character's index.

   Initially, both are 0.

3. Traverse the string using `j`.

4. Check whether the current character has appeared before.

   ```cpp
   if(v[s[j]] != -1)
   ```

   If its value is `-1`, the character has never appeared before.

   Otherwise, it has appeared previously.

5. Check whether the previous occurrence is inside the current window.

   ```cpp
   if(v[s[j]] >= i)
   ```

   **Why???**

   A character may have appeared before but its previous occurrence may be outside the current window.

   Example: `"abba"`

   When we encounter the last `a`:

   - Previous index of `a` = 0.
   - Current window starts at index 2.
   - Since `0 < 2`, the previous `a` is outside the current window.

   Therefore, we should not move `i` backward.

6. If the previous occurrence is inside the current window, update the starting pointer.

   ```cpp
   i = v[s[j]] + 1;
   ```

   This is the same boundary-update logic used in Solution-1.

   The new window must start immediately after the previous occurrence of the duplicate character.

7. Calculate the current window length.

   ```cpp
   ans = max(ans, j - i + 1);
   ```

8. Update the latest index of the current character.

   ```cpp
   v[s[j]] = j;
   ```

   This is important because we always need the latest occurrence of a character.

9. Move the right pointer forward.

   ```cpp
   j++;
   ```

**Time Complexity:** O(n)

**Space Complexity:** O(1), because the vector always contains 256 elements.

*Note: This implementation assumes byte/ASCII-compatible input. For fully safe byte indexing in C++, use `v[(unsigned char)s[j]]`.*

---

## Comparison Between Both Solutions

| Criteria         | Solution-1      | Solution-2          |
| ---------------- | --------------- | ------------------- |
| Data Structure   | `map`           | Fixed-size `vector` |
| Stores           | Last seen index | Last seen index     |
| Time Complexity  | O(n log k)      | O(n)                |
| Space Complexity | O(k)            | O(1)                |
| Lookup           | O(log k)        | O(1)                |
|                  |                 |                     |
