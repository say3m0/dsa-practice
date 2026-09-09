Problem : [https://leetcode.com/problems/number-of-unequal-triplets-in-array/]

**NUMBER OF UNEQUAL TRIPLETS IN ARRAY**

## 4 Approaches (Ordered by Efficiency) ===>

## *First approach* : Frequency Map / Combinatorics (Most Optimal)

1. Count the frequency of each distinct element using a Hash Map.
2. Maintain `left` (elements processed before current group), `freq` (frequency of current element), and `right` (remaining elements: `n - left - freq`).
3. For each unique element, add `left * freq * right` to the answer and update `left += freq`.
--
--
TIME COMPLEXITY : O(n) average
SPACE COMPLEXITY : O(n) because of map storage

## *Second approach* : Sorting + Grouping (Optimal Space)

1. Sort the array so that identical elements come together in contiguous blocks.
2. Iterate through the array using two pointers `i` and `j` to calculate `freq = j - i` for each group.
3. Calculate `right = n - j`, add `left * freq * right` to the count, update `left += freq`, and set `i = j`.
--
--
TIME COMPLEXITY : O(n log n) due to sorting
SPACE COMPLEXITY : O(1) auxiliary space (or O(log n) depending on sort implementation)

## *Third approach* : Hash Set / Frequency Array (Space-Bounded Alternative)

1. Count the frequencies of array elements using a fixed-size frequency array (since constraints allow value checking).
2. Iterate over non-zero frequency elements in the array.
3. Apply the dynamic formula `left * freq * right` iteratively to calculate valid triplets.
--
--
TIME COMPLEXITY : O(n + K) where K is the range of elements
SPACE COMPLEXITY : O(K) where K is the max element value range

## *Fourth approach* : Brute Force (3 Nested Loops)

1. Iterate over all possible triplets (i, j, k) where `0 <= i < j < k < n`.
2. Check if `nums[i] != nums[j]`, `nums[j] != nums[k]`, and `nums[i] != nums[k]`.
3. Increment the counter whenever all three elements are pairwise distinct.
--
--
TIME COMPLEXITY : O(n^3)
SPACE COMPLEXITY : O(1)

PRECEDENCE: Hash Map / Frequency Multiplication (O(n)) > Sorting + Grouping (O(n log n)) > Fixed Frequency Array (O(n + K)) > Brute Force (O(n^3))