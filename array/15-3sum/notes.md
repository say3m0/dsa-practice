Problem : https://leetcode.com/problems/3sum/

**3SUM**

3 Approaches===>
--
*First approach* : Brute Force 
TC==>O(n^3)
--
--
*Second approach* : HASH MAP
--
1. Sort the array first and fix the first element using an outer loop (i), skipping duplicate values for 'i'.
2. Use an inner loop (j) and a hash set (or map) to find two numbers whose sum equals -(nums[i]), effectively turning it into a 2-Sum problem.
3. If the required target (need) exists in the hash set, add the triplet to the result and skip duplicate values for 'j' before inserting current element into the set. 
--
--
TIME COMPLEXITY : O(n^2)
SPACE COMPLEXITY : O(n) because of set

*Third approach* : Two Pointer
--
1. First loop for traversing all the whole array except last two.
2. Check duplicare for the first loop. If necessary then skip.
3. In second loop, if zero then push and check for duplicates.
4. If deplicates apprear then just skip.
--
--
TIME COMPLEXITY : O(n^2)
SPACE COMPLEXITY : O(1)