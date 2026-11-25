Problem : [https://leetcode.com/problems/smallest-unique-subarray/](https://leetcode.com/problems/smallest-unique-subarray/)

# **SMALLEST UNIQUE SUBARRAY**

**Approach : Binary Search + Sliding Window + Rolling Hash**

---

**1. Binary Search**

1. Set `l = 1` and `r = n`.
2. Calculate `mid` and check whether any unique subarray of length `mid` exists using the `check()` function.
3. If a unique subarray exists, update the result and search the left half to find a smaller length.
4. Otherwise, search the right half.

The property is monotonic: If a unique subarray exists at length `L`, a unique subarray must also exist at every greater length.

---

**2. Sliding Window**

1. Use two pointers `i` and `j` to maintain a window of fixed length (`size`).
2. Expand the window by moving `j` until its length becomes equal to `size`.
3. Process the current window.
4. Move both pointers forward to generate the next window.

TIME COMPLEXITY : O(n)

---

**3. Rolling Hash**

**Concept :**

Rolling Hash converts a sequence of elements into a single numeric hash value.

Instead of recalculating the hash of every new window from scratch, we can calculate the next window's hash using the previous window's hash.

**Normal Hash Calculation :**

For example:

```cpp
arr = [2, 3, 4]
base = 10
```

Formula:

`H = 2*10^2 + 3*10^1 + 4*10^0`

`H = 200 + 30 + 4 = 234`

So, `[2, 3, 4]` has hash value `234`.

**Rolling Hash Demonstration :**

Suppose:

```cpp
nums = [2, 3, 4, 5, 6]
base = 10
window size = 3
```

First window: `[2, 3, 4]`

`H = 234`

Next window: `[3, 4, 5]`

Instead of calculating the new hash from scratch, update the previous hash.

**Step 1 : Remove the outgoing element**

Outgoing element = `2`

`p = base^(size-1) = 10^2 = 100`

`H = 234 - (2*100)`

`H = 34`

**Step 2 : Shift the remaining elements**

`H = 34 * 10`

`H = 340`

**Step 3 : Add the incoming element**

Incoming element = `5`

`H = 340 + 5`

`H = 345`

Therefore, `[3, 4, 5]` has hash value `345`.

**General Rolling Hash Formula :**

`NewHash = (OldHash - outgoing * base^(k-1)) * base + incoming`

Where:
- `OldHash` = Previous window's hash.
- `outgoing` = Element leaving the window.
- `incoming` = New element entering the window.
- `base` = Hash base.
- `k` = Window size.

**Modular Arithmetic :**

To prevent overflow, use modulo.

`MOD = 1e9 + 7`

`p = base^(k-1) % MOD`

```cpp
hash = (hash - (p * nums[i]) % MOD + MOD) % MOD;

hash = (hash * base + nums[j]) % MOD;
```

TIME COMPLEXITY : O(1) per window update.

---

**4. Hash Map**

1. Use `unordered_map<ll, int>` to store the frequency of each subarray hash.
2. For every fixed-size window, calculate its hash using Rolling Hash.
3. Increase the frequency of that hash: `mp[hash]++`.
4. After processing all windows, check whether any hash has frequency exactly `1`.
5. If found, return `true`; otherwise, return `false`.

---

**5. Binary Exponentiation**

Use Binary Exponentiation to calculate:

`p = base^(size-1) % MOD`

This represents the positional contribution of the outgoing element.

TIME COMPLEXITY : O(log size)

---

**OVERALL COMPLEXITY :**

TIME COMPLEXITY : O(n log n) expected

SPACE COMPLEXITY : O(n)

---

**IMPORTANT NOTES :**

1. Rolling Hash avoids recalculating the entire hash for every window.
2. Sliding Window helps generate all fixed-length subarrays efficiently.
3. Binary Search finds the minimum valid subarray length.
4. Hash Collision is possible because different subarrays can produce the same hash.
5. Double Rolling Hash (two different MOD values) can reduce collision probability.
6. Use `long long` for hash and multiplication operations.

**FINAL APPROACH :**

Binary Search → Sliding Window → Rolling Hash → Hash Map → Check Unique Frequency.