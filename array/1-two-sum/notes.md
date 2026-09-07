Problem : https://leetcode.com/problems/two-sum/?envType=problem-list-v2&envId=array

Solution 0 based on brute force===>
It may needs two nested loop (n^2) which is inefficient






Solution 1 based on Two pointers===>
Step 1 : Store the values with their initial index==>using pair
Step 2 : Sort the original array
Step 3 : Then apply two pointers
Time Complexity : O(nlogn) because of sorting
Space Complexity :O(n)






Solution 2 based on HASH MAP===>
Step 1 : Take a unordered map (this data structure helps to solve this problem without sorting the whole vector).It stores data in key value pair
Step 2 : Find out (target-value of mp one by one)
Step 3 : If Finding value found in unordered map then return there key.
Time Comlpexity : O(n)(no need to sort just storing visited elements)
Space Complexity :O(n)