
**Problem:** [LeetCode – Maximum Number of Selected Elements in Array](https://leetcode.com/problems/maximum-number-of-selected-elements-in-array/)

## Approach: Sorting + HashMap DP

### 1. Main Idea

For each element, we have two possible choices:

1. Increase the element by `1`.
2. Keep the element unchanged.

Our goal is to select elements and modify them (if necessary) to create the longest possible consecutive sequence.

Example:

```cpp
[1, 2, 3, 4]
```

This is a consecutive sequence of length `4`.

### 2. DP State

We use an `unordered_map`:

```cpp
unordered_map<int, int> dp;
```

**Definition:**

`dp[x]` represents the maximum length of a consecutive sequence ending at value `x`, using the elements processed so far.

Example:

```cpp
dp[4] = 3;
```

For example: `[2, 3, 4]`.
১. প্রথম লাইন
dp[num + 1] = dp[num] + 1;


ধরো:
dp[3] = 2;
num = 3;


তাহলে,
dp[4] = dp[3] + 1;
dp[4] = 2 + 1;
dp[4] = 3;


এর অর্থ:
- আগে 3 দিয়ে শেষ হওয়া sequence-এর length ছিল ২।
- বর্তমান num = 3-কে increment করে 4 বানালাম।
- ফলে নতুন sequence-এর length হলো ৩।
২. দ্বিতীয় লাইন
dp[num] = dp[num - 1] + 1;


ধরো:
dp[2] = 2;
num = 3;


তাহলে,
dp[3] = dp[2] + 1;
dp[3] = 2 + 1;
dp[3] = 3;


এর অর্থ:
- আগে 2 দিয়ে শেষ হওয়া sequence-এর length ছিল ২।
- বর্তমান 3-কে অপরিবর্তিত রাখলাম।
- তাই sequence-এর length হলো ৩।

মূল পার্থক্যটা মনে রাখো:
- num + 1 → বর্তমান সংখ্যার value বাড়াচ্ছি।
- dp[num] + 1 → sequence-এর length বাড়াচ্ছি।

### 3. Why Sorting?

First, sort the array:

```cpp
sort(nums.begin(), nums.end());
```

Sorting ensures that smaller values are processed before larger values.

This allows us to build consecutive sequences using previously processed elements.

### 4. DP Transitions

For every `num`, we consider two possibilities.

**Case 1: Increment the Current Element**

```cpp
dp[num + 1] = dp[num] + 1;
```

- We increase the current element from `num` to `num + 1`.
- We extend an existing consecutive sequence ending at `num`.
- Therefore, the sequence length increases by `1`.

Example:

```cpp
dp[3] = 2;
num = 3;

dp[4] = dp[3] + 1;
dp[4] = 3;
```

We extend the existing sequence ending at `3` by using the current element as `4`.

**Case 2: Keep the Current Element Unchanged**

```cpp
dp[num] = dp[num - 1] + 1;
```

- We keep the current element unchanged.
- We extend an existing consecutive sequence ending at `num - 1`.
- Therefore, the sequence length increases by `1`.

Example:

```cpp
dp[2] = 2;
num = 3;

dp[3] = dp[2] + 1;
dp[3] = 3;
```

We extend the existing sequence ending at `2` by using the current element as `3`.

### 5. Update the Answer

```cpp
ans = max({ans, dp[num], dp[num + 1]});
```

We compare:

- The previous maximum answer.
- The sequence ending at `num`.
- The sequence ending at `num + 1`.

We keep the maximum length in `ans`.

### 7. Dry Run

**Input:**

```cpp
nums = [1, 1, 3, 5, 6]
```

The array is already sorted.

| num | `dp[num + 1]` update | `dp[num]` update | ans |
| --- | -------------------- | ---------------- | --- |
| 1   | `dp[2] = 1`          | `dp[1] = 1`      | 1   |
| 1   | `dp[2] = 2`          | `dp[1] = 1`      | 2   |
| 3   | `dp[4] = 1`          | `dp[3] = 3`      | 3   |
| 5   | `dp[6] = 1`          | `dp[5] = 2`      | 3   |
| 6   | `dp[7] = 2`          | `dp[6] = 3`      | 3   |

**Final Answer:**

```cpp
3
```

One optimal consecutive sequence is:

```cpp
[1, 2, 3]
```

Another optimal sequence is:

```cpp
[4, 5, 6]
```

### 8. Complexity Analysis

Let `n` be the number of elements in the array.

| Operation             | Complexity      |
| --------------------- | --------------- |
| Sorting               | `O(n log n)`    |
| DP traversal          | `O(n)` expected |
| Total Time Complexity | `O(n log n)`    |
| Space Complexity      | `O(n)`          |

- Sorting takes `O(n log n)`.
- Each HashMap operation takes `O(1)` on average.
- We process each element once.
- The HashMap can store up to `O(n)` keys.

### Important Takeaways

1. `dp[x]` represents the maximum length of a consecutive sequence ending at value `x`.
2. `dp[num + 1]` represents the sequence obtained by incrementing the current element.
3. `dp[num]` represents the sequence obtained by keeping the current element unchanged.
4. The `+1` on the right side increases the sequence length, not the element's value.
5. Sorting ensures smaller elements are processed first.
6. An uninitialized key accessed through `unordered_map::operator[]` gets a default value of `0`.

