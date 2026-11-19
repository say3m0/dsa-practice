# Minimum Score by Changing Two Elements

**Problem:** [Minimum Score by Changing Two Elements](https://leetcode.com/problems/minimum-score-by-changing-two-elements/)

## Approaches

### 1. Sorting + Frequency Checking (My Approach)

**Idea:**

First, sort the array in ascending order.

After sorting:

- `nums[0]` = Minimum element.
- `nums[n-1]` = Maximum element.

Since we can change at most two elements, we need to consider how many occurrences of the minimum and maximum elements exist.

**Key Observations:**

1. If both minimum and maximum occur only once, we have three possible choices:

   - Change the two smallest elements.
   - Change the two largest elements.
   - Change the smallest and largest elements.

2. If the minimum occurs at least twice, changing the two largest elements gives the minimum possible score.

3. If the maximum occurs at least twice, changing the two smallest elements gives the minimum possible score.

4. If both occur at least twice, changing two elements cannot remove either extreme completely. Therefore, the original range remains the minimum possible score.

**Complexity:**

- Time Complexity: (O(n \log n)) — Sorting.
- Space Complexity: (O(1)) — Auxiliary space (ignoring sorting implementation).

### 2. Optimal / Standard Approach (Sorting + Three Cases)

**Idea:**

Instead of counting the frequency of minimum and maximum elements, we can simply consider all possible ways to change two elements.

After sorting the array:

[
nums[0] \le nums[1] \le \dots \le nums[n-1]
]

There are exactly three meaningful possibilities:

**Case 1: Change the two largest elements**

The remaining maximum will be `nums[n-3]`, while the minimum remains `nums[0]`.

[
Score_1 = nums[n-3] - nums[0]
]

**Case 2: Change the smallest and largest elements**

The remaining minimum will be `nums[1]`, while the remaining maximum will be `nums[n-2]`.

[
Score_2 = nums[n-2] - nums[1]
]

**Case 3: Change the two smallest elements**

The remaining minimum will be `nums[2]`, while the maximum remains `nums[n-1]`.

[
Score_3 = nums[n-1] - nums[2]
]

Finally, take the minimum among these three possibilities.

[
\boxed{Answer = \min(Score_1, Score_2, Score_3)}
]

**Complexity:**

- Time Complexity: (O(n \log n)) — Sorting.
- Space Complexity: (O(1)) — Auxiliary space (ignoring sorting implementation).

## Why Does the Standard Approach Work?

After sorting, changing any two elements is equivalent to removing two elements from consideration and replacing them with values that do not increase the final range.

To minimize the range, we only need to consider how many elements are removed from the left and right sides:

- 2 from the left.
- 1 from each side.
- 2 from the right.

Removing elements from the middle cannot produce a better result because the original minimum and maximum would still remain.

Therefore, checking these three cases is sufficient.

|   |
| - |

Both approaches achieve the same time complexity, but the standard approach is simpler and more maintainable.

Whenever a problem allows changing at most two elements to minimize the range, sorting and checking the three possible distributions of changes is a useful technique.
