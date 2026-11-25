নিচের Markdown-টি সরাসরি copy করে আপনার LeetCode notes-এ রাখতে পারবেন।

# Maximum Subarray With Equal Products

**Problem:** [LeetCode - Maximum Subarray With Equal Products](https://leetcode.com/problems/maximum-subarray-with-equal-products/)

## Approach 1: Brute Force

1. Use two nested loops (`i` and `j`) to generate all possible contiguous subarrays.
2. Initialize `prod = 1`, `gcd = 0`, and `lcm = 1` for each starting index.
3. Extend the subarray by moving `j` and update product, GCD, and LCM incrementally.
4. Check whether `prod == gcd * lcm`. If true, update the maximum length.

**TIME COMPLEXITY:** O(n² log M)\
**SPACE COMPLEXITY:** O(1)

## Approach 2: Sliding Window + Last Seen Index

1. Use a Sliding Window with two pointers (`left` and `right`).
2. A subarray of length 3 or more is valid if all its elements are pairwise coprime (GCD of every pair is 1).
3. Since `nums[i] <= 10`, the only possible prime factors are `2, 3, 5, 7`.
4. Maintain a `last` array to track the last index where each prime factor appeared.
5. For every new element, check its prime factors. If a factor has appeared before, update `left` to skip the previous conflicting element.
6. Update the last seen index of each prime factor.
7. Update the maximum window length.

**TIME COMPLEXITY:** O(n)\
**SPACE COMPLEXITY:** O(1)

**Note:** Any subarray of length 2 is valid, even if its two elements are not coprime.

## Approach 3: Optimized Sliding Window (Precomputed Prime Factors)

1. Precompute the prime factors of every possible number (2 to 10) using a lookup table `PRIMES`.
2. Maintain a `last` array to store the last occurrence index of each prime factor (`2, 3, 5, 7`).
3. Use two pointers (`left` and `right`) to maintain the valid sliding window.
4. For each new element, iterate only through its precomputed prime factors.
5. If a prime factor appeared previously, update `left` using `last[p] + 1`.
6. Update the last occurrence index of each prime factor.
7. Update the maximum window length.

**TIME COMPLEXITY:** O(n)  
**SPACE COMPLEXITY:** O(1)

**Optimization:** Instead of checking divisibility against all four prime numbers for every element, directly access its precomputed prime factors using `PRIMES[nums[right]]`.