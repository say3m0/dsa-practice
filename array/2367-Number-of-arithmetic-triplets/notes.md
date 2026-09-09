Problem : https://leetcode.com/problems/number-of-arithmetic-triplets/

**NUMBER OF ARITHMETIC TRIPLETS**

4 Approaches (Ordered by Efficiency) ===>
--
*First approach* : Two Pointers / Three Pointers (Most Optimal)
--
1. Use three pointers (i, j, k) starting from the beginning of the array.
2. Advance 'j' until nums[j] - nums[i] >= diff, and advance 'k' until nums[k] - nums[j] >= diff.
3. If both differences equal 'diff', increment the counter and advance 'i'.
--
--
TIME COMPLEXITY : O(n)
SPACE COMPLEXITY : O(1)

*Second approach* : Hash Set / Hash Map
--
1. Store all elements of the array in a Hash Set or Hash Map for O(1) lookups.
2. Iterate through each element 'x' in the set/map.
3. Check if both (x + diff) and (x + 2 * diff) exist in the set/map; if so, increment the counter.
--
--
TIME COMPLEXITY : O(n) average
SPACE COMPLEXITY : O(n) because of set/map storage

*Third approach* : Binary Search
--
1. Since the array is strictly increasing / sorted, traverse each unique element 'x' in the array.
2. Use Binary Search to check if (x + diff) exists in the array.
3. Use Binary Search again to check if (x + 2 * diff) exists in the array. If both exist, increment the counter.
--
--
TIME COMPLEXITY : O(n log n)
SPACE COMPLEXITY : O(1)

*Fourth approach* : Brute Force (3 Nested Loops)
--
1. Iterate over all possible triplets (i, j, k) using 3 nested loops where i < j < k.
2. Check if nums[j] - nums[i] == diff and nums[k] - nums[j] == diff.
3. If the condition is satisfied, increment the counter.
--
--
TIME COMPLEXITY : O(n^3)
SPACE COMPLEXITY : O(1)