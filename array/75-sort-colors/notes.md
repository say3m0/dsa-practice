Problem : https://leetcode.com/problems/sort-colors/description/Sort 
--
ColorsApproach 1 ===>Optimal Approach : DUTCH NATIONAL FLAG ALGORITHM (3-POINTER TRAVERSAL)--Maintain three pointers: low = 0, mid = 0, and high = n - 1 (where n is v.size()).Run a while(mid <= high) loop to partition the array into three sections:[0 ... low - 1] contains all 0s.[low ... mid - 1] contains all 1s.[high + 1 ... n - 1] contains all 2s.If v[mid] == 0: Swap v[mid] and v[low], then increment both mid++ and low++.If v[mid] == 1: Increment mid++ (since 1 is already in its correct middle region).If v[mid] == 2: Swap v[mid] and v[high], then decrement high-- (do NOT increment mid here, as the newly swapped element at mid needs to be processed).
--
--
WHY MID IS NOT INCREMENTED WHEN SWAPPING WITH HIGH :Swapping with v[high] brings an unexamined element to index mid.We must process this swapped element in the next iteration before moving mid forward.
--
--
TIME COMPLEXITY : $O(N)$ (Single pass)
SPACE COMPLEXITY : $O(1)$ (In-place)
--
--Approach 2 ===>Better Approach : COUNTING SORT (2-PASS TRAVERSAL)--Pass 1: Traverse the array once to count the occurrences of 0s, 1s, and 2s using three variables (count0, count1, count2).Pass 2: Overwrite the original array sequentially:Fill the first count0 positions with 0.Fill the next count1 positions with 1.Fill the remaining count2 positions with 2.
--
--
WHY THIS IS LESS OPTIMAL THAN DNF :Requires two passes over the array instead of a single pass.Modifies array elements by overwriting rather than sorting through swaps.
--
--
TIME COMPLEXITY : $O(N)$ (Two passes)
SPACE COMPLEXITY : $O(1)$
--