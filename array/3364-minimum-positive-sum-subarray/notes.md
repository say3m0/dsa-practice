# 3364. Minimum Positive Sum Subarray

**Problem Link:** https://leetcode.com/problems/minimum-positive-sum-subarray/

---

## Approach 1: Brute Force (Nested Loop)

### Idea

Generate all possible subarrays whose length is between `l` and `r`.

Calculate the sum of each subarray. If the sum is positive, update the minimum positive sum.

### Steps

1. Initialize `result = 1e9` to store the minimum positive sum.
2. Run an outer loop using `i` to select the starting index.
3. Initialize `sum = 0` for each starting index.
4. Run an inner loop to extend the subarray.
5. Add each element to `sum`.
6. Check two conditions:
   - Subarray length must be at least `l`.
   - Subarray length must not exceed `r`.
7. If `sum > 0`, update `result = min(result, sum)`.
8. If no positive sum is found, return `-1`.

### Complexity Analysis

**Time Complexity:** `O(n * r)`

- Outer loop runs `n` times.
- Inner loop runs at most `r` times.

**Space Complexity:** `O(1)`

- Only a few extra variables are used.

---

## Approach 2: Prefix Sum + Nested Loop

### Idea

Instead of calculating the subarray sum by adding elements one by one, use a Prefix Sum array.

The prefix sum allows us to calculate any subarray sum in `O(1)` time.

### Prefix Sum Formula

For a subarray from index `i` to index `j`:

`sum = prefixSum[j] - prefixSum[i-1]`

If `i == 0`, then:

`sum = prefixSum[j]`

### Steps

1. Calculate the prefix sum array.
2. Initialize `result = INT_MAX`.
3. Use an outer loop to select the starting index `i`.
4. Use an inner loop to generate subarrays of different lengths from `l` to `r`.
5. Calculate the ending index:

   `j = i + len - 1`

6. Calculate the subarray sum using the prefix sum formula.
7. If the sum is positive, update the minimum result.
8. If no positive sum is found, return `-1`.

### Complexity Analysis

**Time Complexity:** `O(n * r)`

- Building the prefix sum array takes `O(n)`.
- Generating all valid subarrays takes `O(n * r)`.
- Each subarray sum is calculated in `O(1)`.

**Space Complexity:** `O(n)`

- The prefix sum array requires `O(n)` extra space.


---

## Important Observations

1. We only need to consider subarrays whose lengths are between `l` and `r`.
2. A subarray is valid only when its sum is strictly positive.
3. The answer is the minimum among all valid positive subarray sums.
4. Prefix Sum does not improve the overall asymptotic time complexity here because the brute-force approach already calculates each extended subarray sum in `O(1)` time.
5. Prefix Sum is useful when we need to calculate arbitrary range sums repeatedly.