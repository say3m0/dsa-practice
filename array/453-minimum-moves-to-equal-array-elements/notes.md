Problem: [Minimum Moves to Equal Array Elements](https://leetcode.com/problems/minimum-moves-to-equal-array-elements)

Approach: Mathematical Observation

Instead of incrementing n-1 elements in each operation, we can think of decrementing one element by 1.

Find the minimum element of the array.

Consider the minimum element as the target value.

Calculate the difference between every element and the minimum element.

Sum all differences to get the minimum number of operations.

Formula:

[
Operations = \sum_{i=0}^{n-1}(nums[i]-minElement)
]

Complexity Analysis:

Time Complexity: (O(n))

Finding the minimum element takes (O(n)).

Calculating the sum of differences takes (O(n)).

Space Complexity: (O(1))

Only a few extra variables are used.