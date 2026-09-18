**Problem :** [https://leetcode.com/problems/merge-intervals/description/?envType=problem-list-v2&envId=array](https://leetcode.com/problems/merge-intervals/description/?envType=problem-list-v2&envId=array&utm_source=gemini)


**Merge Intervals**
2 Approaches===>
--
**First approach** : SORTING + EXTRA SPACE (RESULT VECTOR)
--
1. Sort all intervals based on their starting times in ascending order.
2. Initialize an empty list to store the merged intervals and add the first interval into it.
3. Iterate through the remaining intervals one by one from left to right.
4. Compare the start time of the current interval with the end time of the last added interval in the result list.
5. If the current start time is less than or equal to the last end time, merge them by updating the last end time to the maximum of both end times.
6. If they do not overlap, push the current interval as a new entry into the result list.
--
--
**TIME COMPLEXITY : O(n log n)**
**SPACE COMPLEXITY : O(n)**
--
--
**Second approach** : SORTING + IN-PLACE OPTIMIZATION
--
1. Sort all intervals based on their starting times in ascending order.
2. Maintain an index pointer `k = 0` representing the position of the last merged interval directly inside the input array.
3. Iterate through the array starting from the second interval (`i = 1`).
4. If the current interval overlaps with the interval at index `k`, update the end time at index `k` to the maximum of both end times.
5. If they do not overlap, increment `k` and copy the current interval's start and end values directly to index `k`.
6. Resize the original array to `k + 1` elements to discard the redundant remaining elements.
--
--
**TIME COMPLEXITY : O(n log n)**
**SPACE COMPLEXITY : O(1)**